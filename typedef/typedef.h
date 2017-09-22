#ifndef _TYPEDEFS_H_
#define _TYPEDEFS_H_


//==============================================================================
// General purpose typedef's
//==============================================================================
//typedef enum _BOOL { FALSE = 0, TRUE } BOOL;
typedef unsigned char Bool;
typedef unsigned char Byte;
typedef unsigned int Word;
typedef unsigned long Dword;
typedef union _BYTE_VAL
{
    struct
    {
        unsigned int b0:1;
        unsigned int b1:1;
        unsigned int b2:1;
        unsigned int b3:1;
        unsigned int b4:1;
        unsigned int b5:1;
        unsigned int b6:1;
        unsigned int b7:1;
    } bits;
    Byte Val;
} Byte_val;


//==============================================================================
// Constants
//==============================================================================
#ifndef YES
#define YES  1
#endif

#ifndef NO
#define NO  0
#endif

#ifndef OFF
#define OFF  0
#endif

#ifndef ON
#define ON  1
#endif

#ifndef TRUE
#define TRUE  1
#endif

#ifndef FALSE
#define FALSE 0
#endif

#ifndef HIGH
#define HIGH  1
#endif

#ifndef LOW
#define LOW 0
#endif

#ifndef ENABLE
#define ENABLE  1
#endif

#ifndef DISABLE
#define DISABLE  0
#endif

#ifndef ENABLED
#define ENABLED  1
#endif

#ifndef DISABLED
#define DISABLED 0
#endif

#ifndef SET
#define SET  1
#endif

#ifndef CLEAR
#define CLEAR 0
#endif

#ifndef SCH_END  //I added this definition myself....
#define SCH_END 0
#endif

#ifndef NULL
#define NULL  (0)
#endif  /* NULL */

#define _56_KHZ  143


#endif // _TYPEDEFS_H_
