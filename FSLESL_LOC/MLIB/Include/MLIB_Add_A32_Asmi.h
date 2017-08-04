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
* @brief  Addition
* 
*******************************************************************************/
#ifndef _MLIB_ADD_A32_ASM_H_
#define _MLIB_ADD_A32_ASM_H_

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
#define MLIB_Add_A32ss_Asmi(f16Add1, f16Add2) MLIB_Add_A32ss_FAsmi(f16Add1, f16Add2)
#define MLIB_Add_A32as_Asmi(a32Accum, f16Add) MLIB_Add_A32as_FAsmi(a32Accum, f16Add)

/***************************************************************************//*!
*  Addition 	   
*  Output = f16Add1 + f16Add2
*  Result can overflow through fractional range and is stored in accumulator type
*******************************************************************************/
static inline acc32_t MLIB_Add_A32ss_FAsmi(register frac16_t f16Add1, register frac16_t f16Add2)
{ 
    register acc32_t a32Val;
    #if defined(__CC_ARM)                          	    /* For ARM Compiler */
        __asm volatile{ sxth f16Add1, f16Add1           /* Transforms 16-bit input f16Add2 to 32-bit */
                        sxth f16Add2, f16Add2           /* Transforms 16-bit input f16Add2 to 32-bit */
                        adds a32Val, f16Add1, f16Add2}; /* f16Add1 = f16Add1 + f16Add2 */
    #else
        __asm volatile(
                        #if defined(__GNUC__)           /* For GCC compiler */
                            ".syntax unified \n"        /* Using unified asm syntax */
                        #endif
                        "sxth %1, %1 \n"                /* Transforms 16-bit input f16Add2 to 32-bit */
                        "sxth %2, %2 \n"                /* Transforms 16-bit input f16Add2 to 32-bit */
                        "adds %0, %1, %2 \n"            /* f16Add1 = f16Add1 + f16Add2 */
                        #if defined(__GNUC__)           /* For GCC compiler */
                            ".syntax divided \n"
                        #endif
                        : "=l"(a32Val), "+l"(f16Add1), "+l"(f16Add2):);
    #endif

    return a32Val;
}

/***************************************************************************//*!
*  Addition 	   
*  Output = a32Accum + f16Add
*  Result can overflow through fractional range and is stored in accumulator type
*******************************************************************************/
static inline acc32_t MLIB_Add_A32as_FAsmi(register acc32_t a32Accum, register frac16_t f16Add)
{ 
    #if defined(__CC_ARM)                                 /* For ARM Compiler */
        __asm volatile{ sxth f16Add, f16Add               /* Transforms 16-bit input f16Add2 to 32-bit */
                        adds a32Accum, a32Accum, f16Add}; /* f16Add1 = f16Add1 + f16Add2 */

    #else
        __asm volatile(
                        #if defined(__GNUC__)           /* For GCC compiler */
                            ".syntax unified \n"        /* Using unified asm syntax */
                        #endif
                        "sxth %1, %1 \n"                /* Transforms 16-bit input f16Add2 to 32-bit */
                        "adds %0, %0, %1 \n"            /* a32Accum = a32Accum + f16Add2 */
                        #if defined(__GNUC__)           /* For GCC compiler */
                            ".syntax divided \n"
                        #endif
                        : "+l"(a32Accum), "+l"(f16Add):);
    #endif

    return a32Accum;
}

#if defined(__cplusplus)
}
#endif

#endif /* _MLIB_ADD_A32_ASM_H_*/
