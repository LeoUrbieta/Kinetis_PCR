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
#ifndef _MLIB_MAC_F16_H_
#define _MLIB_MAC_F16_H_

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
#define MLIB_Mac_F16_Ci( f16Accum, f16Mult1, f16Mult2)                        \
        MLIB_Mac_F16_FCi( f16Accum, f16Mult1, f16Mult2)                               
  
/***************************************************************************//*!
*
* f16Out = f16Accum + ( f16Mult1 * f16Mult2)
* Without saturation
*******************************************************************************/
static inline frac16_t MLIB_Mac_F16_FCi(register frac16_t f16Accum, 
                                        register frac16_t f16Mult1, register frac16_t f16Mult2)
{
    register acc32_t a32Temp;
    
    a32Temp = ((int32_t)f16Mult1 * (int32_t)f16Mult2);
    a32Temp = a32Temp >> 15;
    a32Temp = (acc32_t)f16Accum + a32Temp;
    return((frac16_t)a32Temp);  
}

#if defined(__cplusplus)
}
#endif

#endif /* _MLIB_MAC_F16_H_ */
