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
#ifndef _MLIB_SUB4_F32_H_
#define _MLIB_SUB4_F32_H_

#if defined(__cplusplus)
extern "C" {
#endif

/*******************************************************************************
* Includes
*******************************************************************************/
#include "mlib_types.h"
#include "MLIB_Conv_F32.h"

/*******************************************************************************
* Macros 
*******************************************************************************/  
#define MLIB_Sub4_F32_Ci(f32Min, f32Sub1, f32Sub2, f32Sub3)                    \
        MLIB_Sub4_F32_FCi(f32Min, f32Sub1, f32Sub2, f32Sub3)                   

/***************************************************************************//*!
*  Subtraction of three input values from the first input      
*  f32Out = f32Min + f32Sub1 + f32Sub2 + f32Sub3
*  function is not saturated
*******************************************************************************/  
static inline frac32_t MLIB_Sub4_F32_FCi(register frac32_t f32Min, register frac32_t f32Sub1, 
                                         register frac32_t f32Sub2, register frac32_t f32Sub3)
{
    return((frac32_t)(f32Min - f32Sub1 - f32Sub2 - f32Sub3)); 
}

#if defined(__cplusplus)
}
#endif

#endif  /* _MLIB_SUB4_F32_H_ */
