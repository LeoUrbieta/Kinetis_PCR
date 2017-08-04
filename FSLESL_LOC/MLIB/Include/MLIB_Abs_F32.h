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
* @brief  Absolute Value
* 
*******************************************************************************/
#ifndef _MLIB_ABS_F32_H_
#define _MLIB_ABS_F32_H_

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
#define MLIB_Abs_F32_Ci(f32Val)    MLIB_Abs_F32_FCi(f32Val)
#define MLIB_AbsSat_F32_Ci(f32Val) MLIB_AbsSat_F32_FCi(f32Val)
  
/***************************************************************************//*!
*  Absolute value      
*  f32Out = |f32In|
*  not saturated
*******************************************************************************/
static inline frac32_t MLIB_Abs_F32_FCi(register frac32_t f32Val)
{
    return((f32Val < (frac32_t)0) ? (-f32Val) : (f32Val));
}

/***************************************************************************//*!
*  Absolute value saturadet        
*  f32Out = |f32In|
*******************************************************************************/  
static inline frac32_t MLIB_AbsSat_F32_FCi(register frac32_t f32Val)
{
    register int32_t i32Temp;
    
    i32Temp = (int32_t)(MLIB_Abs_F32_Ci(f32Val));
    i32Temp = (i32Temp == INT32_MIN) ? INT32_MAX : i32Temp; /* Correction for -1.0 * (-1.0) */
    return((frac32_t)(i32Temp));
}

#if defined(__cplusplus)
}
#endif

#endif  /* _MLIB_ABS_F32_H_*/
