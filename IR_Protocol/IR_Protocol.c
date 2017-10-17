/*
 * Written by: Justin Theien
 * Date: 6/12/2017
 * Description: This program is designed to send data from one satellite to another, using IR. I am writing my own protocol based on the research that I have already completed
 *              This code will treat the output signal as either "on", or "off" (the modulation of the signal is assumed to be done in hardware).
 *
 * *NOTE* The IR LED and the interrupt pin are going to be defined in the IO.h file. if for any reasons the pin output/intput needs to be changed, please refer to that file
 */

#include "IR_Protocol.h"
//Global variables available to IR_Protocol.c
static SysTimer_t IR_Transmitter_Timer;
static SysTimer_t IR_Receiver_Timer;
static SysTimer_t IR_Timeout_Timer;

static volatile SysTicks_t high_hex_value = 0;//hex_Value_0_Length;
static volatile SysTicks_t low_hex_value = 100;//hex_Value_8_Length;
static volatile Bool preambleSuccessful = FALSE;
static volatile Bool messageExecuted = TRUE;
static Bool timerStarted = FALSE;
static char messageStatus = NO_NEW_MESSAGE;
static int ackWaitTime;

void IR_Communication_System_Init(SysTmr_GetTicksFunc_hook_t getticks_func){
//----------------------------------------------------------
/*This will set up the timer that the satellite will wait for an acknowledgment before trying again
  We are going to wait the length that it should take to send the message before checking to see if
  the message we received is the correct one...
*/
    char temp1, temp2 = 0;
    temp1 = (RECEIVE_SUCCESSFUL & 0b1111);
    temp2 = (RECEIVE_SUCCESSFUL >> 4) & 0b1111;
    ackWaitTime = (get_Hex_Value_Length(temp1) + get_Hex_Value_Length(temp2)) + 10; //we add 10 ms for a cushion
//----------------------------------------------------------
/*This portion is going to be used to initialize LEDs that will be used for debugging*/
    DDRB |= (1 << PORTB5);
    PORTB &= ~(1<<PORTB5);
//----------------------------------------------------------

    cli();
    //IR_getData = getByteOfData;
    systmr_Init(&IR_Transmitter_Timer,getticks_func);
    systmr_Init(&IR_Receiver_Timer,getticks_func);
    systmr_Init(&IR_Timeout_Timer,getticks_func);

    //enable external interrupt pin for the receiver
    DDRD &= ~(1 << DDD1);     // Clear the PD1 pin
    PORTD |= (1 << PORTD1);    // turn On the Pull-up

    EICRA |= (1 << ISC10);    // set INT0 to trigger on ANY logic change
    EIMSK |= (1 << INT1);     // Turns on INT0
    sei();

}

void disable_IR_Interrupt(void){
    EIMSK &= ~(1 << INT1);     // Turns off INT0
}

void enable_IR_Interrupt(void){
    DDRD &= ~(1 << DDD1);     // Clear the PD2 pin
    EIMSK |= (1 << INT1);     // Turns on INT0
    reset_IR_Interrupt();
}
Bool isMessageExecuted(void){
    return messageExecuted;
}
void setMessageAsExecuted(void){
    messageExecuted = TRUE;
}

Communication_Value get_Hex_Value_Length(char data){
    //NOTE - this function should only handle 4 bit chunks of data
    data = data & 0b1111;

    Communication_Value newData;

    switch(data){
        case 0:
            newData = hex_Value_0_Length;
            break;
        case 1:
            newData = hex_Value_1_Length;
            break;
        case 2:
            newData = hex_Value_2_Length;
            break;
        case 3:
            newData = hex_Value_3_Length;
            break;
        case 4:
            newData = hex_Value_4_Length;
            break;
        case 5:
            newData = hex_Value_5_Length;
            break;
        case 6:
            newData = hex_Value_6_Length;
            break;
        case 7:
            newData = hex_Value_7_Length;
            break;
        case 8:
            newData = hex_Value_8_Length;
            break;
        case 9:
            newData = hex_Value_9_Length;
            break;
        case 10:
            newData = hex_Value_a_Length;
            break;
        case 11:
            newData = hex_Value_b_Length;
            break;
        case 12:
            newData = hex_Value_c_Length;
            break;
        case 13:
            newData = hex_Value_d_Length;
            break;
        case 14:
            newData = hex_Value_e_Length;
            break;
        case 15:
            newData = hex_Value_f_Length;
            break;
        default:
            //if none of the other values were able to catch, then there is a problem
            newData = error_transmission_Length;
            break;
    }
    return newData;
}

