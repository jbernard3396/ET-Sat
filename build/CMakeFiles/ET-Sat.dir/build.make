# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.5

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:


# Remove some rules from gmake that .SUFFIXES does not remove.
SUFFIXES =

.SUFFIXES: .hpux_make_needs_suffix_list


# Suppress display of executed commands.
$(VERBOSE).SILENT:


# A target that is always out of date.
cmake_force:

.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/CS/users/hdeng/.linux/Desktop/Documents/ThinSAT

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/CS/users/hdeng/.linux/Desktop/Documents/ThinSAT/build

# Include any dependencies generated for this target.
include CMakeFiles/ET-Sat.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/ET-Sat.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/ET-Sat.dir/flags.make

CMakeFiles/ET-Sat.dir/Main/main.c.o: CMakeFiles/ET-Sat.dir/flags.make
CMakeFiles/ET-Sat.dir/Main/main.c.o: ../Main/main.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/CS/users/hdeng/.linux/Desktop/Documents/ThinSAT/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/ET-Sat.dir/Main/main.c.o"
	/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/ET-Sat.dir/Main/main.c.o   -c /home/CS/users/hdeng/.linux/Desktop/Documents/ThinSAT/Main/main.c

CMakeFiles/ET-Sat.dir/Main/main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/ET-Sat.dir/Main/main.c.i"
	/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/CS/users/hdeng/.linux/Desktop/Documents/ThinSAT/Main/main.c > CMakeFiles/ET-Sat.dir/Main/main.c.i

CMakeFiles/ET-Sat.dir/Main/main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/ET-Sat.dir/Main/main.c.s"
	/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/CS/users/hdeng/.linux/Desktop/Documents/ThinSAT/Main/main.c -o CMakeFiles/ET-Sat.dir/Main/main.c.s

CMakeFiles/ET-Sat.dir/Main/main.c.o.requires:

.PHONY : CMakeFiles/ET-Sat.dir/Main/main.c.o.requires

CMakeFiles/ET-Sat.dir/Main/main.c.o.provides: CMakeFiles/ET-Sat.dir/Main/main.c.o.requires
	$(MAKE) -f CMakeFiles/ET-Sat.dir/build.make CMakeFiles/ET-Sat.dir/Main/main.c.o.provides.build
.PHONY : CMakeFiles/ET-Sat.dir/Main/main.c.o.provides

CMakeFiles/ET-Sat.dir/Main/main.c.o.provides.build: CMakeFiles/ET-Sat.dir/Main/main.c.o


CMakeFiles/ET-Sat.dir/mode_SCM/SCM.c.o: CMakeFiles/ET-Sat.dir/flags.make
CMakeFiles/ET-Sat.dir/mode_SCM/SCM.c.o: ../mode_SCM/SCM.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/CS/users/hdeng/.linux/Desktop/Documents/ThinSAT/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building C object CMakeFiles/ET-Sat.dir/mode_SCM/SCM.c.o"
	/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/ET-Sat.dir/mode_SCM/SCM.c.o   -c /home/CS/users/hdeng/.linux/Desktop/Documents/ThinSAT/mode_SCM/SCM.c

CMakeFiles/ET-Sat.dir/mode_SCM/SCM.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/ET-Sat.dir/mode_SCM/SCM.c.i"
	/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/CS/users/hdeng/.linux/Desktop/Documents/ThinSAT/mode_SCM/SCM.c > CMakeFiles/ET-Sat.dir/mode_SCM/SCM.c.i

CMakeFiles/ET-Sat.dir/mode_SCM/SCM.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/ET-Sat.dir/mode_SCM/SCM.c.s"
	/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/CS/users/hdeng/.linux/Desktop/Documents/ThinSAT/mode_SCM/SCM.c -o CMakeFiles/ET-Sat.dir/mode_SCM/SCM.c.s

CMakeFiles/ET-Sat.dir/mode_SCM/SCM.c.o.requires:

.PHONY : CMakeFiles/ET-Sat.dir/mode_SCM/SCM.c.o.requires

CMakeFiles/ET-Sat.dir/mode_SCM/SCM.c.o.provides: CMakeFiles/ET-Sat.dir/mode_SCM/SCM.c.o.requires
	$(MAKE) -f CMakeFiles/ET-Sat.dir/build.make CMakeFiles/ET-Sat.dir/mode_SCM/SCM.c.o.provides.build
.PHONY : CMakeFiles/ET-Sat.dir/mode_SCM/SCM.c.o.provides

