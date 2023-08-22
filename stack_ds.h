/**
 * @file    : stack_ds.c
 * @brief   : Stack Ds based on array.
 * @date    : 22 AUG 2023
 * @details : This file contains the definition of library functions.
 * @author  : Ahmed Hani Atef
*/

#ifndef _STACK_DS_H
#define _STACK_DS_H

/********************** Start of linking section **********************/
#include "stack_platform.h"
/*********************** End of linking section ***********************/

/******************** Start of definition section *********************/
#define DEBUG_STATUS (0)
#define STK_PTR_INIT (-1)

static uint32_t current_size = ZERO;
/********************* End of linking definition **********************/

/*************** Start of functions declaration section ***************/

typedef struct stack
{
    sint32_t *stack_ds_data;
    sint32_t stack_ds_pointer;
}stack_ds;

typedef enum stack_size
{
    STACK_FULL,
    STACK_EMPTY,
    STACK_NOT_FULL
}stack_ds_ret_size;

/**
 * @brief  pushing a value to stack 
 * @param  my_stack a pointer to the top of stack
 * @param  value a variable to be pushed in the stack
 * @retval a status of stack_ds_push
 */
ret_status stack_ds_push (stack_ds *my_stack , uint32_t value);

/**
 * @brief  popping a value from stack 
 * @param  my_stack a pointer to the top of stack
 * @param  value a pointer to variable whish will stores the popped value
 * @retval a status of stack_ds_push
 */
ret_status stack_ds_pop (stack_ds *my_stack , uint32_t *value);

/**
 * @brief  returning the the top of stack value
 * @param  my_stack a pointer to the top of stack
 * @param  value a pointer to variable whish will stores the top of stack
 * @retval a status of stack_ds_push
 */
ret_status stack_ds_top (stack_ds *my_stack , uint32_t *value);

/**
 * @brief  return the size of the stack
 * @param  my_stack a pointer to the top of stack
 * @param  value a pointer to variable whish will stores the size of stack;
 * @retval a status of stack_ds_push
 */
ret_status stack_ds_size (stack_ds *my_stack , uint32_t *value);

/**
 * @brief  used to allocate a "size" of stack at first time then initialize the elements of stack with zero and the pointer with -1
 * @param  my_stack a pointer to the top of stack
 * @param  size variable of the size of stack after allocation
 * @retval a status of stack_ds_push
 */
ret_status stack_ds_allocation (stack_ds *my_stack , uint32_t new_size);

/**
 * @brief  used to reallocate a new size to the stack 
 * @param  my_stack a pointer to the top of stack
 * @param  new_size variable of the new size of stack after reallocation
 * @retval a status of stack_ds_push
 */
ret_status stack_ds_reallocation (stack_ds *my_stack , uint32_t new_size);

/**
 * @brief  display the values in the stack 
 * @param  my_stack a pointer to the top of stack
 * @retval a status of stack_ds_push
 */
ret_status stack_ds_display (stack_ds *my_stack);

/**************** End of functions declaration section ******************/

#endif

/*==================================================================================================
*   Revision log
    Date            By                  Description
    ------------    -----------------   ------------------------------------------------------------
    22 AUG 2023     Ahmed Hani Atef     Creating of stack_ds.c file and write functions declaration

====================================================================================================*/