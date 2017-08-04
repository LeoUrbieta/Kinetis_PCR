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
* @brief  Multiply subtract with rounding
* 
*******************************************************************************/
#ifndef _MLIB_MSURND_A32_ASM_H_
#define _MLIB_MSURND_A32_ASM_H_

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
#define MLIB_MsuRnd_A32ass_Asmi(a32Accum, f16Mult1, f16Mult2) MLIB_MsuRnd_A32ass_FAsmi(a32Accum, f16Mult1, f16Mult2)
    
/***************************************************************************//*!
*
* a32Out = a32Accum - ( f16Mult1 * f16Mult2)
*
*******************************************************************************/
static inline acc32_t MLIB_MsuRnd_A32ass_FAsmi(register acc32_t a32Accum, register frac16_t f16Mult1, register frac16_t f16Mult2)
{
    #if defined(__CC_ARM)                                   /* For ARM Compiler */
        __asm volatile{ sxth f16Mult1, f16Mult1             /* Converts 16-bit input to 32-bit */
                        sxth f16Mult2, f16Mult2             /* Converts 16-bit input to 32-bit */
                        muls f16Mult1, f16Mult1, f16Mult2   /* f16Mult1 * f16Mult2 */
                        asrs f16Mult1, f16Mult1, #7         /* f16Mult1 >> 7 for fractional multiplication */
                        adds f16Mult1, f16Mult1, #128       /* Rounding */
                        asrs f16Mult1, f16Mult1, #8         /* f16Mult1 >> 8 for fractional multiplication */
                        subs a32Accum, a32Accum, f16Mult1}; /* a32Accum - f16Mult1 * f16Mult2 */
    #else
        __asm volatile(
                        #if defined(__GNUC__)               /* For GCC compiler */
                            ".syntax unified \n"            /* Using unified asm syntax */
                        #endif
                        "sxth %1, %1 \n"                    /* Converts 16-bit input to 32-bit */
                        "sxth %2, %2 \n"                    /* Converts 16-bit input to 32-bit */
                        "muls %1, %1, %2 \n"                /* f16Mult1 * f16Mult2 */
                        "asrs %1, %1, #7 \n"                /* f16Mult1 >> 7 for fractional multiplication */
                        "adds %1, %1, #128 \n"              /* Rounding */
                        "asrs %1, %1, #8 \n"                /* f16Mult1 >> 8 for fractional multiplication */
                        "subs %0, %0, %1 \n"                /* f32Accum - f16Mult1 * f16Mult2 */
                        #if defined(__GNUC__)               /* For GCC compiler */
                            ".syntax divided \n"
                        #endif
                        : "+l"(a32Accum), "+l"(f16Mult1), "+l"(f16Mult2):);
    #endif

    return a32Accum;
}

#if defined(__cplusplus)
}
#endif

#endif /* _MLIB_MSURND_A32_ASM_H_ */
