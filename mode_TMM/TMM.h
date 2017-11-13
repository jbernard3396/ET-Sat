#ifndef _TMM_H_
#define _TMM_H_

#include "../IR_Protocol/IR_Protocol.h"
#include "../mode_SCM/data_string.h"
#include <stdio.h>

//Functions
int rand(void);
void measure_strain(void);
void check_buffer(void);
char * run_tmm(char * returnString);
int getCommunicationStatus();
int sendTetherExtensionSignal(int);
int sendSignal(int);

#endif // _TMM_H_
