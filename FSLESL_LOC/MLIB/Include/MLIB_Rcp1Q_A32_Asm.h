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
* @brief  Reciprocal value
* 
*******************************************************************************/
#ifndef _MLIB_RCP1Q_A32_ASM_H_
#define _MLIB_RCP1Q_A32_ASM_H_

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
#define MLIB_Rcp1Q1_A32s_Asm(f16Denom) MLIB_Rcp1Q1_A32s_FAsm(f16Denom)
#define MLIB_Rcp1Q_A32s_Asm(f16Denom) MLIB_Rcp1Q_A32s_FAsm(f16Denom)

/*******************************************************************************
* Exported function prototypes
*******************************************************************************/
extern acc32_t MLIB_Rcp1Q1_A32s_FAsm(register frac16_t f16Denom);
extern acc32_t MLIB_Rcp1Q_A32s_FAsm(register frac16_t f16Denom);

#if defined(__cplusplus)
}
#endif

#endif /* _MLIB_RCP1Q_A32_ASM_H_ */
