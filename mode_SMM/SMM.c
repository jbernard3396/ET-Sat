/*
 * Written by: Eliza You and Justin Theien
 * Date: 6/26/2017
 *
 * Description: Science Measurement Mode is the first mode TUS enters from Spacecraft Control Mode. SMM is responsible for measuring
 *              peripheral data, such as plasma, light, and temperature. SMM is a low power mission.
 *
 */

 #include "SMM.h"

//Static Global Variables-----------------------------------------------------------------------------------------------------


//Functions-------------------------------------------------------------------------------------------------------------------


void measure_plasma(void) {
    //power_on(/*plasma probe*/) ;
    //collect and measure plasma
    //power_off(/*plasma probe*/);
    printf("init measure_plasma() ");
}

void measure_light(void) {              //are we measuring light intensity or presence?
    //power_on(/*light sensor*/);
    //collect and measure light
    //power_off(/*light sensor*/);
    printf("init measure_light() ");
}

void run_smm(void) {
    measure_plasma();
    measure_light();
    printf("SMM is running\n\n");
}
