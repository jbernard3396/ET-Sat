/*
 * Written by: Eliza You and Justin Theien
 * Date: 6/26/2017
 *
 * Description: Science Measurement Mode is the first mode TUS enters from Spacecraft Control Mode. SMM is responsible for measuring
 *              peripheral data, such as plasma, light, and temperature. SMM is a low power mission.
 *
 */

#include "SMM.h"

//Static Global Variables-----------------------------------------------------------------------------------------------------



//Functions-------------------------------------------------------------------------------------------------------------------


unsigned short measure_light(void) {              //are we measuring light intensity or presence?
    unsigned short lightValue = Get_Ambient_Light();
    if (lightValue == 0) return 0;// Handle Error Here
    return lightValue;

}

unsigned short measure_em(void) {
    unsigned short emMeasure = getEmField();
    if (emMeasure == 0)  return 0;// Handle Error Here
    return emMeasure;

}
short measure_RotationX(void) {
    short rotationX = getRotationX();
   if (rotationX == 0) return 0; //ErrorHandling
    return rotationX;
}
short measure_RotationY(void) {
    short rotationY = getRotationY();
    if (rotationY == 0) return 0; //ErrorHandling
    return rotationY;
}
short measure_RotationZ(void) {
    short rotationZ = getRotationZ();
    if (rotationZ == 0) return 0; //ErrorHandling
    return rotationZ;
}


char * sendScienceMeasurements(char * returnString){
    unsigned short light = measure_light();
    unsigned short emField =measure_em();
    short rotationX = measure_RotationX();
    short rotationY = measure_RotationY();
    short rotationZ = measure_RotationZ();

    if (light == 0){  //Testing Ambient Light
        printf("%s","There was an error in getting the ambient light \n");
    } else{
        printf("Ambient light= %d\n", light);
    }
    if (emField == 0){  //Testing Ambient Light
        printf("%s","There was an error in getting the ElectroMagnetic Field \n");
    } else{
        printf("ElectroMagnetic Field = %d\n", emField);
    }
    if (rotationX == 0){  // Testing Rotation X
        printf("%s","There was an error in getting rotation X \n");
    } else{
        printf("Rotation X= %d\n", rotationX);
    }
    if (rotationY == 0){  //Testing Rotation Y
        printf("There was an error in getting rotation Y \n");
    } else{
        printf("Rotation Y= %d\n", rotationY);
    }
    if (rotationZ == 0){  //Testing Rotation Z
        printf("%s","There was an error in getting rotation Z \n");
    } else{
        printf("Rotation Z= %d\n", rotationZ);
    }

	// Copy values obtained into the return string
	snprintf(returnString, STRINGLENGTHSMM, "\"light\":%5hu,\"emField\":%5hu,\"rotationX\":%5hd,\"rotationY\":%5hd,\"rotationZ\":%5hd",
			light, emField, rotationX, rotationY, rotationZ);
	return returnString;



	

}
char * run_smm(char * returnString)
{
	return sendScienceMeasurements(returnString);
}
