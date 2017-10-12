/*
 * Written by: Eliza You and Justin Theien
 * Date: 6/23/2017
 *
 * Description: Launch Vehicle Separation Mode is the first mode the TU spacecraft enters after being launched. It marks the beginning of Commissioning Phase.
 *              LVSM is responsible for powering on T-OBC and initializing TUS operation to enter into Mission Phase.
 *
 */

#include "LVSM.h"

//Static Global Variables-----------------------------------------------------------------------------------------------------


//Functions-------------------------------------------------------------------------------------------------------------------
void obc_post(void) {

}

Bool power_on( void ) {
    //switch parts on
    //if part not on immediately, try 3x
    int x = 1;
    printf("init power_on ");
    if (x == 1 ) {
        return TRUE;
    } else {
        return FALSE;
    }

}

void imu_post(void) {
    /*if ( power_on(void) = TRUE ){            //NOT YET DEFINED
        //calibrate imu
        return;
    }*/
    printf("init imu_post ");
    return;

}

void run_lvsm (void) {
    //obc on and ok
    //power level
    //attitude
    //wait for some time here...tbd by nsl
    //imu_post(void);     //imu calibrated
    //enable_IR_interrupt(void);
    //data sent to simplex
    //NOTE: RUN HEALTH AND SAFETY ONLY AFTER LVSM OP DONE
    power_on();
    imu_post();
    printf("LVSM is running\n\n");
}
