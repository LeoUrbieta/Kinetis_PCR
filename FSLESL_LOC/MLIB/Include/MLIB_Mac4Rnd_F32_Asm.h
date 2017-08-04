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
#ifndef _MLIB_MAC4RND_F32_ASM_H_
#define _MLIB_MAC4RND_F32_ASM_H_

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
#define MLIB_Mac4Rnd_F32_Asm(f32Add1Mul1, f32Add1Mul2, f32Add2Mul1, f32Add2Mul2) MLIB_Mac4Rnd_F32_FAsm(f32Add1Mul1, f32Add1Mul2, f32Add2Mul1, f32Add2Mul2)
#define MLIB_Mac4RndSat_F32_Asm(f32Add1Mul1, f32Add1Mul2, f32Add2Mul1, f32Add2Mul2) MLIB_Mac4RndSat_F32_FAsm(f32Add1Mul1, f32Add1Mul2, f32Add2Mul1, f32Add2Mul2)

/*******************************************************************************
* Exported function prototypes
*******************************************************************************/
extern frac16_t MLIB_Mac4Rnd_F32_FAsm(frac32_t f32Add1Mul1, frac32_t f32Add1Mul2, frac32_t f32Add2Mul1, frac32_t f32Add2Mul2);
extern frac16_t MLIB_Mac4RndSat_F32_FAsm(frac32_t f32Add1Mul1, frac32_t f32Add1Mul2, frac32_t f32Add2Mul1, frac32_t f32Add2Mul2);

#if defined(__cplusplus)
}
#endif

#endif  /* _MLIB_MAC4RND_F32_ASM_H_ */
