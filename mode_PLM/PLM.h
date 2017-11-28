#ifndef _PLM_H_
#define _PLM_H_

#include "../IR_Protocol/IR_Protocol.h"
#include "../mode_SCM/data_string.h"
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
//Functions
bool power_loop_on(void);
bool power_loop_off(void);
bool handle_phantom_loop_error();
int initialize_phantom_loop_current();
int get_phantom_loop_current();
void kill_current();
char * run_plm(char * returnString);
#endif // _PLM_H_

