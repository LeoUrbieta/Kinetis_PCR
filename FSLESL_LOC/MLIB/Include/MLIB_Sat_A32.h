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
* @brief  Saturation
* 
*******************************************************************************/
#ifndef _MLIB_SAT_A32_H_
#define _MLIB_SAT_A32_H_

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
#define MLIB_Sat_F16a_Ci(a32Accum) MLIB_Sat_F16a_FCi(a32Accum) 
  
/***************************************************************************//*!
*
* Takes the fractional part from number in accumulator format and
* saturate if the original number is greater than 1. 
* 
*******************************************************************************/ 
static inline frac16_t MLIB_Sat_F16a_FCi(register acc32_t a32Accum)
{
    register int32_t i32z;
    i32z = (int32_t)(a32Accum);
  
    i32z = (i32z > ((int32_t)(INT16_MAX))) ? ((int32_t)(INT16_MAX)) : i32z;
    i32z = (i32z < ((int32_t)(INT16_MIN))) ? ((int32_t)(INT16_MIN)) : i32z;
    return ((frac16_t)(i32z));
}

#if defined(__cplusplus)
}
#endif

#endif /* _MLIB_SAT_A32_H_ */
