#ifndef _IR_PROTOCOL_SENDBITS_H_
#define _IR_PROTOCOL_SENDBITS_H_

//Other files that this file relies on...
#include "../systmr/systmr.h"
#include "../typedef/typedef.h"
#include "../io/io.h"
#include "../timer3/timer3.h"

//standard avr libraries...
#include <avr/io.h>
#include <avr/interrupt.h>
#include <string.h>

//IR Communication System Characteristics
#define ERROR_MARGIN 2 /*This will be used to define the the timer error. This will take into consideration any unknowns that may occur*/
#define NUMBER_OF_ATTEMPTS 10 /*After an ack is not received, how many attempts do we want to make before we give up on communication*/
#define ISR_TIMEOUT_AMOUNT 100 /*determined in miliseconds - this will decide how long we wait to reset the ISR if an error occurs. */
#define END_OF_MESSAGE_BUFFER 10
//Special Message Definitions - typically the IR is only going to send 1 Bytes worth of data
#define RESEND_REQUEST     0xFF //currently not used
#define NO_NEW_MESSAGE     0xCC
#define RECEIVE_SUCCESSFUL 0xFC
#define ERROR              100

typedef enum {
  //a list of values to send via the IR communication system.
  //Each value is defined with a length of time (in ms) that the transmitter shall be turned on for.
  //It has to be defined in multiples of 2 ms.

  preamble_Length = 10,
  intermittent_Delay_Length = 4,
  end_Transmission_Length = 14,

  bit_value_low = 2,
  bit_value_high = 6

} Communication_Value;

typedef struct {
 //this structure will contain the packet that will be sent over the IR communication line.
 //Each message will consist of a preamble, two hex values of data (which is a total of one byte), followed by end of transmission

 Communication_Value preamble;
 int data;
 Communication_Value end_Transmission;
 Communication_Value delay;

} Data_Packet;

void IR_Communication_System_Init(SysTmr_GetTicksFunc_hook_t getticks_func);
Communication_Value get_Hex_Value_Length(char data);
Bool isMessageExecuted(void);
void setMessageAsExecuted(void);
int get_bit_value_length(Bool value);
void send_Message(int data);
Bool send_Message_wait_for_ack(int data);
int assembleMessage(void);
int last_received_message(void);
void reset_IR_Interrupt(void);
Bool is_ISR_timed_out(void);
int IR_checkForNewMessage(void);
void send_Acknowledgement(void);


#endif // _IR_PROTOCOL_SENDBITS_H_
