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
#ifndef _MLIB_SUB_A32_ASM_H_
#define _MLIB_SUB_A32_ASM_H_

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
#define MLIB_Sub_A32ss_Asmi(f16Min, f16Sub) MLIB_Sub_A32ss_FAsmi(f16Min, f16Sub)
#define MLIB_Sub_A32as_Asmi(a32Accum, f16Sub) MLIB_Sub_A32as_FAsmi(a32Accum, f16Sub)
  
/***************************************************************************//*!
*
* a32Out = f16Min - f16Sub
* 
*******************************************************************************/   
static inline acc32_t MLIB_Sub_A32ss_FAsmi(register frac16_t f16Min, register frac16_t f16Sub)
{
    register acc32_t a32Val;
    #if defined(__CC_ARM)                                  /* For ARM Compiler */
        __asm volatile{ sxth f16Min, f16Min                /* Transforms 16-bit input f16Sub to 32-bit */
                        sxth f16Sub, f16Sub                /* Transforms 16-bit input f16Sub to 32-bit */
                        subs a32Val, f16Min, f16Sub};      /* f16Min = f16Min - f16Sub */
    #else
        __asm volatile(
                        #if defined(__GNUC__)              /* For GCC compiler */
                            ".syntax unified \n"           /* Using unified asm syntax */
                        #endif
                        "sxth %1, %1 \n"                   /* Transforms 16-bit input f16Sub to 32-bit */
                        "sxth %2, %2 \n"                   /* Transforms 16-bit input f16Sub to 32-bit */
                        "subs %0, %1, %2 \n"               /* f16Min = f16Min - f16Sub */
                        #if defined(__GNUC__)              /* For GCC compiler */
                            ".syntax divided \n"
                        #endif
                        : "=l"(a32Val), "+l"(f16Min), "+l"(f16Sub):);
    #endif

    return a32Val;
}

/***************************************************************************//*!
*
* a32Out = a32Accum - f16Sub
* 
*******************************************************************************/   
static inline acc32_t MLIB_Sub_A32as_FAsmi(register acc32_t a32Accum, register frac16_t f16Sub)
{
    #if defined(__CC_ARM)                                   /* For ARM Compiler */
        __asm volatile{ sxth f16Sub, f16Sub                 /* Transforms 16-bit input f16Sub to 32-bit */
                        subs a32Accum, a32Accum, f16Sub};   /* a32Accum = a32Accum - f16Sub */

    #else
        __asm volatile(
                        #if defined(__GNUC__)               /* For GCC compiler */
                            ".syntax unified \n"            /* Using unified asm syntax */
                        #endif
                        "sxth %1, %1 \n"                    /* Transforms 16-bit input f16Sub to 32-bit */
                        "subs %0, %0, %1 \n"                /* a32Accum = a32Accum - f16Sub */
                        #if defined(__GNUC__)               /* For GCC compiler */
                            ".syntax divided \n"
                        #endif
                        : "+l"(a32Accum), "+l"(f16Sub):);
    #endif

    return a32Accum;
}

#if defined(__cplusplus)
}
#endif

#endif /* _MLIB_SUB_A32_ASM_H_ */
