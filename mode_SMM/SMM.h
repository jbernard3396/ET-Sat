#ifndef _SMM_H_
#define _SMM_H_

#include "../IR_Protocol/IR_Protocol.h"
#include "../Sensors/Light_Sensor.h"
#include "../Sensors/Em_Sensor.h"
#include "../Sensors/Rotation_Sensor.h"
#include "../mode_SCM/data_string.h"
#include <stdio.h>

//functions
char * run_smm(char * returnString);
char * sendScienceMeasurements(char * returnString);

#endif //_SMM_H
