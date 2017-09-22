/*
 * Timer1 configuration for the Atmega32u4
 * created by: Justin Theien
 * Description: right now, the timer is set up to operate in CTC mode
 *              TOP = ICR1L,timer 1 is being used as the system timer, because timer0
 *              is already being used.
 *
 */

#include "timer1.h"



volatile unsigned long   tmr1_ticks = 000;
volatile unsigned long   tmr1_fifth_ticks = 0;

//----------------------------------------------------------------------------

/** unsigned long tmr0_Get2msTicks_u32(void)
*/
unsigned long tmr1_Get2msTicks_u32(void){
    unsigned long n;
    cli();
    n = tmr1_ticks;
    sei();
    return n;
}


unsigned int tmr1_Get2msTicks_u16(void){
    unsigned int n;
    cli();
    n = (unsigned int)tmr1_ticks;
    sei();
    return n;
}


unsigned char tmr1_Get2msTicks_u8(void){
    unsigned char n;
    cli();
    n = (unsigned char)tmr1_ticks;
    sei();
    return n;
}


unsigned int tmr1_Get10msTicks_u16(void){
    unsigned int n;
    cli();
    n = (unsigned int)tmr1_fifth_ticks;
    sei();
    return n;
}

/** void tck_Init(void)
* Initialize the timer hardware for the tick time base.
*/
//timer 1 PWM Configuration
void  tmr1_Init(void){
    //Try to disable the usb interrupt vectors
    //USBINT = 0;
    UDINT  = 0;
    uint8_t _i;

    //USBINT = 0;
    //UDINT  = 0;

    for ( _i = 0; _i < 6; _i++) { // For each USB endpoint
       UENUM = _i; // select the _i-th endpoint
       UEINTX = UEIENX = 0; // Clear interrupt flags for that endpoint
    }



    cli(); // turn off global interrupts

    // configure OCR0A and OCR0Bas output:
    DDRD |= (1<<PORTD0)+(1<<PORTD1);

    //CTC Mode with OCR1A as TOP
    TCCR1A = 0;
	TCCR1B = (1 << WGM12);

    //  Pre-scalar - divide by 64: CS1[2:0] = 0b011
    TCCR1B |= (1 << CS10);// | _BV(CS11);

    OCR1A = 25000; //This is defined as the TOP
    OCR1B = 200;

    TCCR1C = 0; // not forcing output compare
    TCNT1 = 0; //The timer value is stored here, and therefore we want to reset the timer...

    // enable Timer1 CTCA interrupt
    TIMSK1 = (1<<OCIE1A);

    //
    USBCON = 0;
    USBCON |= (1 << FRZCLK);
    PRR1 |= (1 << PRUSB);
    UDIEN = 0;


    sei(); //Set global Interrupts

}

void  tmr1_PwmsOff(void){
    TCCR1A &= ~(_BV(COM1B1)); //Disable PD0 toggle
}

void  tmr1_PwmsOn(void){
    cli();
    TCCR1A |= (_BV(COM1B1)); //Enable PD0 toggle
    sei();
}

void  tmr1_PwmA(Byte duty){
    if(!duty){
       tmr1_PwmsOff();
    }
    else {
       tmr1_PwmsOn();
       OCR1A = duty;
       OCR1B = 255 - duty; // just because...
    }
}



//----------------------------------------------------------------------------
// TIMER1 CTC INTERRUPT:
ISR(TIMER1_COMPA_vect) {

    PORTD |= (1 << PORTD5);
/*
    static unsigned char i;
    ++tmr1_ticks;

    // increment our 1/5th tick counter
    if(++i >= 5) {
        i = 0;
        ++tmr1_fifth_ticks;
    }
*/
}

