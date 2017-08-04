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
* @brief  Division
* 
*******************************************************************************/
#ifndef _MLIB_DIV_F16_ASM_H_
#define _MLIB_DIV_F16_ASM_H_

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
#define MLIB_Div_F16_Asm(f16Num, f16Denom) MLIB_Div_F16_FAsm(f16Num, f16Denom)
#define MLIB_DivSat_F16_Asm(f16Num, f16Denom) MLIB_DivSat_F16_FAsm(f16Num, f16Denom)

/*******************************************************************************
* Exported function prototypes
*******************************************************************************/
extern frac16_t MLIB_Div_F16_FAsm(frac16_t f16Num, frac16_t f16Denom);
extern frac16_t MLIB_DivSat_F16_FAsm(frac16_t f16Num, frac16_t f16Denom);

#if defined(__cplusplus)
}
#endif

#endif  /* _MLIB_DIV_F16_ASM_H_ */
