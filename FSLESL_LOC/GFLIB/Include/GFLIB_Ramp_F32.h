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
* @brief  Ramp 
* 
*******************************************************************************/
#ifndef _GFLIB_RAMP_F32_H_
#define _GFLIB_RAMP_F32_H_

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
******************************************************************************/  
#define GFLIB_RampInit_F32_Ci(f32InitVal, psParam)                            \
        GFLIB_RampInit_F32_FCi(f32InitVal, psParam)                           

/*******************************************************************************
* Types
*******************************************************************************/
typedef struct
{
    frac32_t f32RampUp;    /* Ramp-up increment */
    frac32_t f32RampDown;  /* Ramp-down increment */
    frac32_t f32State;     /* Previous ramp value */
} GFLIB_RAMP_T_F32;

/***************************************************************************//*!
* @brief  The function initializes the actual value of Ramp_F32.
*
* @param  ptr   GFLIB_RAMP_T_F32 *psParam
*                     - rampUp: Ramp-up increment
*                     - rampDown: Ramp-down increment
*                     - state: Actual state
*                     
* @param  in    frac32_t f32InitVal - Initial value
*******************************************************************************/
static inline void GFLIB_RampInit_F32_FCi(frac32_t f32InitVal, GFLIB_RAMP_T_F32 *psParam)
{
    psParam->f32State = f32InitVal;
}

#if defined(__cplusplus)
}
#endif

#endif /* _GFLIB_RAMP_F32_H */