char get_Data_Value_From_Length(int length){
    char newData;

    if( (length > (hex_Value_0_Length - ERROR_MARGIN)) && (length < (hex_Value_0_Length + ERROR_MARGIN)) ){
        newData = 0;
    }
    else if((length > (hex_Value_1_Length - ERROR_MARGIN)) && (length < (hex_Value_1_Length + ERROR_MARGIN)) ){
        newData = 1;
    }
    else if((length > (hex_Value_2_Length - ERROR_MARGIN)) && (length < (hex_Value_2_Length + ERROR_MARGIN)) ){
        newData = 2;
    }
    else if((length > (hex_Value_3_Length - ERROR_MARGIN)) && (length < (hex_Value_3_Length + ERROR_MARGIN)) ){
        newData = 3;
    }
    else if((length > (hex_Value_4_Length - ERROR_MARGIN)) && (length < (hex_Value_4_Length + ERROR_MARGIN)) ){
        newData = 4;
    }
    else if((length > (hex_Value_5_Length - ERROR_MARGIN)) && (length < (hex_Value_5_Length + ERROR_MARGIN)) ){
        newData = 5;
    }
    else if((length > (hex_Value_6_Length - ERROR_MARGIN)) && (length < (hex_Value_6_Length + ERROR_MARGIN)) ){
        newData = 6;
    }
    else if((length > (hex_Value_7_Length - ERROR_MARGIN)) && (length < (hex_Value_7_Length + ERROR_MARGIN)) ){
        newData = 7;
    }
    else if((length > (hex_Value_8_Length - ERROR_MARGIN)) && (length < (hex_Value_8_Length + ERROR_MARGIN)) ){
        newData = 8;
    }
    else if((length > (hex_Value_9_Length - ERROR_MARGIN)) && (length < (hex_Value_9_Length + ERROR_MARGIN)) ){
        newData = 9;
    }
    else if((length > (hex_Value_a_Length - ERROR_MARGIN)) && (length < (hex_Value_a_Length + ERROR_MARGIN)) ){
        newData = 10;
    }
    else if((length > (hex_Value_b_Length - ERROR_MARGIN)) && (length < (hex_Value_b_Length + ERROR_MARGIN)) ){
        newData = 11;
    }
    else if((length > (hex_Value_c_Length - ERROR_MARGIN)) && (length < (hex_Value_c_Length + ERROR_MARGIN)) ){
        newData = 12;
    }
    else if((length > (hex_Value_d_Length - ERROR_MARGIN)) && (length < (hex_Value_d_Length + ERROR_MARGIN)) ){
        newData = 13;
    }
    else if((length > (hex_Value_e_Length - ERROR_MARGIN)) && (length < (hex_Value_e_Length + ERROR_MARGIN)) ){
        newData = 14;
    }
    else if((length > (hex_Value_f_Length - ERROR_MARGIN)) && (length < (hex_Value_f_Length + ERROR_MARGIN)) ){
        newData = 15;
    }

    else{ //if we have no idea what the data received is
        newData = ERROR;
    }
    return newData;
}

void send_Message(char data){
    disable_IR_Interrupt();
    //Create the packet that contains the information that we are going to be sending
    Data_Packet message;

    //assemble the packet that we are going to send (assign the length of time for each place holder)
    char dataPoint1 = data & 0b1111;
    char dataPoint2 = (data >> 4);

    //assign the correct values to their placeholder
    message.preamble = preamble_Length;
    message.data_1 = get_Hex_Value_Length(dataPoint1);
    message.data_2 = get_Hex_Value_Length(dataPoint2);
    message.end_Transmission = end_Transmission_Length;
    message.delay = intermittent_Delay_Length;

    //Finally, since the message is assembled, transmit the message through the IR Emitter
    //Send the preamble
        IR_LED_ON();
        systmr_Load(&IR_Transmitter_Timer);
        while(!systmr_Elapsed(&IR_Transmitter_Timer, message.preamble/2, SYSTMR_RELOAD));

        IR_LED_OFF();
        while(!systmr_Elapsed(&IR_Transmitter_Timer, message.delay/2, SYSTMR_RELOAD));

        //Send data2
        IR_LED_ON();
        while(!systmr_Elapsed(&IR_Transmitter_Timer, message.data_2/2, SYSTMR_RELOAD));

        IR_LED_OFF();
        while(!systmr_Elapsed(&IR_Transmitter_Timer, message.delay/2, SYSTMR_RELOAD));

        //Send data1
        IR_LED_ON();
        while(!systmr_Elapsed(&IR_Transmitter_Timer, message.data_1/2, SYSTMR_RELOAD));

        IR_LED_OFF();
        while(!systmr_Elapsed(&IR_Transmitter_Timer, message.delay/2, SYSTMR_RELOAD));

        //Send end_Transmission
        IR_LED_ON();
        while(!systmr_Elapsed(&IR_Transmitter_Timer, message.end_Transmission/2, SYSTMR_RELOAD));

        IR_LED_OFF();
        while(!systmr_Elapsed(&IR_Transmitter_Timer, 50/2, SYSTMR_RELOAD));
    enable_IR_Interrupt();
}

