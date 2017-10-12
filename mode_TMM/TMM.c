/*
 * Written by: Eliza You and Justin Theien
 * Date: 6/26/2017
 *
 * Description: Tether Measurement Mode is one of the primary mission modes. TMM is responsible for measuring the strain and
 *              tension on the tether that PGS deploys. TUS enters TMM as PGS enters Tether Deployment Mode.s
 *
 */

 #include "TMM.h"


//Static Global Variables-----------------------------------------------------------------------------------------------------


//Functions-------------------------------------------------------------------------------------------------------------------
void measure_strain(void) {
    printf("init measure_strain() ");
}

void check_buffer() {
    printf("init check_buffer() ");
}

void run_tmm() {
    measure_strain();
    check_buffer();
    printf("TMM is running\n\n");
}
