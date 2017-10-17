// systmr.h
#ifndef _SYSTMR_H_
#define _SYSTMR_H_

#include "../typedef/typedef.h"
#include "../timer3/timer3.h" //<------- This is used so for the delay functions

// DEFINES:
#define SYSTMR_RELOAD              TRUE
#define SYSTMR_DO_NOT_RELOAD       FALSE
#define SYSTMR_LATCH               TRUE
#define SYSTMR_DO_NOT_LATCH        FALSE

// SysTicks data size defined here.  Could use byte, word, dword:
typedef Word  SysTicks_t;

// new type: pointer to a function with no arguments and returning SysTicks_t
typedef SysTicks_t (*SysTmr_GetTicksFunc_hook_t)(void);



// SysTimer_t type defined:
typedef struct {
  SysTicks_t    ticks;
  Bool          latched;
  Bool          reload;
  Bool          elapsed;
  SysTicks_t    offset;

  // pointer to function that returns system ticks:
  SysTmr_GetTicksFunc_hook_t    getTicks;

} SysTimer_t;

//global data
//none


// Initialize the timer by giving it a get ticks function address:
Bool systmr_Init(SysTimer_t *sysTimer, SysTmr_GetTicksFunc_hook_t getticks_func);

// load the timer with the current sysTicks value:
void systmr_Load(SysTimer_t *sysTimer);

// check if tickCount ticks have elapsed on sysTimer since was last loaded:
Bool systmr_Elapsed(    SysTimer_t  *sysTimer,    SysTicks_t  tickCount, Bool reloadTimer);

// latch the timer into its most recent state as determined by the last call to systmr_Elapsed().
void systmr_Latch(SysTimer_t *sysTimer, Bool latch);

// check on whether the most recent timer state is elapsed or not-elapsed
Bool systmr_IsElapsed(  SysTimer_t *sysTimer);

// adjust the timer forward(move forward in time)
void systmr_AdjustForward(SysTimer_t *sysTimer, SysTicks_t advance_ticks)  ;

// adjust timer back (move back in time, i.e. lengthen timer)
void systmr_AdjustBack(SysTimer_t *sysTimer, SysTicks_t delay_ticks) ;

// return the ticks difference between two timers:
SysTicks_t systmr_Delta(SysTimer_t *sysTimer1, SysTimer_t *sysTimer2);

// returns elapsed time (in ticks) since timer was loaded
SysTicks_t systmr_Time(SysTimer_t *sysTimer);

void delay_ms(int delay_in_ms);
void delay_sec(int delay_in_sec);
void delay_min(int delay_in_min);

#endif // _SYSTMR_H_