CMakeFiles/ET-Sat.dir/mode_SCM/SCM.c.o.provides.build: CMakeFiles/ET-Sat.dir/mode_SCM/SCM.c.o


CMakeFiles/ET-Sat.dir/mode_SMM/SMM.c.o: CMakeFiles/ET-Sat.dir/flags.make
CMakeFiles/ET-Sat.dir/mode_SMM/SMM.c.o: ../mode_SMM/SMM.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/CS/users/hdeng/.linux/Desktop/Documents/ThinSAT/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building C object CMakeFiles/ET-Sat.dir/mode_SMM/SMM.c.o"
	/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/ET-Sat.dir/mode_SMM/SMM.c.o   -c /home/CS/users/hdeng/.linux/Desktop/Documents/ThinSAT/mode_SMM/SMM.c

CMakeFiles/ET-Sat.dir/mode_SMM/SMM.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/ET-Sat.dir/mode_SMM/SMM.c.i"
	/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/CS/users/hdeng/.linux/Desktop/Documents/ThinSAT/mode_SMM/SMM.c > CMakeFiles/ET-Sat.dir/mode_SMM/SMM.c.i

CMakeFiles/ET-Sat.dir/mode_SMM/SMM.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/ET-Sat.dir/mode_SMM/SMM.c.s"
	/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/CS/users/hdeng/.linux/Desktop/Documents/ThinSAT/mode_SMM/SMM.c -o CMakeFiles/ET-Sat.dir/mode_SMM/SMM.c.s

CMakeFiles/ET-Sat.dir/mode_SMM/SMM.c.o.requires:

.PHONY : CMakeFiles/ET-Sat.dir/mode_SMM/SMM.c.o.requires

CMakeFiles/ET-Sat.dir/mode_SMM/SMM.c.o.provides: CMakeFiles/ET-Sat.dir/mode_SMM/SMM.c.o.requires
	$(MAKE) -f CMakeFiles/ET-Sat.dir/build.make CMakeFiles/ET-Sat.dir/mode_SMM/SMM.c.o.provides.build
.PHONY : CMakeFiles/ET-Sat.dir/mode_SMM/SMM.c.o.provides

CMakeFiles/ET-Sat.dir/mode_SMM/SMM.c.o.provides.build: CMakeFiles/ET-Sat.dir/mode_SMM/SMM.c.o


CMakeFiles/ET-Sat.dir/mode_TMM/TMM.c.o: CMakeFiles/ET-Sat.dir/flags.make
CMakeFiles/ET-Sat.dir/mode_TMM/TMM.c.o: ../mode_TMM/TMM.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/CS/users/hdeng/.linux/Desktop/Documents/ThinSAT/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building C object CMakeFiles/ET-Sat.dir/mode_TMM/TMM.c.o"
	/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/ET-Sat.dir/mode_TMM/TMM.c.o   -c /home/CS/users/hdeng/.linux/Desktop/Documents/ThinSAT/mode_TMM/TMM.c

CMakeFiles/ET-Sat.dir/mode_TMM/TMM.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/ET-Sat.dir/mode_TMM/TMM.c.i"
	/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/CS/users/hdeng/.linux/Desktop/Documents/ThinSAT/mode_TMM/TMM.c > CMakeFiles/ET-Sat.dir/mode_TMM/TMM.c.i

CMakeFiles/ET-Sat.dir/mode_TMM/TMM.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/ET-Sat.dir/mode_TMM/TMM.c.s"
	/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/CS/users/hdeng/.linux/Desktop/Documents/ThinSAT/mode_TMM/TMM.c -o CMakeFiles/ET-Sat.dir/mode_TMM/TMM.c.s

CMakeFiles/ET-Sat.dir/mode_TMM/TMM.c.o.requires:

.PHONY : CMakeFiles/ET-Sat.dir/mode_TMM/TMM.c.o.requires

CMakeFiles/ET-Sat.dir/mode_TMM/TMM.c.o.provides: CMakeFiles/ET-Sat.dir/mode_TMM/TMM.c.o.requires
	$(MAKE) -f CMakeFiles/ET-Sat.dir/build.make CMakeFiles/ET-Sat.dir/mode_TMM/TMM.c.o.provides.build
.PHONY : CMakeFiles/ET-Sat.dir/mode_TMM/TMM.c.o.provides

CMakeFiles/ET-Sat.dir/mode_TMM/TMM.c.o.provides.build: CMakeFiles/ET-Sat.dir/mode_TMM/TMM.c.o


