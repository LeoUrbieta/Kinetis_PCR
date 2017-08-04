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
* @brief  Moving average filter 
* 
*******************************************************************************/
#ifndef _GDFLIB_FILTERMA_A32_H_
#define _GDFLIB_FILTERMA_A32_H_

#if defined(__cplusplus)
extern "C" {
#endif

/*******************************************************************************
* Includes
*******************************************************************************/
#include "gdflib_types.h"
#include "mlib.h"

/*******************************************************************************
* Macros 
*******************************************************************************/
#define GDFLIB_FilterMAInit_F16_Ci(f16InitVal, psParam)                       \
        GDFLIB_FilterMAInit_F16_FCi(f16InitVal, psParam)                      

/*******************************************************************************
* Types
*******************************************************************************/
typedef struct{
    acc32_t  a32Acc;   /* Filter accumulator. */
    uint16_t u16Sh;    /* Number of samples for averaging, filter sample window [0,15].*/
}GDFLIB_FILTER_MA_T_A32;


/***************************************************************************//*!
* @brief  The function initializes the actual values of FilterMA_F16.
*
* @param  in  frac16_t f16InitVal  - Initial value
*         ptr  GDFLIB_FILTER_MA_T_A32 *psParam - pointer to filter structure 
*
*******************************************************************************/
static inline void GDFLIB_FilterMAInit_F16_FCi(frac16_t f16InitVal,
                                               GDFLIB_FILTER_MA_T_A32 *psParam)
{
    psParam->a32Acc = (acc32_t)f16InitVal;
}

#if defined(__cplusplus)
}
#endif

#endif /* _GDFLIB_FILTERMA_A32_H_ */
