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
#ifndef _MLIB_SAT_A64_H_
#define _MLIB_SAT_A64_H_

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
#define MLIB_Sat_F32A_Ci(a64Accum) MLIB_Sat_F32A_FCi(a64Accum)
  
/***************************************************************************//*!
*
* Takes the fractional part from number in accumulator format and 
* saturate if the original number is greater than 1. 
* 
*******************************************************************************/ 
static inline frac32_t MLIB_Sat_F32A_FCi(register acc64_t a64Accum)
{
    register int64_t i64z;
    
    i64z = (int64_t)(a64Accum);
    i64z = (i64z > ((int64_t)(INT32_MAX))) ? ((int64_t)(INT32_MAX)) : i64z;    
    i64z = (i64z < ((int64_t)(INT32_MIN))) ? ((int64_t)(INT32_MIN)) : i64z;
    return((frac32_t)(i64z)); 
}

#if defined(__cplusplus)
}
#endif

#endif /* _MLIB_SAT_A64_H_ */
