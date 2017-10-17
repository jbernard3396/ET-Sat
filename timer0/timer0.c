/*
 * Timer0 configuration for the Atmega32u4
 * created by: Justin Theien
 * Description: right now, the timer is set up to operate at fast PWM 8-bit mode
 *              The timers frequency is determined by OCR0A and the duty cycle is determined by OCR0B
 *              the default frequency is set at 56 KHz, since this will be the timer that is used to operate the IR LED
 *              There are no interrupts set, therefore please use timer0 if in need of that
 *
 * *NOTE* in order to make any of the timers function properly, both the INIT() function, as well as the tmr_pwmA() need to be called with a pwm value......
 *
 */

#include "timer0.h"

static Bool pwmB_in_use = FALSE;

void  tmr0_Init(void){
    cli(); // turn off global interrupts

    // configure OCR0B as output (for debugging, to make sure that the PWM is working:
    DDRD |= (1 << PORTD0); //OC0B <--This is what the IR LED is connected to
    PORTD &= ~(1<<PORTD0);
    //DDRB |= (1 << PORTB7); //OC0A

    /*  Fast PWM 8-bit: WGM1[2:0] = 0b1110,
        set Fast PWM mode using OCR0A as TOP
        clear output on compare (in fast pwm mode): COM1A[1:0]=COM1B[1:0]=2
        note: WGM12 and WGM13 are located in TCCR1B
    */
    TCCR0A = _BV(WGM01) | _BV(WGM00);
    TCCR0B = _BV(WGM02);

    /*  Pre-scalar - divide by 0: CS1[2:0] = 0b001 */
    TCCR0B |= _BV(CS00);


    // Determine the Duty cycle to be used when in fast PWM mode...
    OCR0A = _56_KHZ; //This is set later when the IR LED is called.. This determines the frequency of the timer
    OCR0B = 30; //This is the only place where the duty cycle is set at this point***********************************************************************

    sei();
}

void  tmr0_PwmBOff(void){
    cli();
    TCCR0A &= ~(_BV(COM0B1));
    pwmB_in_use = FALSE;
    sei();
}

void  tmr0_PwmBOn(void){
    cli();
    TCCR0A |= _BV(COM0B1);
    pwmB_in_use = TRUE;
    sei();
}

void tmr0_ChangeFrequency(Byte new_TOP){
    if(new_TOP > 0 && new_TOP < 10000){
        OCR0A = new_TOP;
    }
}

void tmr0_PwmB(Byte duty){

    if(!duty){
       tmr0_PwmBOff();
    }
    else {
       tmr0_PwmBOn();
       OCR0A = duty;
    }
}

void tmr0_PwmB_toggle(Byte duty){
    if(pwmB_in_use){
        tmr0_PwmBOff();
    }
    else{
        tmr0_PwmBOn();
        OCR0A = duty;
    }
}

