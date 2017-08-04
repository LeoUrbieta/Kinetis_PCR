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
* @brief  Multiply with rounding
* 
*******************************************************************************/
#ifndef _MLIB_MULRND_A32_H_
#define _MLIB_MULRND_A32_H_

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
#define MLIB_MulRnd_F16as_Ci(a32Accum, f16Mult)    MLIB_MulRnd_F16as_FCi(a32Accum, f16Mult)
#define MLIB_MulNegRnd_F16as_Ci(a32Accum, f16Mult) MLIB_MulNegRnd_F16as_FCi(a32Accum, f16Mult)

/***************************************************************************//*!
*
* f16Out = a32Accum * f16Mult
* Without saturation
*******************************************************************************/
static inline frac16_t MLIB_MulRnd_F16as_FCi(register acc32_t a32Accum, register frac16_t f16Mult)
{                                                                              
    return((frac16_t)((((((int32_t)(a32Accum)&0xffff)*(int32_t)(f16Mult))+0x4000)>>15)+
                      (((((int32_t)(a32Accum))>>16)*(int32_t)(f16Mult))<<1)));
}

/***************************************************************************//*!
*
* f16Out = a32Accum * -f16Mult
* 
*******************************************************************************/
static inline frac16_t MLIB_MulNegRnd_F16as_FCi(register acc32_t a32Accum, register frac16_t f16Mult)
{
  return ((frac16_t)(((((((int32_t)(a32Accum)&0xffff)*(int32_t)(-f16Mult))+0x4000)>>15)+
                     ((((((int32_t)(a32Accum)))>>16)*(int32_t)(-f16Mult))<<1))));
}

#if defined(__cplusplus)
}
#endif

#endif /* _MLIB_MULRND_A32_H_ */
