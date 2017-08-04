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
* @brief  Flex ramp functions with 16-bit fractional output and MMDVSQ support
* 
*******************************************************************************/
#ifndef _GFLIB_FLEXRAMPHW_A32_H_
#define _GFLIB_FLEXRAMPHW_A32_H_

#if defined(__cplusplus) 
extern "C" { 
#endif 
/******************************************************************************
* Includes
******************************************************************************/
#include "mlib.h"
#include "GFLIB_FlexRamp_A32.h"    
    
/******************************************************************************
* Macros 
******************************************************************************/
#define GFLIB_FlexRampCalcIncrHw_F16_C(f16Target, a32Duration, psParam)       \
        GFLIB_FlexRampCalcIncrHw_F16_FC(f16Target, a32Duration, psParam)

/******************************************************************************
* Exported function prototypes
******************************************************************************/
extern void GFLIB_FlexRampCalcIncrHw_F16_FC(frac16_t f16Target,
                                            acc32_t a32Duration,
                                            GFLIB_FLEXRAMP_T_F32 *psParam);


#if defined(__cplusplus) 
} 
#endif 

#endif /* _GFLIB_FLEXRAMPHw_A32_H_ */
