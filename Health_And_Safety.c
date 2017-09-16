//
// Created by jbernard on 9/14/17.
//

#include "Health_And_Safety.h"

int check_Battery_Life(){

}

int check_PGConnection(){

}

int check_Position(){

}

int check_Hard_Ware(){

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
    printf("error");
}

void run_Health_And_Safety_Check() {
    check_Battery_Life();
    check_PGConnection();
    check_Position();
    check_Hard_Ware();
    check_For_Alien_Virus();
    printf("Healthy and Safe");
}