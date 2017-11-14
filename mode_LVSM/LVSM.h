#ifndef _LVSM_H_
#define _LVSM_H_

#include "../IR_Protocol/IR_Protocol_sendBits.h"
#include <stdio.h>
//Functions
void obc_post(void);
Bool power_on(void);
void imu_post(void);
void run_lvsm(void);

#endif // _LVSM_H_
