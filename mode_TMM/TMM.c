/*
 * Written by: Eliza You and Justin Theien
 * Date: 6/26/2017
 *
 * Description: Tether Measurement Mode is one of the primary mission modes. TMM is responsible for measuring the strain and
 *              tension on the tether that PGS deploys. TUS enters TMM as PGS enters Tether Deployment Mode.s
 *
 */

#include "TMM.h"


//Static Global Variables-----------------------------------------------------------------------------------------------------
const int lengthToExtendTether = 5;


//Functions-------------------------------------------------------------------------------------------------------------------

void measure_strain(void) {
	printf("init measure_strain() ");
}

void check_buffer() {
	printf("init check_buffer() ");
}

char * run_tmm(char * returnString){
	measure_strain();
	check_buffer();
	printf("TMM is running\n\n");
	int result = sendTetherExtensionSignal(lengthToExtendTether);
	snprintf(returnString, STRINGLENGTHTMM, "\"tetherSignal\":%2d", result);
	return returnString;
}

int getCommunicationStatus() {
	// return GetPing(); // 0 if no connection, big ping means good connection
	int randnum = rand() % 100;
	return randnum; // TEST
}

int sendTetherExtensionSignal(int lengthToExtend) {
	int status = getCommunicationStatus();
	if (status != 0) // if there is connection
	{
		int sendResult = sendSignal(lengthToExtend);
		if (sendResult != 0) // if succeeded
		{
			printf("Tether Extension Signal: 1-- succeeded\n"); // TEST
			return 1;
		}
		else // if not succeed
		{
			printf("Tether Extension Signal: -2-- failed to send signal\n"); // TEST
			return -2;
		}
	}
	else // if there is no connection
	{
		printf("Tether Extension Signal: -1-- no connection\n"); // TEST
		return -1; 
	}
}

int sendSignal(int length){
	// int result = send(length); 
	int result = rand() % 3; // TEST get either 0 or 1 or 2
	return result;
}
