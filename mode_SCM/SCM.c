/*
 * Written By: Eliza You and Justin Theien
 * Date: 6/23/2017
 *
 * Description: Spacecraft Control Mode is the first mode in Mission Phase. It is responsible for all spacecraft operation between
 *              TUS and PGS, assuming communication is established. Otherwise, SCM is responsible solely for TUS operation.
 *

 mode_sequences:
            TUS - PLM      | PGS - PLM
            TUS - PLM, TMM | PGS - PLM, TDM
            TUS - TMM, SMM | PGS - TDM, SMM
            TUS - SMM      | PGS - SMM
 */

#include "SCM.h"
//Variables
static MODE last_recorded_mode = SEND_TO_SIMPLEX; //I only chose this mode because we will never start in this mode, and therefore it will not conflict when the satellite is first turned on.
static Bool enterHealthSafetyCheck   = TRUE;
static Bool runRoutineOp             = TRUE;
static MODE previousNonRoutineOpMode = LVSM;

void SCM_Init(void){
    //LVSM will be the first mode that each satellite enters, and therefore they should beinitialized this way.
    TUS.currentMode = LVSM;
    PGS.currentMode = LVSM;
}

void SCM_TUS_Set_New_Mode(void){
    //Since TUS is the master, The TUS satellite will be in charge of setting which mode the two satellites are going into (there is a master-slave relationship)
    if(runRoutineOp){
        if(enterHealthSafetyCheck){
            TUS.currentMode = HEALTH_SAFETY_CHECK;
            enterHealthSafetyCheck = FALSE;
        }
        else{
            TUS.currentMode = SEND_TO_SIMPLEX;
            enterHealthSafetyCheck = TRUE;
        }
        if(TUS.currentMode == SEND_TO_SIMPLEX){ // we want to run HEALTH_SAFETY_CHECK right after we run SEND_TO_SIMPLEX
            runRoutineOp = FALSE;
        }
    }

    else{
        previousNonRoutineOpMode++; //increment to the next mode so that we do not repeat the same mode twice.
        if(previousNonRoutineOpMode > 3){
            previousNonRoutineOpMode = 1;
        }

        TUS.currentMode = previousNonRoutineOpMode;
        runRoutineOp = TRUE;
    }
}

void SCM_Set_Current_Mode(SATELLITE *sat, char message){
    //We now determine what to do with the message that has been sent to us from the other satellite
    if(message != NO_NEW_MESSAGE && message != RECEIVE_SUCCESSFUL){
        last_recorded_mode = sat->currentMode;
        sat->currentMode = message;
    }
    //else don't do anything
}

 void SCM_Run_Current_Mode( SATELLITE thisSatellite ){   //This describes what happens within each mode
//Each of these modes contains it's own .c and .h file. The plan is to call a function within this switch statement. The function is going to be declared in
//the individual .c and .h files
    switch( thisSatellite.currentMode ){
        case LVSM :                         // #0
//                delay_ms(2000);
            break;

        case SMM :                          // #1
//                delay_ms(1000);
            break;

        case TMM :                          // #2
//                delay_ms(1000);
            break;

        case PLM :                          // #3
//                delay_ms(1000);
            break;
        case HEALTH_SAFETY_CHECK :           // #4
//                delay_ms(1000);

            break;
        case SEND_TO_SIMPLEX :              // #5
//                delay_ms(1000);
            break;
    }
 }
