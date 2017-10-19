#cmake_minimum_required(VERSION 3.5)
#project(ET-Sat)

#set(CMAKE_C_STANDARD 99)

#set(SOURCE_FILES MainTests/mainTest.c MainTests/mainTest.h mode_SCM/SCM.c mode_SCM/SCM.h mode_SMM/SMM.c mode_SMM/SMM.h Sensors/Light_Sensor.c Sensors/Light_Sensor.h)
#add_executable(ET-Sat ${SOURCE_FILES})
#Copy entire cmakelists and echange main.c/h with test.c/h, ake amviant light sensor in sensorfolders.. etc .c and .h,
#test all inputs to return files
cmake_minimum_required(VERSION 3.5)
project(ET-Sat)

set(CMAKE_C_STANDARD 99)

set(SOURCE_FILES Main/main.c Main/main.h mode_SCM/SCM.c mode_SCM/SCM.h mode_PLM/PLM.c mode_PLM/PLM.h mode_SMM/SMM.c mode_SMM/SMM.h mode_TMM/TMM.c mode_TMM/TMM.h Sensors/Light_Sensor.c Sensors/Light_Sensor.h Sensors/Rotation_Sensor.c Sensors/Rotation_Sensor.h
       Sensors/Em_Sensor.c Sensors/Em_Sensor.h Sensors/Tether_Communication_Sensor'.c Sensors/Tether_Communication_Sensor'.h)
add_executable(ET-Sat ${SOURCE_FILES})