CMakeFiles/ET-Sat.dir/Sensors/Light_Sensor.c.o: CMakeFiles/ET-Sat.dir/flags.make
CMakeFiles/ET-Sat.dir/Sensors/Light_Sensor.c.o: ../Sensors/Light_Sensor.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/CS/users/hdeng/.linux/Desktop/Documents/ThinSAT/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building C object CMakeFiles/ET-Sat.dir/Sensors/Light_Sensor.c.o"
	/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/ET-Sat.dir/Sensors/Light_Sensor.c.o   -c /home/CS/users/hdeng/.linux/Desktop/Documents/ThinSAT/Sensors/Light_Sensor.c

CMakeFiles/ET-Sat.dir/Sensors/Light_Sensor.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/ET-Sat.dir/Sensors/Light_Sensor.c.i"
	/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/CS/users/hdeng/.linux/Desktop/Documents/ThinSAT/Sensors/Light_Sensor.c > CMakeFiles/ET-Sat.dir/Sensors/Light_Sensor.c.i

CMakeFiles/ET-Sat.dir/Sensors/Light_Sensor.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/ET-Sat.dir/Sensors/Light_Sensor.c.s"
	/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/CS/users/hdeng/.linux/Desktop/Documents/ThinSAT/Sensors/Light_Sensor.c -o CMakeFiles/ET-Sat.dir/Sensors/Light_Sensor.c.s

CMakeFiles/ET-Sat.dir/Sensors/Light_Sensor.c.o.requires:

.PHONY : CMakeFiles/ET-Sat.dir/Sensors/Light_Sensor.c.o.requires

CMakeFiles/ET-Sat.dir/Sensors/Light_Sensor.c.o.provides: CMakeFiles/ET-Sat.dir/Sensors/Light_Sensor.c.o.requires
	$(MAKE) -f CMakeFiles/ET-Sat.dir/build.make CMakeFiles/ET-Sat.dir/Sensors/Light_Sensor.c.o.provides.build
.PHONY : CMakeFiles/ET-Sat.dir/Sensors/Light_Sensor.c.o.provides

CMakeFiles/ET-Sat.dir/Sensors/Light_Sensor.c.o.provides.build: CMakeFiles/ET-Sat.dir/Sensors/Light_Sensor.c.o


CMakeFiles/ET-Sat.dir/Sensors/Rotation_Sensor.c.o: CMakeFiles/ET-Sat.dir/flags.make
CMakeFiles/ET-Sat.dir/Sensors/Rotation_Sensor.c.o: ../Sensors/Rotation_Sensor.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/CS/users/hdeng/.linux/Desktop/Documents/ThinSAT/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building C object CMakeFiles/ET-Sat.dir/Sensors/Rotation_Sensor.c.o"
	/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/ET-Sat.dir/Sensors/Rotation_Sensor.c.o   -c /home/CS/users/hdeng/.linux/Desktop/Documents/ThinSAT/Sensors/Rotation_Sensor.c

CMakeFiles/ET-Sat.dir/Sensors/Rotation_Sensor.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/ET-Sat.dir/Sensors/Rotation_Sensor.c.i"
	/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/CS/users/hdeng/.linux/Desktop/Documents/ThinSAT/Sensors/Rotation_Sensor.c > CMakeFiles/ET-Sat.dir/Sensors/Rotation_Sensor.c.i

CMakeFiles/ET-Sat.dir/Sensors/Rotation_Sensor.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/ET-Sat.dir/Sensors/Rotation_Sensor.c.s"
	/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/CS/users/hdeng/.linux/Desktop/Documents/ThinSAT/Sensors/Rotation_Sensor.c -o CMakeFiles/ET-Sat.dir/Sensors/Rotation_Sensor.c.s

CMakeFiles/ET-Sat.dir/Sensors/Rotation_Sensor.c.o.requires:

.PHONY : CMakeFiles/ET-Sat.dir/Sensors/Rotation_Sensor.c.o.requires

CMakeFiles/ET-Sat.dir/Sensors/Rotation_Sensor.c.o.provides: CMakeFiles/ET-Sat.dir/Sensors/Rotation_Sensor.c.o.requires
	$(MAKE) -f CMakeFiles/ET-Sat.dir/build.make CMakeFiles/ET-Sat.dir/Sensors/Rotation_Sensor.c.o.provides.build
.PHONY : CMakeFiles/ET-Sat.dir/Sensors/Rotation_Sensor.c.o.provides

CMakeFiles/ET-Sat.dir/Sensors/Rotation_Sensor.c.o.provides.build: CMakeFiles/ET-Sat.dir/Sensors/Rotation_Sensor.c.o


