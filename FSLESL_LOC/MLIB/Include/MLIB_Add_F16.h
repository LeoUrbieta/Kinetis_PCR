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
* @brief  Addition
* 
*******************************************************************************/
#ifndef _MLIB_ADD_F16_H_
#define _MLIB_ADD_F16_H_

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
#define MLIB_Add_F16_Ci(f16Add1, f16Add2)    MLIB_Add_F16_FCi(f16Add1, f16Add2) 
#define MLIB_AddSat_F16_Ci(f16Add1, f16Add2) MLIB_AddSat_F16_FCi(f16Add1, f16Add2)  
  
/***************************************************************************//*!
*  Addition        
*  f16Out = f16Add1 + f16Add2
*  function is not saturated
*******************************************************************************/
static inline frac16_t MLIB_Add_F16_FCi(register frac16_t f16Add1, register frac16_t f16Add2)
{
    return((frac16_t)(f16Add1 + f16Add2));
}

/***************************************************************************//*!
*  Saturated Addition      
*  f16Out = f16Add1 + f16Add2
*******************************************************************************/
static inline frac16_t MLIB_AddSat_F16_FCi(register frac16_t f16Add1, register frac16_t f16Add2)
{
    register int32_t i32z;
    
    i32z = (int32_t)((frac32_t)f16Add1 + (frac32_t)f16Add2); 
    i32z = (i32z > ((int32_t)(INT16_MAX))) ? ((int32_t)(INT16_MAX)) : i32z;
    i32z = (i32z < ((int32_t)(INT16_MIN))) ? ((int32_t)(INT16_MIN)) : i32z;
    return((frac16_t)(i32z)); 
}

#if defined(__cplusplus)
}
#endif

#endif  /*_MLIB_ADD_F16_H_*/
