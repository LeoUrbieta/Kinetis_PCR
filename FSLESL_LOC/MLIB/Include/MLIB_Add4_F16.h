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
* @brief  Summation of four inputs
* 
*******************************************************************************/
#ifndef _MLIB_ADD4_F16_H_
#define _MLIB_ADD4_F16_H_

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
#define MLIB_Add4_F16_Ci(f16Add1, f16Add2, f16Add3, f16Add4)                   \
        MLIB_Add4_F16_FCi(f16Add1, f16Add2, f16Add3, f16Add4)                  

/***************************************************************************//*!
*  Summation of four inputs        
*  f16Out = f16Add1 + f16Add2 + f16Add3 + f16Add4
*  function is not saturated
*******************************************************************************/
static inline frac16_t MLIB_Add4_F16_FCi(register frac16_t f16Add1, register frac16_t f16Add2, 
                                         register frac16_t f16Add3, register frac16_t f16Add4)
{
    return((frac16_t)(f16Add1 + f16Add2 + f16Add3 + f16Add4)); 
}

#if defined(__cplusplus)
}
#endif

#endif  /* _MLIB_ADD4_F16_H_ */
