#ifndef _IO_H_
#define _IO_H_


//#include <avr/io.h>
#include "../typedef/typedef.h"
#include "../timer0/timer0.h"


/* IO Pin defines */

// Note that setting PORTBO turns ON the LED
#define IO_LED_PIN_PORT  PORTB
#define IO_LED_PIN_DDR   DDRB
#define IO_LED_PIN       PORTB0


// Push-button (or maybe later a Piezo)
// Note that PORTB2 idles High via the internal pull-up
// and "dips" when piezo is tapped.
#define IO_SW_PIN_PORT    PORTB
#define IO_SW_PIN_DDR     DDRB
#define IO_SW_PIN         PORTB2
#define IO_SW_PIN_PIN     PINB


/* IO pin macro functions */

#define initOutputPinM(DDR,PIN)           DDR |= 1 <<(PIN)
#define initInputPinM(DDR,PIN)            DDR &= ~(1 <<(PIN))
#define setPinM(PORT, PIN)                ((PORT) |= 1 << (PIN))
#define clearPinM(PORT, PIN)              ((PORT) &= ~(1 << (PIN)))
#define setPinStateM(state, PORT, PIN)    (state) ? setPinM(PORT,PIN) :  clearPinM(PORT,PIN)
#define setPinPullupM(PORT, PIN)          setPinM(PORT, PIN)
#define readPinM(PIN_PIN, PIN)            ( ( (PIN_PIN) & (1<<(PIN)) ) >> (PIN))
#define togglePinM(PORT, PIN)             ((PORT) ^= (1 << (PIN)))


/* IO peripheral macro functions */

#define initLedM()      initOutputPinM(IO_LED_PIN_DDR, IO_LED_PIN)
#define setLedM()       setPinM(IO_LED_PIN_PORT, IO_LED_PIN)
#define clearLedM()     clearPinM(IO_LED_PIN_PORT, IO_LED_PIN)
#define toggleLedM()    togglePinM(IO_LED_PIN_PORT, IO_LED_PIN)
#define initSwitchM()   initInputPinM(IO_SW_PIN_DDR,IO_SW_PIN);\
                        setPinPullupM(IO_SW_PIN_PORT, IO_SW_PIN)
#define readSwitchM()   readPinM(IO_SW_PIN_PIN,IO_SW_PIN)

//---------------------------------------------------------------------------------------------------------------------------
//Everything below the line is used for the IR communication system
// Note that setting PORTBO turns ON the LED
#define IO_IR_LED_PIN_PORT  PORTB
#define IO_IR_LED_PIN_DDR   DDRB
#define IO_IR_LED_PIN       PORTB0

//This is used specifically for the LED Fob....
#define IR_LED_ON()              tmr0_PwmB(_56_KHZ) //this value seens to make the clock as close to 56 KHz as possible
#define IR_LED_OFF()             tmr0_PwmB(OFF)
#define IR_LED_TOGGLE()          tmr0_PwmB_toggle(_56_KHZ) //This is just usedfor testing to make sure that the IR LED is working

Bool io_getSwitchState(void);
#endif // _IO_H_

