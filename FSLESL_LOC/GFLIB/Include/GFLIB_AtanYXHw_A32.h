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
* @brief  Arcus tangent function based on the provided x,y coordinates as arguments
* 		 using division and piece-wise polynomial approximation
* 
*******************************************************************************/
#ifndef _GFLIB_ATANYXHW_A32_H_
#define _GFLIB_ATANYXHW_A32_H_

#if defined(__cplusplus)
extern "C" {
#endif

/******************************************************************************
* Includes
******************************************************************************/
#include "mlib.h"
#include "GFLIB_Atan_A32.h"
#include "gflib_types.h"

/******************************************************************************
* Macros 
******************************************************************************/
#define GFLIB_AtanYXHw_F16_Asm(f16Y, f16X, pbErrFlag) GFLIB_AtanYXHw_F16_FAsm(f16Y, f16X, pbErrFlag)

/****************************************************************************
* Exported function prototypes
****************************************************************************/
extern frac16_t GFLIB_AtanYXHw_F16_FAsm(frac16_t f16Y, frac16_t f16X, bool_t *pbErrFlag);

/*******************************************************************************
* Global variables
*******************************************************************************/
extern GFLIB_CONST GFLIB_ATAN_T_A32 gsAtanCoef;

#if defined(__cplusplus)
}
#endif
#endif /* _GFLIB_ATANYXHW_A32_H_ */
