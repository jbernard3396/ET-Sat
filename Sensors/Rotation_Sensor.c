//
// Created by caleb Anthony on 10/5/2017.
//

#include "Rotation_Sensor.h"
#include <limits.h>
#include <stdio.h>

short getRotationX(){
   short rotationX = -1999; // Sensor Rotation Getting
    if (rotationX > SHRT_MAX || rotationX < SHRT_MIN) return 0;
    if (rotationX == 0) rotationX = 1; //Same as light Sensor, 0 is mapped to 1.
    return rotationX;
}

short getRotationY(){
   short rotationY = 9999; //Gets rotation
    if (rotationY > SHRT_MAX || rotationY < SHRT_MIN) return 0;
    if (rotationY == 0) rotationY = 1; //Same as light Sensor, 0 is mapped to 1.
    return rotationY;
}
short getRotationZ() {
    short rotationZ = SHRT_MAX + 1;
    if (rotationZ > SHRT_MAX || rotationZ < SHRT_MIN) { // Or any other type of error
        return 0;
    }
    if (rotationZ == 0) rotationZ = 1; //Same as light Sensor, 0 is mapped to 1.
    return rotationZ;
}

