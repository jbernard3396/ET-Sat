/*
 * Written by: Justin Theien
 * Date: 9/12/2017
 * Description: This program is designed to send data from one satellite to another, using Near Infrared (NIR). I am writing my own protocol based on the research that I have already completed
 *              This code will treat the output signal as either "on", or "off" (the modulation/filtering of the signal is assumed to be done in hardware). I have modified this
 *              file to send only single bits of data at one pulse. I had spoken with a programmer at PhyxtGears who had brought the idea to mind. He had mentioned it would be more efficient to send
 *              bits at a time, instead of hex values.
 *
 * *NOTE* The IR LED and the interrupt pin are going to be defined in the IO.h file. if for any reasons the pin output/intput needs to be changed, please refer to that file
 */

 //The pin assignments are as follows:
 //Interrupt/receiver pin = PD1
 //transmitter pin = PD0

#include "IR_Protocol_sendBits.h"
//Global variables available to IR_Protocol.c
static SysTimer_t IR_Transmitter_Timer;
static SysTimer_t IR_Receiver_Timer;
static SysTimer_t IR_Timeout_Timer;

static volatile char incomingData[16];
static volatile Bool preambleSuccessful = FALSE;
static volatile Bool messageExecuted = TRUE;
static Bool timerStarted = FALSE;
static int messageStatus = NO_NEW_MESSAGE;
static volatile char totalBits;
static int ackWaitTime;
static volatile int k;
static Bool sendAck = TRUE;


//::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::
int getAckWaitTime(void){
    unsigned int data;
    char currentBit;
    int ackTransmissionLength = 0;

    data = RECEIVE_SUCCESSFUL;
    while(data != 0){
        currentBit = data & 0b01;
        ackTransmissionLength += get_bit_value_length(currentBit);
        data = data >> 1;
    }
    ackTransmissionLength += preamble_Length;
    ackTransmissionLength += end_Transmission_Length;
    ackTransmissionLength += END_OF_MESSAGE_BUFFER;

    return ackTransmissionLength;
}

//::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::
void IR_Communication_System_Init(SysTmr_GetTicksFunc_hook_t getticks_func){
//----------------------------------------------------------
/*This will set up the timer that the satellite will wait for an acknowledgment before trying again
  We are going to wait the length that it should take to send the ack message before checking to see if
  the message was received... the ackWaitTime variable will be used.
*/
    ackWaitTime = getAckWaitTime();
//----------------------------------------------------------
/*This portion is going to be used to initialize LEDs that will be used for debugging*/
    DDRB |= (1 << PORTB3);
    PORTB &= ~(1<<PORTB3);
//----------------------------------------------------------

    cli();
    //IR_getData = getByteOfData;
    systmr_Init(&IR_Transmitter_Timer,getticks_func);
    systmr_Init(&IR_Receiver_Timer,getticks_func);
    systmr_Init(&IR_Timeout_Timer,getticks_func);

    //enable external interrupt pin for the receiver
    DDRD &= ~(1 << DDD1);     // Clear the PD1 pin
    PORTD |= (1 << PORTD1);    // turn On the Pull-up

    DDRD &= ~(1 << DDD0);     // Clear the PD1 pin
    PORTD |= (1 << PORTD0);    // turn On the Pull-up

    EICRA |= (1 << ISC10);    // set INT1 to trigger on ANY logic change
    EIMSK |= (1 << INT1);     // Turns on INT1
    sei();

}

//::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::
void disable_IR_Interrupt(void){
    cli();
    EIMSK &= ~(1 << INT1);     // Turns off INT1
    sei();
}

//::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::
void enable_IR_Interrupt(void){
    cli();
    DDRD &= ~(1 << DDD1);     // Clear the PD2 pin
    EIMSK |= (1 << INT1);     // Turns on INT1
    reset_IR_Interrupt();
    sei();
}

//::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::
Bool isMessageExecuted(void){
    return messageExecuted;
}

//::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::
void setMessageAsExecuted(void){
    messageExecuted = TRUE;
}

//::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::
void setTotalBitsReceived(char value){
	totalBits = value;
}

//::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::
char getTotalNumOfBitsReceived(void){
	return totalBits;
}

//::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::
int get_bit_value_length(Bool value){
    if(value){
        return bit_value_high;
    }
    else{
        return bit_value_low;
    }
}

//::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::
Bool isWithinErrorMargin(char temp, char bit_value){ //returns whtether the time received can be translated into a bit value
	 if((temp > (bit_value - ERROR_MARGIN)) && (temp < (bit_value + ERROR_MARGIN))){
		 return TRUE;
	 }
	 else{
		 return FALSE;
	 }
}

//::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::
char get_Bit_Value_From_Length(char length){
    char newData;

    if( isWithinErrorMargin(length,bit_value_low) ){
        newData = 0;
    }
    else if( isWithinErrorMargin(length,bit_value_high) ){
        newData = 1;
    }
    else{ //if we have no idea what the data received is
        newData = ERROR;
    }

    return newData;
}

