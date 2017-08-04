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
#ifndef _MLIB_DIVHW_A32_ASM_H_
#define _MLIB_DIVHW_A32_ASM_H_

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
#define MLIB_DivHw_A32ll_Asm(f32Num, f32Denom) MLIB_DivHw_A32ll_FAsm(f32Num, f32Denom, &gu16CntMmdvsq)
#define MLIB_DivHw_A32ls_Asm(f32Num, f16Denom) MLIB_DivHw_A32ls_FAsm(f32Num, f16Denom, &gu16CntMmdvsq)
#define MLIB_DivHw_A32ss_Asm(f16Num, f16Denom) MLIB_DivHw_A32ss_FAsm(f16Num, f16Denom, &gu16CntMmdvsq)

/*******************************************************************************
* Exported function prototypes
*******************************************************************************/  
extern frac32_t MLIB_DivHw_A32ll_FAsm(frac32_t f32Num, frac32_t f32Denom, const volatile uint16_t *pVal);
extern frac32_t MLIB_DivHw_A32ls_FAsm(frac32_t f32Num, frac16_t f16Denom, const volatile uint16_t *pVal);
extern frac16_t MLIB_DivHw_A32ss_FAsm(frac16_t f16Num, frac16_t f16Denom, const volatile uint16_t *pVal);

#if defined(__cplusplus)
}
#endif

#endif  /* _MLIB_DIVHW_A32_ASM_H_ */
