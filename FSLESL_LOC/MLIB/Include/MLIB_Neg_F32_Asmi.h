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
#ifndef _MLIB_NEG_F32_ASM_H_
#define _MLIB_NEG_F32_ASM_H_

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
#define MLIB_NegSat_F32_Asmi(f32Val) MLIB_NegSat_F32_FAsmi(f32Val)
  
/***************************************************************************//*!
*
* Output = -f32Val
* With saturation
*******************************************************************************/  
#if defined(__IAR_SYSTEMS_ICC__)           /* IAR compiler */
#pragma diag_suppress=Pe549                /* Suppresses the Pe549 warning for IAR compiler*/
#endif
static inline frac32_t MLIB_NegSat_F32_FAsmi(register frac32_t f32Val)
{
	register frac32_t f32SatVal;
    #if defined(__CC_ARM)                               /* For ARM Compiler */
        __asm volatile{ rev f32SatVal, f32Val           /* f32SatVal = byte-reverse of f32Val*/
                        rsbs f32Val, f32Val, #0         /* f32Val = - f32Val */
                        cmp f32SatVal, #128             /* Compares f32SatVal with 0x80 */
                        bne SatEnd                      /* If f32SatVal != 0x80, then goes to SatEnd */
                        subs f32Val, f32Val, #1         /* If f32SatVal = 0x80, then f32Val = f32Val - 1 */
                    SatEnd: };

    #else
        __asm volatile(
                        #if defined(__GNUC__)           /* For GCC compiler */
                            ".syntax unified \n"        /* Using unified asm syntax */
                        #endif
                 		"rev %1, %0 \n"                 /* f32SatVal = byte-reverse of f32Val*/
                 		"rsbs %0, %0, #0 \n"            /* f32Val = - f32Val */
                 		"cmp %1, #128 \n"               /* Compares f32SatVal with 0x80 */
        		        "bne .+4 \n"                    /* If f32SatVal != 0x80, then jumps through next command */
                        "subs %0, %0, #1 \n"            /* If f32SatVal = 0x80, then f32Val = f32Val - 1 */
                        #if defined(__GNUC__)           /* For GCC compiler */
                            ".syntax divided \n"
                        #endif
                        : "+l"(f32Val), "+l"(f32SatVal):);
    #endif

    return f32Val;
}
#if defined(__IAR_SYSTEMS_ICC__)           /* IAR compiler */
#pragma diag_default=Pe549
#endif

#if defined(__cplusplus)
}
#endif

#endif /* _MLIB_NEG_F32_ASM_H_ */
