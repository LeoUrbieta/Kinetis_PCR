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
* @brief  Multiply 
* 
*******************************************************************************/
#ifndef _MLIB_MUL_F32_H_
#define _MLIB_MUL_F32_H_

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
#define MLIB_Mul_F32_Ci(f32Mult1, f32Mult2)      MLIB_Mul_F32_FCi(f32Mult1, f32Mult2)
#define MLIB_Mul_F32ss_Ci(f16Mult1, f16Mult2)    MLIB_Mul_F32ss_FCi(f16Mult1, f16Mult2)
#define MLIB_MulSat_F32_Ci(f32Mult1, f32Mult2)   MLIB_MulSat_F32_FCi(f32Mult1, f32Mult2)
#define MLIB_MulSat_F32ss_Ci(f16Mult1, f16Mult2) MLIB_MulSat_F32ss_FCi(f16Mult1, f16Mult2)
#define MLIB_MulNeg_F32_Ci(f32Mult1, f32Mult2)   MLIB_MulNeg_F32_FCi(f32Mult1, f32Mult2)
#define MLIB_MulNeg_F32ss_Ci(f16Mult1, f16Mult2) MLIB_MulNeg_F32ss_FCi(f16Mult1, f16Mult2)
  
/***************************************************************************//*!
*
* f32Out = f32Mult1 * f32Mult2
* Without saturation
*******************************************************************************/   
static inline frac32_t MLIB_Mul_F32_FCi(register frac32_t f32Mult1, register frac32_t f32Mult2)
{
  return((((frac32_t)(f32Mult1>>16)*(frac32_t)(f32Mult2>>16))<<1) + 
         (((frac32_t)(f32Mult1>>16)*(frac32_t)(f32Mult2&0xffff))>>15) + 
         (((frac32_t)(f32Mult1&0xffff)*(frac32_t)(f32Mult2>>16))>>15));   
}

/***************************************************************************//*!
*
* f32Out = f16Mult1 * f16Mult2
* Without saturation
*******************************************************************************/
static inline frac32_t MLIB_Mul_F32ss_FCi(register frac16_t f16Mult1, register frac16_t f16Mult2)
{
    return((frac32_t)(((int32_t)(f16Mult1)*(int32_t)(f16Mult2))<<1)); 
}

/***************************************************************************//*!
*
* f32Out = f32Mult1 * f32Mult2
* With saturation
*******************************************************************************/  
static inline frac32_t MLIB_MulSat_F32_FCi(register frac32_t f32Mult1, register frac32_t f32Mult2)
{
    register int32_t i32Temp;
    
    i32Temp = (int32_t)(MLIB_Mul_F32_Ci(f32Mult1, f32Mult2));
    i32Temp = (i32Temp == INT32_MIN) ? INT32_MAX : i32Temp;
    return((frac32_t)(i32Temp)); 
}

/***************************************************************************//*!
*
* f32Out = f16Mult1 * f16Mult2
* With saturation
*******************************************************************************/
static inline frac32_t MLIB_MulSat_F32ss_FCi(register frac16_t f16Mult1, register frac16_t f16Mult2)
{
    register int32_t i32Temp;
    
    i32Temp = (int32_t)(MLIB_Mul_F32ss_Ci(f16Mult1, f16Mult2));
    i32Temp = (i32Temp == INT32_MIN) ? INT32_MAX : i32Temp;
    return((frac32_t)(i32Temp));
}

/***************************************************************************//*!
*
* f32Out = f32Mult1 * -f32Mult2
* 
*******************************************************************************/  
static inline frac32_t MLIB_MulNeg_F32_FCi(register frac32_t f32Mult1, register frac32_t f32Mult2)
{
    register frac32_t f32Temp;
    
    f32Temp = (frac32_t)(MLIB_Mul_F32_Ci(f32Mult1, f32Mult2));
    return(-f32Temp); 
}

/***************************************************************************//*!
*
* f32Out = f16Mult1 * -f16Mult2
* 
*******************************************************************************/
static inline frac32_t MLIB_MulNeg_F32ss_FCi(register frac16_t f16Mult1, register frac16_t f16Mult2)
{
    return((frac32_t)(((int32_t)(f16Mult1)*(int32_t)((-f16Mult2)))<<1)); 
}

#if defined(__cplusplus)
}
#endif

#endif /* _MLIB_MUL_F32_H_ */
