#ifndef _TIMER1_H_
#define _TIMER1_H_

#include "../typedef/typedef.h"
//#include <avr/io.h>
//#include <avr/interrupt.h>

//functions
unsigned long tmr1_Get2msTicks_u32(void);
unsigned int  tmr1_Get2msTicks_u16(void);
unsigned char tmr1_Get2msTicks_u8(void);
unsigned int  tmr1_Get10msTicks_u16(void);

void  tmr1_Init(void);
void  tmr1_PwmsOff(void);
void  tmr1_PwmsOn(void);
void  tmr1_PwmA(Byte duty);



#endif // _TIMER1_H_
