cmake_minimum_required(VERSION 3.5)
project(ET-Sat)

set(CMAKE_C_STANDARD 99)

set(SOURCE_FILES Main/main.c Main/main.h
        mode_SCM/SCM.c mode_SCM/SCM.h
        mode_LVSM/LVSM.c mode_LVSM/LVSM.h
        mode_PLM/PLM.c mode_PLM/PLM.h
        mode_SMM/SMM.h mode_SMM/SMM.c
        mode_TMM/TMM.h mode_TMM/TMM.c
        Health_Safety_Check/health_safety_check.h Health_Safety_Check/health_safety_check.c)
add_executable(ET-Sat ${SOURCE_FILES})
