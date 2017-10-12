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
        SCM_Set_Current_Mode(&TUS,recievedMessage);
        SCM_Run_Current_Mode(TUS);
        SCM_TUS_Set_New_Mode(); //Select a new mode to send to PGS
//        send_Message_wait_for_ack(TUS.currentMode); //<--Send a message to PGS and wait for ack
}

int main(void)
{
    unsigned short light = Get_Ambient_Light();
    unsigned short emField =getEMField();
    short rotationX = getRotationX();

    short rotationY = getRotationY();

    short rotationZ = getRotationZ();

    if (light == 0){  //Testing Ambient Light
        printf("%s","There was an error in getting the ambient light \n");
    } else{
        printf("Ambient light= %o\n", light);
    }
    if (emField == 0){  //Testing Ambient Light
        printf("%s","There was an error in getting the ElectroMagnetic Field \n");
    } else{
        printf("ElectroMagnetic Field = %o\n", emField);
    }

    if (rotationX == 0){  // Testing Rotation X
        printf("%s","There was an error in getting rotation Y \n");
    } else{
        printf("Rotation X= %d\n", rotationX);
    }
    if (rotationY == 0){  //Testing Rotation Y
        printf("There was an error in getting rotation Z \n");
    } else{
        printf("Rotation Y= %d\n", rotationY);
    }

    if (rotationZ == 0){  //Testing Rotation Z
        printf("%s","There was an error in getting rotation Z \n");
    } else{
        printf("Rotation Z= %d\n", rotationZ);
    }


    unsigned short wireStrain = wireTension();
    if (wireStrain == 0){  // Getting Tether Tension
        printf("%s","There was an error in getting the Tether Tension \n");
    } else{
        printf("Tether Tension= %o\n", wireStrain);
    }
    satellite_test();

    return 0;
}