CMakeFiles/ET-Sat.dir/Sensors/Em_Sensor.c.o: CMakeFiles/ET-Sat.dir/flags.make
CMakeFiles/ET-Sat.dir/Sensors/Em_Sensor.c.o: ../Sensors/Em_Sensor.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/CS/users/hdeng/.linux/Desktop/Documents/ThinSAT/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Building C object CMakeFiles/ET-Sat.dir/Sensors/Em_Sensor.c.o"
	/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/ET-Sat.dir/Sensors/Em_Sensor.c.o   -c /home/CS/users/hdeng/.linux/Desktop/Documents/ThinSAT/Sensors/Em_Sensor.c

CMakeFiles/ET-Sat.dir/Sensors/Em_Sensor.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/ET-Sat.dir/Sensors/Em_Sensor.c.i"
	/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/CS/users/hdeng/.linux/Desktop/Documents/ThinSAT/Sensors/Em_Sensor.c > CMakeFiles/ET-Sat.dir/Sensors/Em_Sensor.c.i

CMakeFiles/ET-Sat.dir/Sensors/Em_Sensor.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/ET-Sat.dir/Sensors/Em_Sensor.c.s"
	/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/CS/users/hdeng/.linux/Desktop/Documents/ThinSAT/Sensors/Em_Sensor.c -o CMakeFiles/ET-Sat.dir/Sensors/Em_Sensor.c.s

CMakeFiles/ET-Sat.dir/Sensors/Em_Sensor.c.o.requires:

.PHONY : CMakeFiles/ET-Sat.dir/Sensors/Em_Sensor.c.o.requires

CMakeFiles/ET-Sat.dir/Sensors/Em_Sensor.c.o.provides: CMakeFiles/ET-Sat.dir/Sensors/Em_Sensor.c.o.requires
	$(MAKE) -f CMakeFiles/ET-Sat.dir/build.make CMakeFiles/ET-Sat.dir/Sensors/Em_Sensor.c.o.provides.build
.PHONY : CMakeFiles/ET-Sat.dir/Sensors/Em_Sensor.c.o.provides

CMakeFiles/ET-Sat.dir/Sensors/Em_Sensor.c.o.provides.build: CMakeFiles/ET-Sat.dir/Sensors/Em_Sensor.c.o


CMakeFiles/ET-Sat.dir/Sensors/Tether_Communication_Sensor'.c.o: CMakeFiles/ET-Sat.dir/flags.make
CMakeFiles/ET-Sat.dir/Sensors/Tether_Communication_Sensor'.c.o: ../Sensors/Tether_Communication_Sensor'.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/CS/users/hdeng/.linux/Desktop/Documents/ThinSAT/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_8) "Building C object CMakeFiles/ET-Sat.dir/Sensors/Tether_Communication_Sensor'.c.o"
	/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o "CMakeFiles/ET-Sat.dir/Sensors/Tether_Communication_Sensor'.c.o"   -c "/home/CS/users/hdeng/.linux/Desktop/Documents/ThinSAT/Sensors/Tether_Communication_Sensor'.c"

CMakeFiles/ET-Sat.dir/Sensors/Tether_Communication_Sensor'.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/ET-Sat.dir/Sensors/Tether_Communication_Sensor'.c.i"
	/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E "/home/CS/users/hdeng/.linux/Desktop/Documents/ThinSAT/Sensors/Tether_Communication_Sensor'.c" > "CMakeFiles/ET-Sat.dir/Sensors/Tether_Communication_Sensor'.c.i"

CMakeFiles/ET-Sat.dir/Sensors/Tether_Communication_Sensor'.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/ET-Sat.dir/Sensors/Tether_Communication_Sensor'.c.s"
	/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S "/home/CS/users/hdeng/.linux/Desktop/Documents/ThinSAT/Sensors/Tether_Communication_Sensor'.c" -o "CMakeFiles/ET-Sat.dir/Sensors/Tether_Communication_Sensor'.c.s"

CMakeFiles/ET-Sat.dir/Sensors/Tether_Communication_Sensor'.c.o.requires:

.PHONY : CMakeFiles/ET-Sat.dir/Sensors/Tether_Communication_Sensor'.c.o.requires

CMakeFiles/ET-Sat.dir/Sensors/Tether_Communication_Sensor'.c.o.provides: CMakeFiles/ET-Sat.dir/Sensors/Tether_Communication_Sensor'.c.o.requires
	$(MAKE) -f CMakeFiles/ET-Sat.dir/build.make "CMakeFiles/ET-Sat.dir/Sensors/Tether_Communication_Sensor'.c.o.provides.build"
