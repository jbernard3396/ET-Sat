/*
 * Written by: Eliza You and Justin Theien
 * Date: 6/26/2017
 *
 * Description: Phantom Loop Mode is one of the primary mission modes. PLM is responsible for the creation of a phantom loop and
 *              measuring its current.
 *
 */

#include "PLM.h"

//Static Global Variables-----------------------------------------------------------------------------------------------------
static int current;

//Functions-------------------------------------------------------------------------------------------------------------------
/**
 * initalizes phantom loop current
 * @return
 */
bool power_loop_on(void) {
    initialize_phantom_loop_current();
    if (current > 0) {
        get_phantom_loop_current();
        printf("Current was: %d\n", get_phantom_loop_current());
        return true;
    } else {
        return handle_phantom_loop_error();
    }
}

bool power_loop_off(void) {
    kill_current();
    if (current == 0) return true;
    return false;
}

bool handle_phantom_loop_error(void) {
    if (get_phantom_loop_current() > 0) return true; //try turning on again
    return false;
}

int get_phantom_loop_current(void) {
    return current;
}

int initialize_phantom_loop_current(void) {
    current = rand()% 100;
    return current;
}

void kill_current() { current = 0; }

void measure_current(void) {
    printf("measure_current() ");

}

char * run_plm(char * returnString){
    printf("Initalizing Phantom Loop Management\n");
	snprintf(returnString, STRINGLENGTHPLM, "\"current\":%2d", current);
    if (power_loop_on()) printf("Phantom Loop started successfully\n");
    if (power_loop_off()) printf("Phantom Loop ended successfully\n");
	return returnString;
}
