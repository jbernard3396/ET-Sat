//
// Created by caleb on 10/3/2017.
//

#include "Light_Sensor.h"
#include "limits.h"

unsigned short Get_Ambient_Light() {
    //Reads ambient light input from port Light_Sensor is on
    int lightReading = 8; //will be port Name / DDR location
    //We are mapping errors to 0, so if the reading is 0, we must return 1.
    if (lightReading == 0) lightReading = 1;
    //Else if there is an error, (No Idea how to check), lightReading returns 0;
    if (lightReading <0) lightReading = 0;
    if (lightReading > USHRT_MAX){ //Makes sure it is not bigger than it is supposed to
        lightReading = 0;
    }

     unsigned short lightValue = (unsigned short)lightReading;
    return lightValue;
}