//::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::
void send_Message(int data){
    //******Note****** this send_message assumes that no unsigned values are sent. This is because we are >> the data, and assuming that the bits added on the left hand side are all '0'

    disable_IR_Interrupt();
    //Create the packet that contains the information that we are going to be sending
    Data_Packet message;

    //assign the correct values to their placeholder
    message.preamble = preamble_Length;
    message.end_Transmission = end_Transmission_Length;
    message.delay = intermittent_Delay_Length;

    //Finally, since the message is assembled, transmit the message through the IR Emitter
    //Send the preamble
	systmr_Load(&IR_Transmitter_Timer);
    IR_LED_ON();
    while(!systmr_Elapsed(&IR_Transmitter_Timer, message.preamble/2, SYSTMR_RELOAD));

    IR_LED_OFF();
    while(!systmr_Elapsed(&IR_Transmitter_Timer, message.delay/2, SYSTMR_RELOAD));
//---------------------------------------------------------------------------------------------
    //Send data
    char currentBit;
    char bitTransmissionLength;

        while(data != 0){
            currentBit = data & 0b1;
            data = data >> 1;
            bitTransmissionLength = get_bit_value_length(currentBit);

            IR_LED_ON();
            while(!systmr_Elapsed(&IR_Transmitter_Timer, bitTransmissionLength/2, SYSTMR_RELOAD));

            IR_LED_OFF();
            while(!systmr_Elapsed(&IR_Transmitter_Timer, message.delay/2, SYSTMR_RELOAD));
        }

//---------------------------------------------------------------------------------------------
        //Send end_Transmission
    IR_LED_ON();
    while(!systmr_Elapsed(&IR_Transmitter_Timer, message.end_Transmission/2, SYSTMR_RELOAD));

    IR_LED_OFF();
    while(!systmr_Elapsed(&IR_Transmitter_Timer, END_OF_MESSAGE_BUFFER/2, SYSTMR_RELOAD)); //Padding that will be used as a buffer

    enable_IR_Interrupt();
    reset_IR_Interrupt();
}

//::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::
Bool send_Message_wait_for_ack(int data){
    char i;
    int ack;
    Bool isSuccessfullySent = FALSE;

    sendAck = FALSE;

    for(i = 0; i < NUMBER_OF_ATTEMPTS; i++){
        if(!isSuccessfullySent){
            send_Message(data);
            delay_ms(ackWaitTime+ISR_TIMEOUT_AMOUNT);
        }

        ack = IR_checkForNewMessage();

        if(ack == RECEIVE_SUCCESSFUL){
            PORTB ^= (1 << PORTB1);
            i = NUMBER_OF_ATTEMPTS; //If we have received the ack, then we can exit the for loop
            isSuccessfullySent = TRUE;
        }
    }

    sendAck = TRUE;
    return isSuccessfullySent;

}

//::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::
int assembleMessage(){
		char total,temp;
		int j;
		int final_data = 0b00000000;
		total = getTotalNumOfBitsReceived();


        for(j = 0; j < total; j++){
            temp = incomingData[j];

            if(temp == 1 || temp == 0){
                final_data |= (temp << j);

            }
            else{
                final_data = ERROR;
                j = total;
            }
        }

        setMessageAsExecuted(); //Now that we have dealt with our data, we do not have a new message anymore

        return final_data;

}

//::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::
int last_received_message(void){
    return messageStatus;
}

//::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::
void reset_IR_Interrupt(void){
    timerStarted = FALSE;
    preambleSuccessful = FALSE;
    PORTB &= ~(1 << PORTB3);
}

//::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::
Bool is_ISR_timed_out(void){ //used to make sure that the ISR is functioning properly

    if(systmr_Elapsed(&IR_Timeout_Timer, (ISR_TIMEOUT_AMOUNT/2), SYSTMR_DO_NOT_RELOAD)){ //this is just testing if the message sending works properly
        reset_IR_Interrupt();
        return TRUE;
    }

    return FALSE;

}

//::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::
int IR_checkForNewMessage(void){
    int receivedMessage;

    while(!is_ISR_timed_out()){
        //do nothing because we are in the middle of receiving a message
		//If there is an incoming message, then we are going to want to assemble it.

    }

    if(!isMessageExecuted()){
        receivedMessage = assembleMessage();
        if(receivedMessage != RECEIVE_SUCCESSFUL){
            messageStatus = receivedMessage;
        }
    }
    else{
        receivedMessage = NO_NEW_MESSAGE;
    }

    return receivedMessage;

}

//::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::
void send_Acknowledgement(void){
    send_Message(RECEIVE_SUCCESSFUL);
}

//::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::
void setData(int position, char data){
    incomingData[position] = data;
}

//::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::
ISR(INT1_vect) { //what happens when we receive an IR signal from the other satellite. This interupt will only store the data that it received. What happens to the data will be decided in main()
    PORTB ^= (1 << PORTB3);
    static SysTicks_t elapsedTime;

    if( !timerStarted){
        systmr_Load(&IR_Receiver_Timer); //start the timer
        timerStarted = TRUE;
        systmr_Load(&IR_Timeout_Timer);
    }

    else{

        //Stop the timer and decypher the data
        elapsedTime = systmr_Time(&IR_Receiver_Timer);
        elapsedTime = 2 * elapsedTime; //we have to multiply by two since systmr_Time returns amount of ticks, and each tick = 2 ms (not one)

        //Now we decide what to do with the data...
		if( isWithinErrorMargin(elapsedTime,bit_value_low) ){
            k++;
			setData(k-1,0);

		}
		else if( isWithinErrorMargin(elapsedTime,bit_value_high) ){
		    k++;
			setData(k-1,1);

		}

        else if( isWithinErrorMargin(elapsedTime,preamble_Length) ){
			//setTotalBitsReceived(0); //reset the counter
            preambleSuccessful = TRUE;
            k = 0;
        }

        else if( isWithinErrorMargin(elapsedTime, end_Transmission_Length) ){
            PORTB &= ~(1 << PORTB3);
            messageExecuted = FALSE;
			setTotalBitsReceived(k);
            if(preambleSuccessful){ //If this satellite received both the preamble and the end_transmission successfully, then it is safe to assume that the data was a success
                delay_ms(50);
                if(sendAck == TRUE){
                    send_Acknowledgement();
                }
            }
        }
        timerStarted = FALSE; //so we will start the timer the next time the interrupt is triggered
    }

}
