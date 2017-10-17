#ifndef _TIMER3_H_
#define _TIMER3_H_

#include "../typedef/typedef.h"
//#include <avr/io.h>
//#include <avr/interrupt.h>

//functions
unsigned long tmr3_Get2msTicks_u32(void);
unsigned int  tmr3_Get2msTicks_u16(void);
unsigned char tmr3_Get2msTicks_u8(void);
unsigned int  tmr3_Get10msTicks_u16(void);

void  tmr3_Init(void);
void  tmr3_PwmsOff(void);
void  tmr3_PwmsOn(void);
void  tmr3_PwmA(Byte duty);

#endif // _TIMER3_H_
