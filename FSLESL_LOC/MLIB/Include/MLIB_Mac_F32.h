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
* @brief  Multiply accumulate
* 
*******************************************************************************/
#ifndef _MLIB_MAC_F32_H_
#define _MLIB_MAC_F32_H_

#if defined(__cplusplus)
extern "C" {
#endif

/*******************************************************************************
* Includes
*******************************************************************************/
#include "mlib_types.h"
#include "MLIB_Add_F32.h"
#include "MLIB_Sub_F32.h"
#include "MLIB_Mul_F32.h"

/*******************************************************************************
* Macros
*******************************************************************************/                       
#define MLIB_Mac_F32lss_Ci(f32Accum, f16Mult1, f16Mult2)                       \
        MLIB_Mac_F32lss_FCi(f32Accum, f16Mult1, f16Mult2)                      

/***************************************************************************//*!
*
* f32Out = f32Accum + ( f16Mult1 * f16Mult2)
* Without saturation
*******************************************************************************/
static inline frac32_t MLIB_Mac_F32lss_FCi(register frac32_t f32Accum, 
                                           register frac16_t f16Mult1, register frac16_t f16Mult2)
{
    frac32_t f32Temp;
    f32Temp = MLIB_Mul_F32ss_Ci(f16Mult1,f16Mult2);
    return(MLIB_Add_F32_Ci(f32Accum, f32Temp));
}

#if defined(__cplusplus)
}
#endif

#endif  /* _MLIB_MAC_F32_H_ */
