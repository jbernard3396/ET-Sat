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
const char otherData[] = "\"CW01\": { \"RSSI\": 55, \"Chip ID\": 19938676, \"MAC\": \"11:22:33:77:88:99\" }, \"Input\": { \"Unit Name\": \"Jacobs Test Unit\", \"Organization\": \"Satelite Software Team\", \"Location_lat_lon\": [ -70.6264, 80 ], \"Altitude\": 2065000 }, \"Timestamp\": { \"Created\": \"2017-10-26T20:19:24\" }";
static MODE last_recorded_mode = SEND_TO_SIMPLEX; //I only chose this mode because we will never start in this mode, and therefore it will not conflict when the satellite is first turned on.
const char headString[STRINGLENGTHHEADSTRING] = "{\"GS\":{";
const char endString[STRINGLENGTHENDSTRING] = "}}";
static Bool enterHealthSafetyCheck = TRUE;
static Bool runRoutineOp = TRUE;
static MODE previousNonRoutineOpMode = LVSM;
char dataString[STRINGLENGTHDATASTRING];
char stringToSend[STRINGLENGTHSTRINGTOSEND];

void SCM_Init(void) {
    //LVSM will be the first mode that each satellite enters, and therefore they should beinitialized this way.
    TUS.currentMode = LVSM;
    PGS.currentMode = LVSM;
}
/**
void SCM_TUS_Set_New_Mode(void) {
    //Since TUS is the master, The TUS satellite will be in charge of setting which mode the two satellites are going into (there is a master-slave relationship)
    if (runRoutineOp) {
        if (enterHealthSafetyCheck) {
            TUS.currentMode = HEALTH_SAFETY_CHECK;
            enterHealthSafetyCheck = FALSE;
        } else {
            TUS.currentMode = SEND_TO_SIMPLEX;
            enterHealthSafetyCheck = TRUE;
        }
        if (TUS.currentMode ==
            SEND_TO_SIMPLEX) { // we want to run HEALTH_SAFETY_CHECK right after we run SEND_TO_SIMPLEX
            runRoutineOp = FALSE;
        }
    } else {
        previousNonRoutineOpMode++; //increment to the next mode so that we do not repeat the same mode twice.
        if (previousNonRoutineOpMode > 3) {
            previousNonRoutineOpMode = 1;
        }

        TUS.currentMode = previousNonRoutineOpMode;
        runRoutineOp = TRUE;
    }
}
 */

void scm_change_current_mode(void) {
    switch(TUS.currentMode) {
        case LVSM:
            TUS.currentMode = SMM;
            break;
        case SMM:
            TUS.currentMode = TMM;
            break;
        case TMM:
            TUS.currentMode = PLM;
            break;
        case PLM:
            TUS.currentMode = HEALTH_SAFETY_CHECK;
            break;
        case HEALTH_SAFETY_CHECK:
            TUS.currentMode = SEND_TO_SIMPLEX;
            break;
        case SEND_TO_SIMPLEX:
            TUS.currentMode = LVSM;
    }
}

void SCM_Set_Current_Mode(SATELLITE *sat, char message) {
    //We now determine what to do with the message that has been sent to us from the other satellite
    if (message != NO_NEW_MESSAGE && message != RECEIVE_SUCCESSFUL) {
        last_recorded_mode = sat->currentMode;
        sat->currentMode = message;
    }
    //else don't do anything
}

void eat_time(void) {
    int k = 0;
    for (int i = 0; i < 100000; i++) {
        for (int j = 0; j < 10000; j++) {
            k = i + j;
        }
    }
}

void SCM_Run_Current_Mode(SATELLITE thisSatellite) {
//This describes what happens within each mode
//Each of these modes contains it's own .c and .h file. The plan is to call a function within this switch statement. The function is going to be declared in
//the individual .c and .h files
    switch (thisSatellite.currentMode) {
        case LVSM : //Launch Vehicle Separation Mode #0
            printf("RUN LVSM\n");
//            run_lvsm();
            break;

        case SMM : //Science Measurement Mode #1
            printf("RUN SMM\n");
			char stringSMM[STRINGLENGTHSMM];
            strcpy(dataString, run_smm(stringSMM));
			printf("dataString=>%s\n", dataString);
            break;

        case TMM : //Tether Measurement Mode #2
            printf("RUN TMM\n");
			char stringTMM[STRINGLENGTHTMM];
			strcat(dataString, ",");
			strcat(dataString, run_tmm(stringTMM));
			printf("dataString=>%s\n", dataString);
            break;

        case PLM : //Phantom Loop Mode #3
            printf("RUN PLM\n\n");
			char stringPLM[STRINGLENGTHPLM];
			strcat(dataString, ",");
			strcat(dataString, run_plm(stringPLM));
			printf("dataString=>%s\n", dataString);
			printf("otherData=>%s\n", otherData);
			// Concatinate with otherData
			strcpy(stringToSend, headString);
			strcat(stringToSend, dataString);
			strcat(stringToSend, ",");
			strcat(stringToSend, otherData);
			strcat(stringToSend, endString);
			printf("stringToSend=>%s\n", stringToSend);
			
            break;

        case HEALTH_SAFETY_CHECK : // Health and safety #4
            printf("RUN HEALTH_AND_SAFETY\n");
//            run_health_safety_check();
            break;

        case SEND_TO_SIMPLEX : // #5
            printf("RUN SEND_TO_SIMPLEX\n");
            printf("Running SEND_TO_SIMPLEX\n\n");
            break;
    }

    eat_time();
    printf("::CHANGING MODE::\n\n");
    scm_change_current_mode();
    eat_time();
}
