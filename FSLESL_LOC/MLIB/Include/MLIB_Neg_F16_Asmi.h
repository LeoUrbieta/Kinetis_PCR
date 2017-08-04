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
* @brief  Negation
* 
*******************************************************************************/
#ifndef _MLIB_NEG_F16_ASM_H_
#define _MLIB_NEG_F16_ASM_H_

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
#define MLIB_NegSat_F16_Asmi(f16Val) MLIB_NegSat_F16_FAsmi(f16Val)

/***************************************************************************//*!
*
* Output = -f16Val
* With saturation
*******************************************************************************/
static inline frac16_t MLIB_NegSat_F16_FAsmi(register frac16_t f16Val)
{
	register frac32_t f32SatVal = 0x8000;
    #if defined(__CC_ARM)                               /* For ARM Compiler */
        __asm volatile{ sxth f16Val, f16Val             /* Transforms 16-bit input f16Val to 32-bit */
	                    rsbs f16Val, f16Val, #0         /* f16Val = - f16Val */
                        cmp f16Val, f32SatVal           /* Compares f16Val with 0x00008000 */
                        bne SatEnd                      /* If f32Val != 0x8000, then goes to SatEnd */
                        subs f16Val, f16Val, #1         /* Compares f16Val with 0x00008000 */
        SatEnd: };

    #else
        __asm volatile(
                        #if defined(__GNUC__)           /* For GCC compiler */
                            ".syntax unified \n"        /* Using unified asm syntax */
                        #endif
                        "sxth %0, %0 \n"                /* Transforms 16-bit input f16Val to 32-bit */
                        "rsbs %0, %0, #0 \n"            /* f16Val = - f16Val */
        		        "cmp %0, %1 \n"                 /* Compares f16Val with 0x00008000 */
                        "bne .+4 \n"                    /* If f32Val != 0x8000, then jumps through next command */
		                "subs %0, %0, #1 \n"            /* Compares f16Val with 0x00008000 */
                        #if defined(__GNUC__)           /* For GCC compiler */
                            ".syntax divided \n"
                        #endif
                        : "+l"(f16Val): "l"(f32SatVal));
    #endif

    return f16Val;
}

#if defined(__cplusplus)
}
#endif

#endif /* _MLIB_NEG_F16_ASM_H_ */
