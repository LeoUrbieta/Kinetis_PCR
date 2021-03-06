/*******************************************************************************
*
* Copyright 2007-2015 Freescale Semiconductor, Inc.
*
* This software is owned or controlled by Freescale Semiconductor.
* Use of this software is governed by the Freescale License
* distributed with this Material.
* See the LICENSE file distributed for more details.
* 
****************************************************************************//*!
*
* @brief  Main GDFLIB header file for devices without FPU.
* 
*******************************************************************************/
#ifndef _GDFLIB_H_
#define _GDFLIB_H_

#if defined(__cplusplus)
extern "C" {
#endif
  
/*******************************************************************************
* Includes
*******************************************************************************/
#include "GDFLIB_FilterIIR1_F32.h"
#include "GDFLIB_FilterIIR2_F32.h"   
#include "GDFLIB_FilterMA_A32.h"
#include "GDFLIB_FilterMA_A32_Asmi.h"

/*******************************************************************************
* Macros 
*******************************************************************************/
#define GDFLIB_FilterIIR1Init_F16(psParam)                                     \
        GDFLIB_FilterIIR1Init_F16_Ci(psParam)                                  
#define GDFLIB_FilterIIR1_F16(f16InX, psParam)                                 \
        GDFLIB_FilterIIR1_F16_Asm(f16InX, psParam)
#define GDFLIB_FilterIIR2Init_F16(psParam)                                     \
        GDFLIB_FilterIIR2Init_F16_C(psParam)                                  
#define GDFLIB_FilterIIR2_F16(f16InX, psParam)                                 \
        GDFLIB_FilterIIR2_F16_Asm(f16InX, psParam)
#define GDFLIB_FilterMAInit_F16(f16InitVal, psParam)                           \
        GDFLIB_FilterMAInit_F16_Ci(f16InitVal, psParam)                        
#define GDFLIB_FilterMA_F16(f16InX, psParam)                                   \
        GDFLIB_FilterMA_F16_Asmi(f16InX, psParam)

#if defined(__cplusplus)
}
#endif

#endif /* _GDFLIB_H_ */
