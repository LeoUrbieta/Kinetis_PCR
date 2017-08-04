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
#ifndef _MLIB_MUL_A32_H_
#define _MLIB_MUL_A32_H_

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
#define MLIB_Mul_F16as_Ci(a32Accum, f16Mult)    MLIB_Mul_F16as_FCi(a32Accum, f16Mult)
#define MLIB_MulNeg_F16as_Ci(a32Accum, f16Mult) MLIB_MulNeg_F16as_FCi(a32Accum, f16Mult)

/***************************************************************************//*!
*
* f16Out = a32Accum * f16Mult
* Without saturation
*******************************************************************************/  
static inline frac16_t MLIB_Mul_F16as_FCi(register acc32_t a32Accum, register frac16_t f16Mult)
{
    return((frac16_t)(((((int32_t)(a32Accum)&0xffff)*(int32_t)(f16Mult))>>15)+
                      ((((int32_t)(a32Accum)>>16)*(int32_t)(f16Mult))<<1)));
  
}



/***************************************************************************//*!
*
* f16Out = a32Accum * -f16Mult

*******************************************************************************/
static inline frac16_t MLIB_MulNeg_F16as_FCi(register acc32_t a32Accum, register frac16_t f16Mult)
{
    return ((frac16_t)(((((int32_t)(a32Accum)&0xffff)*(int32_t)(-f16Mult))>>15)+
                       ((((int32_t)(a32Accum)>>16)*(int32_t)(-f16Mult))<<1)));
}

#if defined(__cplusplus)
}
#endif

#endif /* _MLIB_MUL_A32_H_ */
