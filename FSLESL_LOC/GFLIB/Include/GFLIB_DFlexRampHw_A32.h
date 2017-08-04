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
* @brief  Dynamic flex ramp functions with 16-bit fractional output 
* 
*******************************************************************************/
#ifndef _GFLIB_DFLEXRAMPHW_A32_H_
#define _GFLIB_DFLEXRAMPHW_A32_H_

#if defined(__cplusplus) 
extern "C" { 
#endif 
/******************************************************************************
* Includes
******************************************************************************/
#include "mlib.h"
#include "GFLIB_DFlexRamp_A32.h"  
    
/******************************************************************************
* Macros 
******************************************************************************/
#define GFLIB_DFlexRampCalcIncrHw_F16_C(f16Target, a32Duration, f32IncrSatMot, f32IncrSatGen, psParam) \
        GFLIB_DFlexRampCalcIncrHw_F16_FC(f16Target, a32Duration, f32IncrSatMot, f32IncrSatGen, psParam)

/******************************************************************************
* Exported function prototypes
******************************************************************************/
extern void GFLIB_DFlexRampCalcIncrHw_F16_FC(frac16_t f16Target,
                                             acc32_t a32Duration,
                                             frac32_t f32IncrSatMot,
                                             frac32_t f32IncrSatGen,
                                             GFLIB_DFLEXRAMP_T_F32 *psParam);

#if defined(__cplusplus) 
} 
#endif 

#endif /* _GFLIB_DFLEXRAMPHW_A32_H_ */
