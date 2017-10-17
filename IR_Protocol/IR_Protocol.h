//IR_Protocol.h
#ifndef _IR_PROTOCOL_H_
#define _IR_PROTOCOL_H_

#ifdef __cplusplus
extern "C" {
#endif

//Other files that this file relies on...
#include "../systmr/systmr.h"
#include "../typedef/typedef.h"
#include "../io/io.h"
#include "../timer3/timer3.h"

//#include <avr/io.h>
//#include <avr/interrupt.h>

//IR Communication System Characteristics
#define ERROR_MARGIN 15
#define NUMBER_OF_ATTEMPTS 3
#define ISR_TIMEOUT_AMOUNT 500 //determined in miliseconds

//Special Message Definitions
#define RESEND_REQUEST     0xFF
#define NO_NEW_MESSAGE     0xCC
#define RECEIVE_SUCCESSFUL 0xFC
#define ERROR              100 //In this case, an error occurs when a hex value that is not defined is received


typedef enum {
    //a list of hex values to send via the IR communication system.
    //Each value is defined with a length of time (in ms) that the transmitter shall be turned on for.

    preamble_Length = 295,
    intermittent_Delay_Length = 50,
    end_Transmission_Length = 105,
    error_transmission_Length = 255,

    hex_Value_0_Length = 50,
    hex_Value_1_Length = 80,
    hex_Value_2_Length = 120,
    hex_Value_3_Length = 150,
    hex_Value_4_Length = 180,
    hex_Value_5_Length = 210,
    hex_Value_6_Length = 240,
    hex_Value_7_Length = 270,
    hex_Value_8_Length = 300,
    hex_Value_9_Length = 310,
    hex_Value_a_Length = 340,
    hex_Value_b_Length = 370,
    hex_Value_c_Length = 400,
    hex_Value_d_Length = 430,
    hex_Value_e_Length = 460,
    hex_Value_f_Length = 490

} Communication_Value;

typedef struct {
    //this structure will contain the packet that will be sent over the IR communication line.
    //Each message will consist of a preamble, two hex values of data (which is a total of one byte), followed by end of transmission

    Communication_Value preamble;
    Communication_Value data_1;
    Communication_Value data_2;
    Communication_Value end_Transmission;
    Communication_Value delay;

} Data_Packet;


void IR_Communication_System_Init(SysTmr_GetTicksFunc_hook_t getticks_func);

Communication_Value get_Hex_Value_Length(char data);

Bool isMessageExecuted(void);

void setMessageAsExecuted(void);

void send_Message(char data);

Bool send_Message_wait_for_ack(char data);

char assembleMessage(void);

char last_received_message(void);

void reset_IR_Interrupt(void);

Bool is_ISR_timed_out(void);

char IR_checkForNewMessage(void);

void send_Acknowledgement(void);


#ifdef __cplusplus
}
#endif

#endif // _IR_PROTOCOL_H_
