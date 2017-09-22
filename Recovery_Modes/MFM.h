#ifndef _MFM_H_
#define _MFM_H_

#include "../IR_Protocol/IR_Protocol.h"
#include "../Health_Safety_Check/health_safety_check.h"

//Functions
void power_error(void);
void temperature_error(void);
void attitude_error(void);

void run_malfunction_mode(int error_val);

#endif // _MFM_H_
