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
* @brief  Summation of four inputs
* 
*******************************************************************************/
#ifndef _MLIB_ADD4_F16_ASM_H_
#define _MLIB_ADD4_F16_ASM_H_

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
#define MLIB_Add4Sat_F16_Asmi(f16Add1, f16Add2, f16Add3, f16Add4) MLIB_Add4Sat_F16_FAsmi(f16Add1, f16Add2, f16Add3, f16Add4)

/***************************************************************************//*!
*  Saturated summation of four inputs 	   
*  Output = f16Add1 + f16Add2 + f16Add3 + f16Add4
*******************************************************************************/
static inline frac16_t MLIB_Add4Sat_F16_FAsmi(register frac16_t f16Add1, register frac16_t f16Add2, register frac16_t f16Add3, register frac16_t f16Add4)
{        
    register frac32_t f32Val = 0x8000;

    #if defined(__CC_ARM)                               /* For ARM Compiler */
        __asm volatile{ sxth f16Add1, f16Add1           /* Transforms 16-bit input f16Add1 to 32-bit */
                        sxth f16Add2, f16Add2           /* Transforms 16-bit input f16Add2 to 32-bit */
                        sxth f16Add3, f16Add3           /* Transforms 16-bit input f16Add1 to 32-bit */
                        sxth f16Add4, f16Add4           /* Transforms 16-bit input f16Add2 to 32-bit */
                        adds f16Add1, f16Add2, f16Add1  /* f16Add1 = f16Add1 + f16Add2 */
                        adds f16Add1, f16Add1, f16Add3  /* f16Add1 = f16Add1 + f16Add3 */
                        adds f16Add1, f16Add1, f16Add4  /* f16Add1 = f16Add1 + f16Add4 */

                        cmp f32Val, f16Add1             /* Compares f16Add1 with 0x8000 */
                        bgt NegTest                     /* If f16Add1 < 0x8000, then goes to NegTest */
                        subs f16Add1, f32Val, #1        /* If f16Add1 >= 0x8000, then f16Add1 = 0x7FFF */
                        b SatEnd                        /* Goes to SatEnd */
                    NegTest:
                        sxth f32Val, f32Val             /* f32Val = 0xFFFF8000 */
                        cmp f32Val, f16Add1             /* Compares f16Add1 with 0xFFFF8000 */
                        ble SatEnd                      /* If f16Add1 >= 0xFFFF8000, then goes to SatEnd */
                        mov f16Add1, f32Val             /* If f16Add1 < 0xFFFF8000, then f16Add1 = 0xFFFF8000 */
                    SatEnd: };
    #else
        __asm volatile(
                        #if defined(__GNUC__)           /* For GCC compiler */
                            ".syntax unified \n"        /* Using unified asm syntax */
                        #endif
                        "sxth %0, %0 \n"                /* Transforms 16-bit input f16Add1 to 32-bit */
                        "sxth %1, %1 \n"                /* Transforms 16-bit input f16Add2 to 32-bit */
                        "sxth %2, %2 \n"                /* Transforms 16-bit input f16Add1 to 32-bit */
                        "sxth %3, %3 \n"                /* Transforms 16-bit input f16Add2 to 32-bit */
                        "adds %0, %0, %1 \n"            /* f16Add1 = f16Add1 + f16Add2 */
                        "adds %0, %0, %2 \n"            /* f16Add1 = f16Add1 + f16Add3 */
                        "adds %0, %0, %3 \n"            /* f16Add1 = f16Add1 + f16Add4 */

                        "cmp %4, %0 \n"                 /* Compares f16Add1 with 0x8000 */
                        "bgt .+6 \n"                    /* If f16Add1 < 0x8000, then jumps through two commands */
                        "subs %0, %4, #1 \n"            /* If f16Add1 >= 0x8000, then f16Add1 = 0x7FFF */
                        "b .+10 \n"                     /* Jumps through four commands */

                        "sxth %4, %4 \n"                /* f32Val = 0xFFFF8000 */
                        "cmp %4, %0 \n"                 /* Compares f16Add1 with 0xFFFF8000 */
                        "ble .+4 \n"                    /* If f16Add1 >= 0xFFFF8000, then jumps through next commands */
                        "mov %0, %4 \n"                 /* If f16Add1 < 0xFFFF8000, then f16Add1 = 0xFFFF8000 */
                        #if defined(__GNUC__)           /* For GCC compiler */
                            ".syntax divided \n"
                        #endif
                        : "+l"(f16Add1), "+l"(f16Add2), "+l"(f16Add3), "+l"(f16Add4), "+l"(f32Val):);
    #endif

    return f16Add1;
}

#if defined(__cplusplus)
}
#endif

#endif  /* _MLIB_ADD4_F16_ASM_H_ */
