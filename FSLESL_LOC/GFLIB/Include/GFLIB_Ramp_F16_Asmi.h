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
* @brief  Ramp 
* 
*******************************************************************************/
#ifndef _GFLIB_RAMP_F16_ASMI_H_
#define _GFLIB_RAMP_F16_ASMI_H_

#if defined(__cplusplus)
extern "C" {
#endif

/*******************************************************************************
* Includes
*******************************************************************************/
#include "gflib_types.h"
#include "mlib.h"
  
/*******************************************************************************
* Macros 
*******************************************************************************/  
#define GFLIB_Ramp_F16_Asmi(f16Target, psParam) GFLIB_Ramp_F16_FAsmi(f16Target, psParam)

/***************************************************************************//*!
* @brief  Ramp function
*
* @param  ptr	        GFLIB_RAMP_T_F16 *psParam
*						  - rampUp: Ramp-up increment
*						  - rampDown: Ramp-down increment
*						  - state: Actual state
* @param  in    		frac16_t f16Target
*                         - Desired value in <-1;1) in frac16_t
*
* @return This function returns
*                       frac16_t value <-1;1)
*
* @remarks 	This function ramps the value from the f16State value up/down to
*			the f16Target value using the up/down increments defined in
*			the psParam structure.
*******************************************************************************/
#if defined(__IAR_SYSTEMS_ICC__)           /* IAR compiler */
#pragma diag_suppress=Pe549  /* Suppresses the Pe549 warning for IAR compiler*/
#endif
static inline frac16_t GFLIB_Ramp_F16_FAsmi(frac16_t f16Target, GFLIB_RAMP_T_F16 *psParam)
{
    register frac32_t f32Val1, f32Val2;

    #if defined(__CC_ARM)                               /* For ARM Compiler */
        __asm volatile{ ldrh f32Val1, [psParam, #4]     /* Loads psParam -> f16State */
                        sxth f32Val1, f32Val1           /* Transforms 16-bit value to 32-bit */
                        sxth f16Target, f16Target       /* Transforms 16-bit input value to 32-bit */
                        cmp f16Target, f32Val1          /* Compares f16Target with psParam -> f16State */
                        blt RampDown                    /* If f16Target < psParam -> f16State, then ramps down */
                        ldrh f32Val2, [psParam]         /* Loads psParam -> f16RampUp */
                        adds f32Val1, f32Val1, f32Val2  /* f32Val1 = f16State + f16RampUp */
                        cmp f16Target, f32Val1          /* Compares f32Val1 with f16Target */
                        blt RampEnd                     /* If f16Target < f32Val1, then executes next command */
                        mov f16Target, f32Val1          /* f16Target = f32Val1 */
                        b RampEnd                       /* Goes to the RampEnd label */
                     RampDown:
                        ldrh f32Val2, [psParam, #2]     /* Loads psParam -> f16RampDown */
                        subs f32Val1, f32Val1, f32Val2  /* f32Val1 = f16State - f16RampDown */
                        cmp f16Target, f32Val1          /* Compares f32Val1 with f16Target */
                        bgt RampEnd                     /* If f16Target > f32Val1, then executes next command */
                        mov f16Target, f32Val1          /* f16Target = f32Val1 */
                     RampEnd:
                        strh f16Target, [psParam, #4] };/* Loads psParam -> f16State */
    #else
        __asm volatile(
                        #if defined(__GNUC__)           /* For GCC compiler */
                            ".syntax unified \n"        /* Using unified asm syntax */
                        #endif
                        "ldrh %2, [%1, #4] \n"          /* Loads psParam -> f16State */
                        "sxth %2, %2 \n"                /* Transforms 16-bit value to 32-bit */
                        "sxth %0, %0 \n"                /* Transforms 16-bit input value to 32-bit */
                        "cmp %0, %2 \n"                 /* Compares f16Target with psParam -> f16State */
                        "blt RampDown \n"               /* If f16Target < psParam -> f16State, then ramps down */
                        "ldrh %3, [%1] \n"              /* Loads psParam -> f16RampUp */
                        "adds %2, %2, %3 \n"            /* f32Val1 = f16State + f16RampUp */
                        "cmp %0, %2 \n"                 /* Compares f32Val1 with f16Target */
                        "blt RampEnd \n"                /* If f16Target < f32Val1, then executes next command */
                        "mov %0, %2 \n"                 /* f16Target = f32Val1 */
                        "b RampEnd \n"                  /* Goes to the RampEnd label */
                    "RampDown: \n"
                        "ldrh %3, [%1, #2] \n"          /* Loads psParam -> f16RampDown */
                        "subs %2, %2, %3 \n"            /* f32Val1 = f16State - f16RampDown */
                        "cmp %0, %2 \n"                 /* Compares f32Val1 with f16Target */
                        "bgt .+4 \n"                    /* If f16Target > f32Val1, then executes next command */
                        "mov %0, %2 \n"                 /* f16Target = f32Val1 */
                    "RampEnd: \n"
                        "strh %0, [%1, #4] \n"          /* Loads psParam -> f16State */
                        #if defined(__GNUC__)           /* For GCC compiler */
                            ".syntax divided \n"
                        #endif
                        : "+l"(f16Target), "+l"(psParam), "+l"(f32Val1), "+l"(f32Val2):);
    #endif
    return(f16Target);
}
#if defined(__IAR_SYSTEMS_ICC__)           /* IAR compiler */
#pragma diag_default=Pe549
#endif

#if defined(__cplusplus)
}
#endif

#endif /* _GFLIB_RAMP_F16_ASMI_H */

