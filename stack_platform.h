#ifndef _STACK_PLATFORM_H
#define _STACK_PLATFORM_H

#include <stdio.h>
#include <stdlib.h>

#define ZERO (0)

/********************** Start of Platform Types **********************/
typedef unsigned char   uint8_t;
typedef unsigned short  uint16_t;
typedef unsigned int    uint32_t;
typedef signed char     sint8_t;
typedef signed short    sint16_t;
typedef signed int      sint32_t;

typedef enum err 
{
    R_NOK,
    R_OK
}ret_status;

/*********************** End of Platform Types ***********************/

#endif