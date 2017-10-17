//
// Created by caleb on 10/5/2017.
//

#include "Em_Sensor.h"
#include <limits.h>
#include <stdio.h>

unsigned short getEmField(){
    //Reads Electro Magnetic Field input from port Em_Sensor is on
    int emReading = 56; //will be port Name / DDR location
    //We are mapping errors to 0, so if the reading is 0, we must return 1.
    if (emReading == 0) emReading = 1;
    //Else if there is an error, (No Idea how to check), emeading returns 0;
    if (emReading <0) emReading = 0; // Ifsmaller/ not unsigned
    if (emReading > USHRT_MAX){ //Makes sure it is not bigger than it is supposed to
        emReading = 0;
    }

    unsigned short emValue = (unsigned short)emReading;
    return emValue;
}