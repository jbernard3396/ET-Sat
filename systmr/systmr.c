/* sysTmr.c - implements a general purpose system timer
 *
 *  Author: J. P. GEGNER
 *  Date: April 2015
 */
#include "systmr.h"    // timekeeping support
//-----------------------------------------------------------------------------
// DATA:
//SysTicks_t elapsedTicks = 0;
//-----------------------------------------------------------------------------
Bool systmr_Init(SysTimer_t *sysTimer, SysTmr_GetTicksFunc_hook_t getticks_func){

    if(getticks_func == NULL){
        return FALSE;
    }

    else {
        sysTimer->getTicks = getticks_func;
        return TRUE;
    }

}
//-----------------------------------------------------------------------------
// load timer with current system tick value
void systmr_Load(SysTimer_t *sysTimer) {

  if(sysTimer->getTicks){
      sysTimer->ticks = sysTimer->getTicks();// + sysTimer->offset;
  }
  sysTimer->latched = FALSE;
}
//-----------------------------------------------------------------------------
Bool systmr_Elapsed( SysTimer_t  *sysTimer, SysTicks_t  durationTicks,
                     Bool reloadTimer) {

  SysTicks_t elapsedTicks = 0;
  SysTicks_t systicks;

   // read the system tick value.
   // (do so only if the getTicks() function address is not NULL)
   if(sysTimer->getTicks){

        systicks = sysTimer->getTicks();

   }
   // else, return FALSE since we don't have a valid getTicks function.
   else {
        return FALSE;
   }


  // Check if timer is latched.  If so, return the last elapsed state.
  if( sysTimer->latched == TRUE ) {

    /*
    if(reloadTimer == TRUE){

      sysTimer->latched = FALSE;
      sysTimer->ticks = systicks;
      return FALSE;

    }
    */

    // return the last elapsed state, whether TRUE or FALSE.
    return sysTimer->elapsed;
  }

  // Compute the elapsed ticks
  elapsedTicks = (systicks - sysTimer->ticks);

  // Now check if durationTicks have elapsed since the timer was last loaded.
  if ( elapsedTicks >= durationTicks) {

    // updated the elapsed state. (used for when the timer is latched)
    sysTimer->elapsed = TRUE;

    // set the timer ticks to equal the current system ticks:
    if (reloadTimer) {
      sysTimer->ticks = systicks ;
    }
    /* Note: if this else latch timer is included,
       then subsequent calls to systmr_Elapsed0() will always return true,
       even if we are checking the timer against a new and longer timer
       duration.  For example, we load the timer based on some event and
       then we wish to check when 20 ticks have elapsed from that event
       and then when 50 ticks have elapsed from that same original event
       where we loaded the timer.  In such a case, we would not want to
       automatically latch the timer at the first occurrence of 20 ticks
       elapsing.
       If the durationTicks (the 20, and 50) were stored in a element of our
       timer structure, then we could automatically latch the timer once the
       duration has elapsed, but we would automatically unlatch the timer whenever
       the timer's duration ticks were updated.  This might be a better way.

    */
    //else {
    //  sysTimer->latched = TRUE;
    //}
    return TRUE;
  }
  else {
    sysTimer->elapsed = FALSE;
    return FALSE;
  }
}
//-----------------------------------------------------------------------------
// latch the result.
void systmr_Latch(SysTimer_t *sysTimer, Bool latch){
  sysTimer->latched = latch;
}
//-----------------------------------------------------------------------------
Bool systmr_IsElapsed(  SysTimer_t *sysTimer) {
    return sysTimer->elapsed;
}
//-----------------------------------------------------------------------------
// adjust timer forward(move forward in time)
void systmr_AdjustForward(SysTimer_t *sysTimer, SysTicks_t advance_ticks) {
      sysTimer->ticks -= advance_ticks;
}
//-----------------------------------------------------------------------------
// adjust timer back (move back in time, i.e. lengthen timer)
void systmr_AdjustBack(SysTimer_t *sysTimer, SysTicks_t delay_ticks) {
      sysTimer->ticks += delay_ticks;
}
//-----------------------------------------------------------------------------
// compute delta between two timers (systimer1 >= sysTimer2)
SysTicks_t systmr_Delta(SysTimer_t *sysTimer1, SysTimer_t *sysTimer2) {
  return sysTimer1->ticks - sysTimer2->ticks;
}
//-----------------------------------------------------------------------------
// returns elapsed time (in ticks) since timer was loaded
SysTicks_t systmr_Time(SysTimer_t *sysTimer) {
    return  sysTimer->getTicks() - sysTimer->ticks;
}
//-------------------------------------------------------------------------------------------------------------------------------
/* The next few functions are delay functions. Although they are not necessary, it is helpful when debugging.
    Please note, that using a delay is wasting clock cycles, and therefore is not practical in the final system*/
void delay_ms(int delay_in_ms){
    SysTimer_t ms_timer; //Declares an instance of a new timer
    systmr_Init(&ms_timer, tmr3_Get2msTicks_u16); //We are using 16 bits, so that the timer may count to a higher value
    systmr_Load(&ms_timer); //Load the timer before starting. This is used as a referenece point.

    while(!systmr_Elapsed(&ms_timer, delay_in_ms/2, SYSTMR_DO_NOT_RELOAD));
}
//-----------------------------------------------------------------------------
void delay_sec(int delay_in_sec){
    SysTimer_t sec_timer; //Declares an instance of a new timer
    systmr_Init(&sec_timer, tmr3_Get2msTicks_u16); //We are using 16 bits, so that the timer may count to a higher value
    systmr_Load(&sec_timer); //Load the timer before starting. This is used as a referenece point.
    char i;

    for(i = 0; i < delay_in_sec; i++){
        delay_ms(1000); //wait until one second has passed
    }

}
//------------------------------------------------------------------------------
void delay_min(int delay_in_min){
    SysTimer_t min_timer; //Declares an instance of a new timer
    systmr_Init(&min_timer, tmr3_Get2msTicks_u16); //We are using 16 bits, so that the timer may count to a higher value
    systmr_Load(&min_timer); //Load the timer before starting. This is used as a referenece point.
    char i;

    for(i = 0; i < delay_in_min; i++){
        delay_sec(60); //we use 60 since there are 60 seconds within each min
    }

}







