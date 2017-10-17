/*
 * Timer3 configuration for the Atmega32u4
 * created by: Justin Theien
 * Description: Timer1 is not currently working. In order for the design of the satellite to work, we need two timers
 *              Therefore, we are going to use timer0, and timer3. *NOTE* timer 3 is a 16 bit timer, and contains different
 *              registers that that of timer0. This timer is going to be used as the systmr, and keep track of milliseconds (in intervals of 2 ms)
 *
 *  *NOTE* We are not using this timer as an output on a pin. On the Atmega32u4, there is only one output pin... and it is currently not working.
 *  it is not needed for the systmr to work though.
 *
 */

#include "timer3.h"

volatile unsigned long   tmr3_ticks = 000;
volatile unsigned long   tmr3_fifth_ticks = 0;

//----------------------------------------------------------------------------

/** unsigned long tmr0_Get2msTicks_u32(void)
*/
unsigned long tmr3_Get2msTicks_u32(void){
    unsigned long n;
    cli();
    n = tmr3_ticks;
    sei();
    return n;
}


unsigned int tmr3_Get2msTicks_u16(void){
    unsigned int n;
    cli();
    n = (unsigned int)tmr3_ticks;
    sei();
    return n;
}


unsigned char tmr3_Get2msTicks_u8(void){
    unsigned char n;
    cli();
    n = (unsigned char)tmr3_ticks;
    sei();
    return n;
}


unsigned int tmr3_Get10msTicks_u16(void){
    unsigned int n;
    cli();
    n = (unsigned int)tmr3_fifth_ticks;
    sei();
    return n;
}

/** void tck_Init(void)
* Initialize the timer hardware for the tick time base.
*/
//timer 1 PWM Configuration
void  tmr3_Init(void){
    cli(); // turn off global interrupts

    // configure OCR3A as output:
    //DDRD |= (1<<PORTC6);

    //CTC Mode with OCR1A as TOP
    TCCR3A = 0;
	TCCR3B = (1 << WGM32);

    //  Pre-scalar - divide by 64: CS1[2:0] = 0b011
    TCCR3B |= (1 << CS31) | (1 << CS30);

    OCR3A = 232; //This is defined as the TOP

    TCCR3C = 0; // not forcing output compare
    TCNT3 = 0; //The timer value is stored here, and therefore we want to reset the timer...

    // enable Timer1 CTCA interrupt
    TIMSK3 = (1<<OCIE3A);

    // This is just used for debugging.... Our team read on some forums that the USB can interfere with different ISRs and therefore we tried to disable everything USB
    USBCON = 0;
    USBCON |= (1 << FRZCLK);
    PRR1 |= (1 << PRUSB);
    UDIEN = 0;


    sei(); //Set global Interrupts

}


void  tmr3_PwmsOff(void){ //
    TCCR3A &= ~(_BV(COM3A1)); //Disable PC6 toggle
}

void  tmr3_PwmsOn(void){
    cli();
    TCCR3A |= (_BV(COM3A1)); //Enable PC6 toggle
    sei();
}

void  tmr3_PwmA(Byte duty){
    if(!duty){
       tmr3_PwmsOff();
    }
    else {
       tmr3_PwmsOn();
       OCR3A = duty;
       OCR3B = 255 - duty; // just because...
    }
}



//----------------------------------------------------------------------------
// TIMER1 CTC INTERRUPT:
ISR(TIMER3_COMPA_vect) {
    static unsigned char i;
    ++tmr3_ticks;

    // increment our 1/5th tick counter
    if(++i >= 5) {
        i = 0;
        ++tmr3_fifth_ticks;
    }

}
