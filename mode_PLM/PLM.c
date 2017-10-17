/*
 * Written by: Eliza You and Justin Theien
 * Date: 6/26/2017
 *
 * Description: Phantom Loop Mode is one of the primary mission modes. PLM is responsible for the creation of a phantom loop and
 *              measuring its current.
 *
 */

#include "PLM.h"

//Static Global Variables-----------------------------------------------------------------------------------------------------


//Functions-------------------------------------------------------------------------------------------------------------------
void measure_current(void) {
    //power_on(/*emitter*/);
    //bias_tether();
    //power_off();
    printf("measure_current() ");

}

void run_plm(void) {
    measure_current();
    printf("Running PLM\n\n");
}
