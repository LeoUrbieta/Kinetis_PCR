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
* @brief  Look-up table algorithm using linear interpolation 
* 
*******************************************************************************/
#ifndef _GFLIB_LUT1D_F16_H_
#define _GFLIB_LUT1D_F16_H_

#if defined(__cplusplus)
extern "C" {
#endif

/*******************************************************************************
* Includes
*******************************************************************************/

#include "mlib.h"
#include "gflib_types.h"

/*******************************************************************************
* Macros 
*******************************************************************************/  
#define GFLIB_Lut1D_F16_C(f16X, pf16Table, u16TableSize) GFLIB_Lut1D_F16_FC(f16X, pf16Table, u16TableSize)  

/*******************************************************************************
* Exported function prototypes
*******************************************************************************/
extern frac16_t GFLIB_Lut1D_F16_FC(frac16_t f16X, const frac16_t *pf16Table, uint16_t u16TableSize);


#if defined(__cplusplus)
}
#endif

#endif /* _GFLIB_LUT1D_F16_H_ */
