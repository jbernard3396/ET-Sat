#ifndef _TIMER0_H_
#define _TIMER0_H_

//#include <avr/io.h>
//#include <avr/interrupt.h>
#include "../typedef/typedef.h"

//functions
void  tmr0_Init(void);
void  tmr0_PwmBOff(void);
void  tmr0_PwmBOn(void);
void  tmr0_ChangeFrequency(Byte new_TOP);
void  tmr0_PwmB(Byte duty);
void tmr0_PwmB_toggle(Byte duty);


#endif // _TIMER0_H_
