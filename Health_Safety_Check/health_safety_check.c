/*
 * Written By: Justin Theien and Eliza You
 *
 * Description: Health and Safety Check is performed before entering a mode. This process is responsible for monitoring the spacecraft's
 *              condition. If a flag is issued, Malfunction Mode is executed. Otherwise, Spacecraft Control Mode proceeds onto the next mode.
 *
 */

#include "health_safety_check.h"

//Static Global Variables -------------------------------------------------------------------------------------------------------------------
/*
PWR_STATE tus_power_status = HIGH_PWR;  //status of high voltage battery supply
PWR_STATE nsl_power_status = HIGH_PWR;  //when the satellite turns on, we can assume that we have a full battery [TBR]
*/
static HEALTH_STATE HEALTH_SAFETY_STATUS = ATTITUDE_STATUS;      //Begins health and safety check

//Functions----------------------------------------------------------------------------------------------------------------------------------
/*PWR_STATE get_tus_pwr_state(void){
    return tus_power_status;
}

PWR_STATE get_nsl_pwr_state(void){
    return nsl_power_status;
}*/

Bool attitude_status_ok(void){
    //power on imu and imu_post() if not calibrated

    int roll_1 = 1;                             //placeholder values; TBD
    int roll_2 = 2;
    int roll_3 = 3;

    int attitude = roll_1 * roll_2 * roll_3;    //calculate attitude (maybe another func?)
    int high_threshold = 100;                   //high_threshold = some ridiculously high roll rate that exceeds our "BAD" condition

    if ( attitude > high_threshold ) {          //spacecraft roll rate too high; MFM checks IMU for faulty reading or passive detumble
        return FALSE;
    }
    return TRUE;

}

Bool tether_status_ok(void){
    //idk my bff tiff
    return TRUE;
}

Bool tus_power_status_ok(void) {
    int power = 100;                        //placeholder; TBD
    int low_threshold = 25;                 //placeholder; TBD

    if ( power < low_threshold ) {          //emitter battery level too low, need to wait to solar charge
        return FALSE;
    }                                       //add if power too high (in the case of a faulty read?)
    return TRUE;
}

/*Bool communication_status_ok(void){           //TUS doesn't care? TUS interrupts PGS to go into whatever mode. PGS has to know which mode op to rely on: time, interrupt.
}*/

void flag_status( Bool conditional_val, int error_val ) {
    if ( conditional_val == FALSE ) {
//        run_malfunction_mode( error_val );              //send to Malfunction Mode w/error code
        printf("condition value was false");
    }
}

void mode_test_init(void){
    //set LED pins as output
    /**
    DDRB |= (1<<PB0)|(1<<PB1)|(1<<PB6)|(1<<PB7);//|(1<<PB2)|(1<<PB3)|(1<<PB4)|(1<<PB5);
    //DDRC |= (1<<PC0)|(1<<PC1)|(1<<PC2)|(1<<PC3)|(1<<PC4)|(1<<PC5)|(1<<PC6);
    DDRD |= (1<<PD0)|(1<<PD1)|(1<<PD4)|(1<<PD5)|(1<<PD6)|(1<<PD7); //|(1<<PD2)|(1<<PD3);
     */
}

void led_clear(void){
    /*****************************
    PORTB &= 0;
    PORTC &= 0;
    PORTD &= 0;
     */
}

void run_health_safety_check(void){
    printf("Running Health and Safety Checks\n\n");
    switch ( HEALTH_SAFETY_STATUS ) {
        case ATTITUDE_STATUS :                          //if true, move to next health check. if false, go to malfunction mode(error_code).
            //led_clear();
            //PORTC |= (1<<PC4);
            //_delay_ms(100);         //delay 100 ms*/

            flag_status( attitude_status_ok(), 0 );

        case TETHER_STATUS :
            //led_clear();
            //PORTC |= (1<<PC3);
            //_delay_ms(100);

            flag_status( tether_status_ok(), 1 );

        case TUS_POWER_STATUS :
            //led_clear();
            //PORTC |= (1<<PC2);
            //_delay_ms(100);

            flag_status( tus_power_status_ok(), 2 );

        //case COMMUNICATION_STATUS :
            //flag_status( communication_status_ok(), 3 );
            break;
    }
}

