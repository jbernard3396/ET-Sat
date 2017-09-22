//
// Created by jbernard on 9/14/17.
//

#include "Health_And_Safety.h"

/**
 * Checks status of battery.
 * Written by Ryan Jones
 * @return value telling what battery life range is
 */
int check_Battery_Life(){
    double bLife = satBatteryStatus();
    if(bLife < .10) {
        return 0;
    } else if (bLife > 0.10) {
        return 1;
    }
}

int check_PGConnection(){ //Ryan

}

int check_Position(){ //David

}

int check_Hard_Ware(){ //Jake
    //This is Jakes code
}

int check_For_Alien_Virus(){
    int tooManyViruses = 8;
    int virusStatus = getVirusStatusFromVirusSensor(1);
    if (virusStatus >= tooManyViruses) {
        throw_Error();
        return -1;
    }
    return 1;
}

void throw_Error(){
    printf("error\n");
}

void run_Health_And_Safety_Check() {
    check_Battery_Life();
    check_PGConnection();
    check_Position();
    check_Hard_Ware();
    check_For_Alien_Virus();
    printf("Healthy and Safe");
}