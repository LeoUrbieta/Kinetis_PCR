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
#ifndef _MLIB_RCPHW_A32_ASM_H_
#define _MLIB_RCPHW_A32_ASM_H_

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
#define MLIB_RcpHw1_A32s_Asm(f16Denom) MLIB_RcpHw_A32s_FAsm(f16Denom, &gu16CntMmdvsq)
#define MLIB_RcpHw_A32s_Asm(f16Denom) MLIB_RcpHw_A32s_FAsm(f16Denom, &gu16CntMmdvsq)

/*******************************************************************************
* Exported function prototypes
*******************************************************************************/
extern acc32_t MLIB_RcpHw_A32s_FAsm(register frac16_t f16Denom, const volatile uint16_t *pVal);

#if defined(__cplusplus)
}
#endif

#endif /* _MLIB_RCPHW_A32_ASM_H_ */
