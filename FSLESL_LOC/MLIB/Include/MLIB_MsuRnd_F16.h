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
* @brief  Multiply subtract with rounding
* 
*******************************************************************************/
#ifndef _MLIB_MSURND_F16_H_
#define _MLIB_MSURND_F16_H_

#if defined(__cplusplus)
extern "C" {
#endif

/*******************************************************************************
* Includes
*******************************************************************************/
#include "mlib_types.h"
#include "MLIB_Add_F16.h"
#include "MLIB_MulRnd_F16.h"

/*******************************************************************************
* Macros
*******************************************************************************/ 
#define MLIB_MsuRnd_F16_Ci(f16Accum, f16Mult1, f16Mult2)                       \
        MLIB_MsuRnd_F16_FCi(f16Accum, f16Mult1, f16Mult2)                      

/***************************************************************************//*!
*
* f16Out = f16Accum - ( f16Mult1 * f16Mult2)
* Without saturation
*******************************************************************************/
static inline frac16_t MLIB_MsuRnd_F16_FCi(register frac16_t f16Accum, 
                                           register frac16_t f16Mult1, register frac16_t f16Mult2)
{
    frac16_t f16Temp;  
    
    f16Temp = MLIB_MulNegRnd_F16_Ci(f16Mult1, f16Mult2);
    return(MLIB_Add_F16_Ci(f16Accum, f16Temp));
}

#if defined(__cplusplus)
}
#endif

#endif /* _MLIB_MSURND_F16_H_ */
