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
* @brief  Multiply accumulate of four inputs with rounding
* 
*******************************************************************************/
#ifndef _MLIB_MAC4RND_F16_H_
#define _MLIB_MAC4RND_F16_H_

#if defined(__cplusplus)
extern "C" {
#endif

/*******************************************************************************
* Includes
*******************************************************************************/
#include "mlib_types.h"
#include "MLIB_Add_F32.h"
#include "MLIB_Add_F16.h"
#include "MLIB_MulRnd_F16.h" 

/*******************************************************************************
* Macros
*******************************************************************************/  
#define MLIB_Mac4Rnd_F16_Ci(f16Add1Mul1, f16Add1Mul2, f16Add2Mul1, f16Add2Mul2)    \
        MLIB_Mac4Rnd_F16_FCi(f16Add1Mul1, f16Add1Mul2, f16Add2Mul1, f16Add2Mul2) 
  
/***************************************************************************//*!
*
* f16Out = (f16Add1Mul1 * f16Add1Mul2) + (f16Add2Mul1 * f16Add2Mul2)
* Without saturation
*******************************************************************************/
static inline frac16_t MLIB_Mac4Rnd_F16_FCi(register frac16_t f16Add1Mul1, register frac16_t f16Add1Mul2, 
                                            register frac16_t f16Add2Mul1, register frac16_t f16Add2Mul2)
{
    return(frac16_t)(((MLIB_Add_F32_Ci((int32_t)(f16Add1Mul1)*(int32_t)(f16Add1Mul2),
                                       (int32_t)(f16Add2Mul1)*(int32_t)(f16Add2Mul2)))+0x4000)>>15);
}

#if defined(__cplusplus)
}
#endif

#endif /* _MLIB_MAC4RND_F16_H_ */
