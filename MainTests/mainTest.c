/*
 * Thin-Sat Test Code
 * Creator: Caleb Anthony
 * Date: 10/3/2017
 *
 * Team members: Jake Masters, Caleb Anthony
 *
 * This A dummy/sudo main to run tests on sensor calling and mode cycling.
 */

#include "mainTest.h"


#define RUN_TUS TRUE //<---------------------------------------------------------Pick which satellite

//Gloabal variables
static char recievedMessage = NO_NEW_MESSAGE;

//Testing Main
void satellite_test(void){
        //Change modes according to the message received (if any), and execute that mode.
//        SCM_Set_Current_Mode(&TUS,recievedMessage);
//        SCM_Run_Current_Mode(TUS);
//        SCM_TUS_Set_New_Mode(); //Select a new mode to send to PGS
//        send_Message_wait_for_ack(TUS.currentMode); //<--Send a message to PGS and wait for ack
}

int main(void)
{

    sendScienceMeasurements();

    return 0;
}

