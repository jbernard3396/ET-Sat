#ifndef _SCM_H_
#define _SCM_H_

//#include <avr/io.h>
#include "../Health_Safety_Check/health_safety_check.h"
#include "../Recovery_Modes/MFM.h"
#include "../mode_LVSM/LVSM.h"
#include "../mode_SMM/SMM.h"
#include "../mode_TMM/TMM.h"
#include "../mode_PLM/PLM.h"
#include "data_string.h"
#include <stdio.h>
#include <string.h>

/*typedef PWR_STATE (*GET_PWR_STATE_CALLBACK)(void);*/

typedef enum {
    LVSM = 0, // Launch Vehicle Separation Mode
    //SCM = 1, // Spacecraft Control Mode
    SMM = 1, // Science Measurement Mode
    TMM = 2, // Tether Measurement Mode
    PLM = 3, // Phantom Loop Mode

    //THe following are Routine Operations that will occur more often than the other modes
    HEALTH_SAFETY_CHECK = 4,
    SEND_TO_SIMPLEX = 5
    //MFM = 7  // Malfunction Mode

} MODE;

typedef enum {

   HIGH_PWR = 100, //TBR
   MED_PWR = 50,
   LOW_PWR = 0

} PWR_STATE;

typedef enum {

    ATT_GOOD = 100, //these numbers are TBD
    ATT_OKAY = 50,
    ATT_LOW = 0

} ATT_STATE;

typedef struct {
    MODE       currentMode;
    MODE       routineOp;
    PWR_STATE  powerState;
    ATT_STATE  attitudeState;

} SATELLITE; //This typedef is going to be used to be able to keep track of the modes and routine_ops of each satellite

//variables availabe to main
SATELLITE TUS; //TUS stands for Taylor University Satellite
SATELLITE PGS; //PGS stands for Phyxt Gears Satellite

//Functions
void SCM_Init(void);
void SCM_Set_Current_Mode(SATELLITE *sat, char message);
void SCM_TUS_Set_New_Mode(void);
void SCM_Run_Current_Mode( SATELLITE thisSatellite );


#endif // _SCM_H_
