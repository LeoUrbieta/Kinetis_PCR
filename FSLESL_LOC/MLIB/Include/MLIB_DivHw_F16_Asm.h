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
#ifndef _MLIB_DIVHW_F16_ASM_H_
#define _MLIB_DIVHW_F16_ASM_H_

#if defined(__cplusplus)
extern "C" {
#endif

/*******************************************************************************
* Includes
*******************************************************************************/
#include "MLIB_MMDVSQ.h"

/*******************************************************************************
* Macros 
*******************************************************************************/  
#define MLIB_DivHw_F16_Asm(f16Num, f16Denom) MLIB_DivHw_F16_FAsm(f16Num, f16Denom, &gu16CntMmdvsq)
#define MLIB_DivHwSat_F16_Asm(f16Num, f16Denom) MLIB_DivHwSat_F16_FAsm(f16Num, f16Denom, &gu16CntMmdvsq)

/*******************************************************************************
* Exported function prototypes
*******************************************************************************/
extern frac16_t MLIB_DivHw_F16_FAsm(frac16_t f16Num, frac16_t f16Denom, const volatile uint16_t *pVal);
extern frac16_t MLIB_DivHwSat_F16_FAsm(frac16_t f16Num, frac16_t f16Denom, const volatile uint16_t *pVal);

#if defined(__cplusplus)
}
#endif

#endif  /* _MLIB_DIVHW_F16_ASM_H_ */
