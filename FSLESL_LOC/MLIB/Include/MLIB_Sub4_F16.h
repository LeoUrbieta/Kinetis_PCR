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
* @brief  Subtraction of three input values from the first input
* 
*******************************************************************************/
#ifndef _MLIB_SUB4_F16_H_
#define _MLIB_SUB4_F16_H_

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
#define MLIB_Sub4_F16_Ci(f16Min, f16Sub1, f16Sub2, f16Sub3)                    \
        MLIB_Sub4_F16_FCi(f16Min, f16Sub1, f16Sub2, f16Sub3)                   

/***************************************************************************//*!
*  Subtraction of three input values from the first input      
*  f16Out = f16Min + f16Sub1 + f16Sub2 + f16Sub3
*  function is not saturated
*******************************************************************************/
static inline frac16_t MLIB_Sub4_F16_FCi(register frac16_t f16Min, register frac16_t f16Sub1, 
                                         register frac16_t f16Sub2,register frac16_t f16Sub3)
{
    return((frac16_t)(f16Min - f16Sub1 - f16Sub2 - f16Sub3)); 
}

#if defined(__cplusplus)
}
#endif /* _MLIB_SUB4_F16_H_ */

#endif 