Bool send_Message_wait_for_ack(char data){
    char i;
    char ack;
    Bool successfullySent = FALSE;

    for(i = 0; i < NUMBER_OF_ATTEMPTS; i++){
        send_Message(data);
        delay_ms(ackWaitTime);
        ack = IR_checkForNewMessage();

        if(ack == RECEIVE_SUCCESSFUL){
            i = NUMBER_OF_ATTEMPTS; //If we have received the ack, then we can exit the for loop
            successfullySent = TRUE;
        }
    }

    return successfullySent;

}

char assembleMessage(void){
        SysTicks_t high_value = high_hex_value;
        SysTicks_t low_value = low_hex_value;

        unsigned char final_data = 0;
        unsigned char high_temp;
        unsigned char low_temp;

        high_temp = get_Data_Value_From_Length(high_value);
        low_temp = get_Data_Value_From_Length(low_value);

        if(high_temp == ERROR || low_temp == ERROR){
            return ERROR;
        }

        final_data = (high_temp << 4) | low_temp;

        setMessageAsExecuted();

        messageStatus = final_data;

        return final_data;

}

char last_received_message(void){
    return messageStatus;
}

void reset_IR_Interrupt(void){
    timerStarted = FALSE;
    preambleSuccessful = FALSE;
    PORTB &= ~(1 << PORTB5);
}

Bool is_ISR_timed_out(void){ //used to make sure that the ISR is functioning properly

    if(systmr_Elapsed(&IR_Timeout_Timer, (ISR_TIMEOUT_AMOUNT/2), SYSTMR_DO_NOT_RELOAD)){ //this is just testing if the message sending works properly
        reset_IR_Interrupt();
        return TRUE;
    }

    return FALSE;

}

char IR_checkForNewMessage(void){
    char receivedMessage;

    while(!is_ISR_timed_out()){
        //do nothing because we are in the middle of receiving a message
    }
    //If there is an incoming message, then we are going to want to assemble it.
    if(!isMessageExecuted()){
        receivedMessage = assembleMessage();
    }
    else{
        receivedMessage = NO_NEW_MESSAGE;
    }

    return receivedMessage;

}

void send_Acknowledgement(void){
    send_Message(RECEIVE_SUCCESSFUL);
}


ISR(INT1_vect) { //what happens when we receive an IR signal from the other satellite. This interupt will only store the data that it received. What happens to the data will be decided in main()
    PORTB ^= (1 << PORTB5);
    static SysTicks_t elapsedTime;
    static Bool waiting_to_receive_data1 = FALSE;
    static Bool waiting_to_receive_data2 = FALSE;

    if( !timerStarted ){
        systmr_Load(&IR_Receiver_Timer); //start the timer
        timerStarted = TRUE;
        if(waiting_to_receive_data2 == FALSE && waiting_to_receive_data1 == FALSE){ //THis statement is true right after the timer has been started
            systmr_Load(&IR_Timeout_Timer);
        }
    }

    else{

        //useful interrupt code starts here
        elapsedTime = systmr_Time(&IR_Receiver_Timer); //we have to multiply by two since systmr_Time returns amount of ticks, and each tick = 2 ms (not one)
        elapsedTime = 2 * elapsedTime;

        //Now we decide what to do with the data...
        if(waiting_to_receive_data2){
            high_hex_value = elapsedTime;
            waiting_to_receive_data2 = FALSE;
            waiting_to_receive_data1 = TRUE;
        }

        else if(waiting_to_receive_data1){
            low_hex_value = elapsedTime;
            waiting_to_receive_data2 = FALSE;
            waiting_to_receive_data1 = FALSE;
        }
        else if(elapsedTime > (preamble_Length - ERROR_MARGIN) && elapsedTime < (preamble_Length + ERROR_MARGIN) && waiting_to_receive_data2 == FALSE &&  waiting_to_receive_data1 == FALSE){
            waiting_to_receive_data2 = TRUE; //data 2 is the high bit, and the high bit is sent first
            waiting_to_receive_data1 = FALSE;
            preambleSuccessful = TRUE;
        }

        else if(elapsedTime > (end_Transmission_Length - ERROR_MARGIN) && elapsedTime < (end_Transmission_Length + ERROR_MARGIN)){
            messageExecuted = FALSE;

            if(preambleSuccessful){ //If this satellite received both the preamble and the end_transmission successfully, then it is safe to assume that the data was a success
                send_Acknowledgement();
            }
        }

        timerStarted = FALSE;
    }

}
