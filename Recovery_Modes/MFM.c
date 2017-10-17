/*
 * Written by: Eliza You and Justin Theien
 * Date: 6/26/2017
 *
 * Description: Malfunction Mode is a part of Recovery Modes and entered only by a FALSE reading during a Health and Safety
 *              check. MFM is responsible for ensuring the spacecraft is operable condition and resume spacecraft functionality.
 *              MFM is also equipped to cut the tether if it is deemed necessary.
 *
 */

 #include "MFM.h"

//Static Global Variables-----------------------------------------------------------------------------------------------------


//Functions-------------------------------------------------------------------------------------------------------------------

/*
    THINGS2CONSIDER:
        -Go back to Health and Safety Check
*/

void power_error(void) {
    return;
}

void attitude_error(void) {
    return;
}

void run_malfunction_mode(int error_val){     //priority hierarchy that revisits issues depending on severity (?)
                                            //somehow indicate to SCM that spacecraft is in MFM

    //int error value or name of error
    switch ( error_val ) {
        case 0 :                    //attitude error
            led_clear();
            PORTB |= (1<<PB0);
            delay_ms(500);
            break;

        case 1 :                    //tether error
            led_clear();
            PORTD |= (1<<PD7);
            delay_ms(500);
            break;

        case 2 :
            led_clear();            //power error
            PORTD |= (1<<PD6);
            delay_ms(500);
            break;

        case 3 :
            break;

        case 4 :
            break;

        case 5 :
            break;

        case 6 :
            break;

    }
}
