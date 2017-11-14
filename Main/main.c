/*
 * Thin-Sat Embedded Code
 * Creator: Justin Theien
 * Date: 6/9/2017
 *
 * Team members: Justin Theien, Chester Chan, Austin Wolgemuth, Eliza You, Moriah S.
 *
 * *NOTE* in order to make sure that the timers function properly, we need to make sure that the efuse is set to 0xe2 (for the atmega328p)
 *        This can be accomplished through the avrdude terminal (located within tools on C::B on my machine)
 *
 *
 */

#include "main.h"


//Gloabal variables
static char recievedMessage = NO_NEW_MESSAGE;

int main(void) {
    //Setup starts here!
    // initialize the system
    tmr0_Init(); //This is used for IR communication
    tmr3_Init(); //This is used as the systmr
    IR_Communication_System_Init(tmr3_Get2msTicks_u16);


    //This following is just a setup for timer. This is not currently used, and therefore it is commented out
    SysTimer_t timer1; //Declares an instance of a new timer
    systmr_Init(&timer1, tmr3_Get2msTicks_u16); //We are using 16 bits, so that the timer may count to a higher value
    systmr_Load(&timer1); //Load the timer before starting. This is used as a referenece point.

    //init test LED
    DDRD |= (1 << PORTD7);
    //PORTD &= ~(1<<PORTD7);

    SCM_Init();
    while (1) {
        if(systmr_Elapsed(&timer1, (1000/2), SYSTMR_RELOAD)){ //this is just testing if the message sending works properly
            //send_Message(5);
            PORTD ^= (1<<PORTD7);
        }
    }
    return 0;
}

