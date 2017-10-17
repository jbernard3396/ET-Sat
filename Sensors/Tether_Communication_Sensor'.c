//
// Created by caleb on 10/5/2017.
//

#include "Tether_Communication_Sensor'.h"
#include <limits.h>

unsigned short getWireTension(void){
        //Reads Wire tension some how from Tether sensor port
        int wireTension = -1; //will be port Name / DDR location
        //We are mapping errors to 0, so if the reading is 0, we must return 1.
        if (wireTension == 0) wireTension = 1;
        if (wireTension <0) wireTension = 0;
        if (wireTension > USHRT_MAX){ //Makes sure it is not bigger than it is supposed to
            wireTension = 0;
        }

        unsigned short wireTensionValue  = (unsigned short)wireTension;
    return wireTensionValue;
}