.PHONY : CMakeFiles/ET-Sat.dir/Sensors/Tether_Communication_Sensor'.c.o.provides

CMakeFiles/ET-Sat.dir/Sensors/Tether_Communication_Sensor'.c.o.provides.build: CMakeFiles/ET-Sat.dir/Sensors/Tether_Communication_Sensor'.c.o


# Object files for target ET-Sat
ET__Sat_OBJECTS = \
"CMakeFiles/ET-Sat.dir/Main/main.c.o" \
"CMakeFiles/ET-Sat.dir/mode_SCM/SCM.c.o" \
"CMakeFiles/ET-Sat.dir/mode_SMM/SMM.c.o" \
"CMakeFiles/ET-Sat.dir/mode_TMM/TMM.c.o" \
"CMakeFiles/ET-Sat.dir/Sensors/Light_Sensor.c.o" \
"CMakeFiles/ET-Sat.dir/Sensors/Rotation_Sensor.c.o" \
"CMakeFiles/ET-Sat.dir/Sensors/Em_Sensor.c.o" \
"CMakeFiles/ET-Sat.dir/Sensors/Tether_Communication_Sensor'.c.o"

# External object files for target ET-Sat
ET__Sat_EXTERNAL_OBJECTS =

ET-Sat: CMakeFiles/ET-Sat.dir/Main/main.c.o
ET-Sat: CMakeFiles/ET-Sat.dir/mode_SCM/SCM.c.o
ET-Sat: CMakeFiles/ET-Sat.dir/mode_SMM/SMM.c.o
ET-Sat: CMakeFiles/ET-Sat.dir/mode_TMM/TMM.c.o
ET-Sat: CMakeFiles/ET-Sat.dir/Sensors/Light_Sensor.c.o
ET-Sat: CMakeFiles/ET-Sat.dir/Sensors/Rotation_Sensor.c.o
ET-Sat: CMakeFiles/ET-Sat.dir/Sensors/Em_Sensor.c.o
ET-Sat: CMakeFiles/ET-Sat.dir/Sensors/Tether_Communication_Sensor'.c.o
ET-Sat: CMakeFiles/ET-Sat.dir/build.make
ET-Sat: CMakeFiles/ET-Sat.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/CS/users/hdeng/.linux/Desktop/Documents/ThinSAT/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_9) "Linking C executable ET-Sat"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/ET-Sat.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/ET-Sat.dir/build: ET-Sat

.PHONY : CMakeFiles/ET-Sat.dir/build

CMakeFiles/ET-Sat.dir/requires: CMakeFiles/ET-Sat.dir/Main/main.c.o.requires
CMakeFiles/ET-Sat.dir/requires: CMakeFiles/ET-Sat.dir/mode_SCM/SCM.c.o.requires
CMakeFiles/ET-Sat.dir/requires: CMakeFiles/ET-Sat.dir/mode_SMM/SMM.c.o.requires
CMakeFiles/ET-Sat.dir/requires: CMakeFiles/ET-Sat.dir/mode_TMM/TMM.c.o.requires
CMakeFiles/ET-Sat.dir/requires: CMakeFiles/ET-Sat.dir/Sensors/Light_Sensor.c.o.requires
CMakeFiles/ET-Sat.dir/requires: CMakeFiles/ET-Sat.dir/Sensors/Rotation_Sensor.c.o.requires
CMakeFiles/ET-Sat.dir/requires: CMakeFiles/ET-Sat.dir/Sensors/Em_Sensor.c.o.requires
CMakeFiles/ET-Sat.dir/requires: CMakeFiles/ET-Sat.dir/Sensors/Tether_Communication_Sensor'.c.o.requires

.PHONY : CMakeFiles/ET-Sat.dir/requires

CMakeFiles/ET-Sat.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/ET-Sat.dir/cmake_clean.cmake
.PHONY : CMakeFiles/ET-Sat.dir/clean

CMakeFiles/ET-Sat.dir/depend:
	cd /home/CS/users/hdeng/.linux/Desktop/Documents/ThinSAT/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/CS/users/hdeng/.linux/Desktop/Documents/ThinSAT /home/CS/users/hdeng/.linux/Desktop/Documents/ThinSAT /home/CS/users/hdeng/.linux/Desktop/Documents/ThinSAT/build /home/CS/users/hdeng/.linux/Desktop/Documents/ThinSAT/build /home/CS/users/hdeng/.linux/Desktop/Documents/ThinSAT/build/CMakeFiles/ET-Sat.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/ET-Sat.dir/depend

