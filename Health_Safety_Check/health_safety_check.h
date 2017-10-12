#ifndef _HEALTH_SAFETY_CHECK_H_
#define _HEALTH_SAFETY_CHECK_H_

#include "../typedef/typedef.h"
#include "../Recovery_Modes/MFM.h"
#include <stdio.h>

typedef enum {

    ATTITUDE_STATUS = 0,
    TETHER_STATUS = 1,
    TUS_POWER_STATUS = 2
    //COMMUNICATION_STATUS = 3;

} HEALTH_STATE;

//functions
Bool thermal_status_ok(void);
Bool attitude_status_ok(void);
Bool tether_status_ok(void);
Bool tus_power_status_ok(void);
//Bool communication_status_ok(void);
void flag_status( Bool conditional_val, int error_val );

void mode_test_init(void);
void led_clear(void);


void run_health_safety_check(void);


#endif // _HEALTH_SAFETY_CHECK_H_
