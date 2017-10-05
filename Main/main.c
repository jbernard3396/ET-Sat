/*
 * Thin-Sat Embedded Code
 * Creator: Justin Theien
 * Date: 6/9/2017
 *
 * Team members: Justin Theien, Chester Chan, Austin Wolgemuth, Eliza You, Moriah S.
 *
 * *NOTE* in order to make sure that the timers function properly, we need to make sure that the efuse is set to 0xe2 (for the atmega328p)
 *        This can be accomplished through the avrdude terminal (located within tools on C::B on my machine)
 *
 *
 */

#include "main.h"


#define RUN_TUS TRUE //<---------------------------------------------------------Pick which satellite

//Gloabal variables
static char recievedMessage = NO_NEW_MESSAGE;

//I will write the code for each satellite here
void run_TUS_main(void) {
    //Both satellites will Check For a new IR message
//        recievedMessage = IR_checkForNewMessage();

    //Change modes according to the message received (if any), and execute that mode.
    //SCM_Set_Current_Mode(&TUS, recievedMessage);
    //SCM_Init();
    SCM_Run_Current_Mode(TUS);
    //SCM_TUS_Set_New_Mode(); //Select a new mode to send to PGS
//        send_Message_wait_for_ack(TUS.currentMode); //<--Send a message to PGS and wait for ack
}

int main(void) {
    //Setup starts here!
    //---------------------------------------------------------------------------------------------------------------------------------------------------------
    // initialize the system
//    tmr0_Init(); //This is used for IR communication
//    tmr3_Init(); //This is used as the systmr
//    SCM_Init();
//    IR_Communication_System_Init(tmr3_Get2msTicks_u16);


    //This following is just a setup for timer. This is not currently used, and therefore it is commented out
//    SysTimer_t timer1; //Declares an instance of a new timer
//    systmr_Init(&timer1, tmr3_Get2msTicks_u16); //We are using 16 bits, so that the timer may count to a higher value
//    systmr_Load(&timer1); //Load the timer before starting. This is used as a referenece point.

    //---------------------------------------------------------------------------------------------------------------------------------------------------------
    SCM_Init();
    while (1) {
//        if(RUN_TUS){
//            if(systmr_Elapsed(&timer1, (10000/2), SYSTMR_RELOAD)){ //this is just testing if the message sending works properly
        run_TUS_main();

//        printf("Run" + i++);
//            }
//        }
//        else{
//            run_PGS_main();
//        }
    }
    //---------------------------------------------------------------------------------------------------------------------------------------------------------

    return 0;
}

