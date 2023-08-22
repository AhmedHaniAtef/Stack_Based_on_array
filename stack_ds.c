/**
 * @file    : stack_ds.h
 * @brief   : Stack Ds based on array.
 * @date    : 22 AUG 2023
 * @details : This file contains the declaration of library functions.
 * @author  : Ahmed Hani Atef
*/

/********************** Start of linking section **********************/
#include "stack_ds.h"
/*********************** End of linking section ***********************/

/*************** Start of functions definition section ***************/
/*
 * @brief  check if the stack is full or not 
 * @param  my_stack a pointer to the top of stack
 * @param  pointer to the the status of the stack
 * @retval a status of stack_ds_push
 */
static stack_ds_ret_size stack_ds_full (stack_ds *my_stack)
{
    stack_ds_ret_size ret = STACK_NOT_FULL;
    if (current_size == (my_stack->stack_ds_pointer)+1)
    {
        ret = STACK_FULL;
    }
    else{}
    return ret;
}

/*
 * @brief  check if the stack is empty or not 
 * @param  my_stack a pointer to the top of stack
 * @param  pointer to the the status of the stack
 * @retval a status of stack_ds_push
 */
static stack_ds_ret_size stack_ds_empty (stack_ds *my_stack)
{
    stack_ds_ret_size ret = STACK_NOT_FULL;
    if (-1 == (my_stack->stack_ds_pointer)-1)
    {
        ret = STACK_EMPTY;
    }
    else{}
    return ret;
    
}

/*
 * @brief  pushing a value to stack 
 * @param  my_stack a pointer to the top of stack
 * @param  value a variable to be pushed in the stack
 * @retval a status of stack_ds_push
 */
ret_status stack_ds_push (stack_ds *my_stack , uint32_t value)
{
    ret_status ret = R_NOK;
    if ((NULL == my_stack) || (STACK_FULL == stack_ds_full(my_stack)))
    {
        ret = R_NOK;
        #if DEBUG_STATUS
        printf("Can not puss any value to the stack!!");
        #endif
    }
    else
    {
        (my_stack->stack_ds_pointer)++;
        *((my_stack->stack_ds_data) + (my_stack->stack_ds_pointer)) = value;
        ret = R_OK;
    }
    return ret;
}

/*
 * @brief  popping a value from stack 
 * @param  my_stack a pointer to the top of stack
 * @param  value a pointer to variable whish will stores the popped value
 * @retval a status of stack_ds_push
 */
ret_status stack_ds_pop (stack_ds *my_stack , uint32_t *value)
{
    ret_status ret = R_NOK;
    if ((NULL == my_stack) || (NULL == value) || (STACK_EMPTY == stack_ds_empty(my_stack)))
    {
        ret = R_NOK;
        #if DEBUG_STATUS
        printf("Can not pop any value from the stack!!");
        #endif
    }
    else
    {
        *value =  *((my_stack->stack_ds_data) + (my_stack->stack_ds_pointer));
        (my_stack->stack_ds_pointer)--;
        ret = R_OK;
    }
    return ret;
}

/*
 * @brief  returning the the top of stack value
 * @param  my_stack a pointer to the top of stack
 * @param  value a pointer to variable whish will stores the top of stack
 * @retval a status of stack_ds_push
 */
ret_status stack_ds_top (stack_ds *my_stack , uint32_t *value)
{
    ret_status ret = R_NOK;
    if ((NULL == my_stack) || (NULL == value) || (STACK_EMPTY == stack_ds_empty(my_stack)))
    {
        ret = R_NOK;
        #if DEBUG_STATUS
        printf("Can not find the top of th stack!!");
        #endif
    }
    else
    {
        *value =  *((my_stack->stack_ds_data) + (my_stack->stack_ds_pointer));
        ret = R_OK;
    }
    return ret;
}

/*
 * @brief  return the size of the stack
 * @param  my_stack a pointer to the top of stack
 * @param  value a pointer to variable whish will stores the size of stack;
 * @retval a status of stack_ds_push
 */
ret_status stack_ds_size (stack_ds *my_stack , uint32_t *value)
{
    ret_status ret = R_NOK;
    if ((NULL == my_stack) || (NULL == value) || (STACK_EMPTY == stack_ds_empty(my_stack)))
    {
        ret = R_NOK;
        #if DEBUG_STATUS
        printf("Can not find the size of the stack!!");
        #endif
    }
    else
    {
        
        *value = current_size;
        ret = R_OK;
    }
    return ret;
}

/*
 * @brief  used to allocate a "size" of stack at first time then initialize the elements of stack with zero and the pointer with -1
 * @param  my_stack a pointer to the top of stack
 * @param  size variable of the size of stack after allocation
 * @retval a status of stack_ds_push
 */
ret_status stack_ds_allocation (stack_ds *my_stack , uint32_t size)
{
    ret_status ret = R_NOK;
    if (NULL == my_stack)
    {
        ret = R_NOK;
        #if DEBUG_STATUS
        printf("Can not allocate memory for the stack!!");
        #endif
    }
    else
    {
        sint32_t counter = ZERO;
        current_size = size;

        (my_stack->stack_ds_data) = (sint32_t *)malloc(size * sizeof(sint32_t));
        
        my_stack->stack_ds_pointer = STK_PTR_INIT ;
        for (counter = ZERO ; counter < size ; counter ++)
        {
            *((my_stack->stack_ds_data) + counter) = ZERO ;
        }
        ret = R_OK;
    }
    return ret;
}

/*
 * @brief  used to reallocate a new size to the stack
 * @param  my_stack a pointer to the top of stack
 * @param  new_size variable of the new size of stack after reallocation
 * @retval a status of stack_ds_push
 */
ret_status stack_ds_reallocation (stack_ds *my_stack , uint32_t new_size)
{
    ret_status ret = R_NOK;
    if (NULL == my_stack)
    {
        ret = R_NOK;
        #if DEBUG_STATUS
        printf("Can not reallocate more memory for the stack!!");
        #endif
    }
    else
    {
        sint32_t counter = ZERO;
        current_size = new_size;

        (my_stack->stack_ds_data) = (sint32_t *)realloc((my_stack->stack_ds_data),new_size * sizeof(sint32_t));
        
        for (counter = (my_stack->stack_ds_pointer + 1) ; counter < new_size ; counter ++)
        {
            *((my_stack->stack_ds_data) + counter) = ZERO ;
        }
        ret = R_OK;
    }
    return ret;
}

/*
 * @brief  display the values in the stack 
 * @param  my_stack a pointer to the top of stack
 * @retval a status of stack_ds_push
 */
ret_status stack_ds_display (stack_ds *my_stack)
{
    ret_status ret = R_NOK;
    if (NULL == my_stack)
    {
        ret = R_NOK;
        #if DEBUG_STATUS
        printf("Can not display the stack!!");
        #endif
    }
    else
    {
        sint32_t counter = ZERO;
        
        printf("Stack data : ");
        for (counter = ZERO ; counter <= (my_stack->stack_ds_pointer) ; counter ++)
        {
            printf("%i    ",*((my_stack->stack_ds_data) + counter));
        }
        printf("\n");
        ret = R_OK;
    }
    return ret;
}

/**************** End of functions definition section ******************/


/*==================================================================================================
*   Revision log
    Date            By                  Description
    ------------    -----------------   ------------------------------------------------------------
    22 AUG 2023     Ahmed Hani Atef     Creating of stack_ds.c file and write functions definitions

====================================================================================================*/