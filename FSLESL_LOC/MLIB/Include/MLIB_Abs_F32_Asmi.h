/*******************************************************************************
*
* Copyright 2007-2015 Freescale Semiconductor, Inc.
*
* This software is owned or controlled by Freescale Semiconductor.
* Use of this software is governed by the Freescale License
* distributed with this Material.
* See the LICENSE file distributed for more details.
* 
*
****************************************************************************//*!
*
* @brief  Absolute Value
* 
*******************************************************************************/
#ifndef _MLIB_ABS_F32_ASM_H_
#define _MLIB_ABS_F32_ASM_H_

#if defined(__cplusplus)
extern "C" {
#endif

/*******************************************************************************
* Includes
*******************************************************************************/
#include "mlib_types.h"

/*******************************************************************************
* Macros 
*******************************************************************************/
#define MLIB_AbsSat_F32_Asmi(f32Val) MLIB_AbsSat_F32_FAsmi(f32Val)

/***************************************************************************//*!
*  Absolute value saturated
*  Output = |f32In|
*******************************************************************************/  
static inline frac32_t MLIB_AbsSat_F32_FAsmi(register frac32_t f32Val)
{
    #if defined(__CC_ARM)                               /* For ARM Compiler */
        __asm volatile{ cmp f32Val, #0                  /* Compares f32Val with 0 */
                        bge AbsEnd                      /* If f32Val >= 0, then goes to AbsEnd */
                        rsbs f32Val, f32Val, #0         /* If f32Val < 0, then f32Val = 0 - f32Val */
                        bpl AbsEnd                      /* If f32Val >= 0, then goes to AbsEnd */
                        subs f32Val, f32Val, #1         /* If f32Val = 0x80000000, f32Val = 0x7FFFFFFF */
                    AbsEnd: };
    #else
        __asm volatile(
                        #if defined(__GNUC__)           /* For GCC compiler */
                            ".syntax unified \n"        /* Using unified asm syntax */
                        #endif
                        "cmp %0, #0 \n"                 /* Compares f32Val with 0 */
                        "bge .+8 \n"                    /* If f32Val >= 0, then jumps through three commands */
                        "rsbs %0, %0, #0 \n"            /* If f32Val < 0, then f32Val = 0 - f32Val */
                        "bpl .+4 \n"                    /* If f32Val >= 0, then jumps through next command */
                        "subs %0, %0, #1 \n"            /* If f32Val = 0x80000000, f32Val = 0x7FFFFFFF */
                        #if defined(__GNUC__)           /* For GCC compiler */
                            ".syntax divided \n"
                        #endif
                        : "+l"(f32Val):);
    #endif

    return f32Val;
}

#if defined(__cplusplus)
}
#endif

#endif  /* _MLIB_ABS_F32_ASM_H_*/
