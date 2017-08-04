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
* @brief  Subtraction
* 
*******************************************************************************/
#ifndef _MLIB_SUB_F16_ASM_H_
#define _MLIB_SUB_F16_ASM_H_

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
#define MLIB_SubSat_F16_Asmi(f16Min, f16Sub) MLIB_SubSat_F16_FAsmi(f16Min, f16Sub)

/***************************************************************************//*!
*
* f16Out = f16Min - f16Sub
* With saturation
*******************************************************************************/
static inline frac16_t MLIB_SubSat_F16_FAsmi(register frac16_t f16Min, register frac16_t f16Sub)
{
    register frac32_t f32Val = 0x8000;

    #if defined(__CC_ARM)                          	    /* For ARM Compiler */
        __asm volatile{ sxth f16Min, f16Min             /* Transforms 16-bit input f16Min to 32-bit */
                        sxth f16Sub, f16Sub             /* Transforms 16-bit input f16Sub to 32-bit */
                        subs f16Min, f16Min, f16Sub     /* f16Min = f16Min - f16Sub */

                        cmp f32Val, f16Min              /* Compares f16Min with 0x7FFF */
                        bge NegTest                     /* If f16Min < 0x8000, then goes to NegTest */
                        subs f16Min, f32Val, #1         /* If f16Min >= 0x8000, then f16Min = 0x7FFF */
                        b SatEnd                        /* Goes to SatEnd */
                    NegTest:
                        sxth f32Val, f32Val             /* f32Val = 0xFFFF8000 */
                        cmp f32Val, f16Min              /* Compares f16Min with 0xFFFF8000 */
                        ble SatEnd                      /* If f16Min >= 0xFFFF8000, then goes to SatEnd */
                        mov f16Min, f32Val};            /* If f16Min < 0xFFFF8000, then f16Min = 0xFFFF8000 */
                    SatEnd:
    #else
        __asm volatile(
                        #if defined(__GNUC__)           /* For GCC compiler */
                            ".syntax unified \n"        /* Using unified asm syntax */
                        #endif
                        "sxth %2, %2 \n"                /* Transforms 16-bit input f16Min to 32-bit */
                        "sxth %0, %0 \n"                /* Transforms 16-bit input f16Sub to 32-bit */
                        "subs %2, %2, %0 \n"            /* f16Min = f16Min - f16Sub */

                        "cmp %1, %2 \n"                 /* Compares f16Min with 0x8000 */
                        "bgt .+6 \n"                    /* If f16Min < 0x8000, then jumps through two commands */
                        "subs %2, %1, #1 \n"            /* If f16Min >= 0x8000, then f16Min = 0x7FFF */
                        "b .+10 \n"                     /* Jumps through four commands */

                        "sxth %1, %1 \n"                /* f32Val = 0xFFFF8000 */
                        "cmp %1, %2 \n"                 /* Compares f16Min with 0xFFFF8000 */
                        "ble .+4 \n"                    /* If f16Min >= 0xFFFF8000, then jumps through next commands */
                        "mov %2, %1 \n"                 /* If f16Min < 0xFFFF8000, then f16Min = 0xFFFF8000 */
                        #if defined(__GNUC__)           /* For GCC compiler */
                            ".syntax divided \n"
                        #endif
                        : "+l"(f16Sub), "+l"(f32Val), "+l"(f16Min):);
    #endif

    return f16Min;
}

#if defined(__cplusplus)
}
#endif

#endif /* _MLIB_SUB_F16_ASM_H_ */
