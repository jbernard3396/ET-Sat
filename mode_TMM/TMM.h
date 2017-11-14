#ifndef _TMM_H_
#define _TMM_H_

#include "../IR_Protocol/IR_Protocol_sendBits.h"
#include <stdio.h>

//Functions
int rand(void);
void measure_strain(void);
void check_buffer(void);
void run_tmm(void);
int getCommunicationStatus();
int sendTetherExtensionSignal(int);
int sendSignal(int);

#endif // _TMM_H_
