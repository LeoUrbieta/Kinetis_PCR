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
* @brief  MLIB_MMDVSQ.h
* 
*******************************************************************************/
#if defined(__cplusplus)
extern "C" {
#endif

/******************************************************************************
* Includes
******************************************************************************/   
#include "mlib_types.h"

/*******************************************************************************
* Macros
*******************************************************************************/    
/* Base adress of Memory-Mapped Divide and Square Root peripheral module(MMDVSQ) */ 
#define FSLESL_MMDVSQ_BASE_PTR 0xF0004000   

/* MMDVSQ registers definitions
*  Absolute      Register name                        Width      Access Reset value
*  address (hex)                                      (in bits)
*  F000_4000     Dividend Register (MMDVSQ_DEND)      32         R/W    Undefined
*  F000_4004     Divisor Register (MMDVSQ_DSOR)       32         R/W    Undefined
*  F000_4008     Control/Status Register (MMDVSQ_CSR) 32         R/W    Some bits undefined
*  F000_400C     Result Register (MMDVSQ_RES)         32         R/W    Undefined
*  F000_4010     Radicand Register (MMDVSQ_RCND)      32         W      Undefined    */
    
#define FSLESL_MMDVSQ_DEND  *(volatile unsigned int*)(FSLESL_MMDVSQ_BASE_PTR + 0x0)
#define FSLESL_MMDVSQ_DSOR  *(volatile unsigned int*)(FSLESL_MMDVSQ_BASE_PTR + 0x4)
#define FSLESL_MMDVSQ_CSR   *(volatile unsigned int*)(FSLESL_MMDVSQ_BASE_PTR + 0x8)
#define FSLESL_MMDVSQ_RES   *(volatile unsigned int*)(FSLESL_MMDVSQ_BASE_PTR + 0xC)
#define FSLESL_MMDVSQ_RCND  *(volatile unsigned int*)(FSLESL_MMDVSQ_BASE_PTR + 0x10)

/*******************************************************************************
* Variables
*******************************************************************************/    
/* Global variable which store actual MMDVSQ state to avoid register 
   rewriting during interrupt service routine handling */  
extern volatile uint16_t gu16CntMmdvsq;  

#if defined(__cplusplus)
}
#endif


