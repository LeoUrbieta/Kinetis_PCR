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
#ifndef _MLIB_ABS_F16_ASM_H_
#define _MLIB_ABS_F16_ASM_H_

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
#define MLIB_AbsSat_F16_Asmi(f16Val) MLIB_AbsSat_F16_FAsmi(f16Val)


/***************************************************************************//*!
*  Absolute value saturated
*  Output = |f16In|
*******************************************************************************/
static inline frac16_t MLIB_AbsSat_F16_FAsmi(register frac16_t f16Val)
{
    #if defined(__CC_ARM)                               /* For ARM Compiler */
        __asm volatile{ lsls f16Val, f16Val, #16        /* f16Val << 16 */
                        bpl AbsEnd                      /* If f16Val >= 0, then goes to AbsEnd */
                        rsbs f16Val, f16Val, #0         /* If f16Val < 0, then f16Val = 0 - f16Val */
                        bpl AbsEnd                      /* If f16Val >= 0, then goes to AbsEnd */
                        subs f16Val, f16Val, #1         /* If f16Val == 0xFFFF8000, f16Val = f16Val - 1 */
                    AbsEnd:
                        lsrs f16Val, f16Val, #16};      /* f16Val >> 16 */
    #else
        __asm volatile(
                        #if defined(__GNUC__)           /* For GCC compiler */
                            ".syntax unified \n"        /* Using unified asm syntax */
                        #endif
                        "lsls %0, %0, #16 \n"           /* f16Val << 16 */
                        "bpl .+8 \n"                    /* If f16Val >= 0, then jumps through three commands */
                        "rsbs %0, %0, #0 \n"            /* If f16Val < 0, then f16Val = 0 - f16Val */
                        "bpl .+4 \n"                    /* If f16Val >= 0, then jumps through next command */
                        "subs %0, %0, #1 \n"            /* If f16Val = 0x80000000, f16Val = 0x7FFFFFFF */
                        "lsrs %0, %0, #16 \n"           /* f16Val >> 16 */
                        #if defined(__GNUC__)           /* For GCC compiler */
                            ".syntax divided \n"
                        #endif
                        : "+l"(f16Val):);
    #endif

    return f16Val;
}

#if defined(__cplusplus)
}
#endif

#endif /*_MLIB_ABS_F16_ASM_H_*/
