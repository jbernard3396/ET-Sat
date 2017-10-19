#ifndef _SMM_H_
#define _SMM_H_

#include "../IR_Protocol/IR_Protocol.h"
#include "../Sensors/Light_Sensor.h"
#include "../Sensors/Em_Sensor.h"
#include "../Sensors/Rotation_Sensor.h"
#include <stdio.h>

//functions
void run_smm();
void sendScienceMeasurements(void);

#endif //_SMM_H
