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
* @brief  FSLESL configuration file
* 
*******************************************************************************/
#ifndef _FSLESL_CFG_H_
#define _FSLESL_CFG_H_

#if defined(__cplusplus)
extern "C" {
#endif

/*******************************************************************************
* Macros 
*******************************************************************************/  
#define FSLESL_ON 1
#define FSLESL_OFF 0    
    
/*******************************************************************************
* User Modified Macros 
*******************************************************************************/     
/* Memory-Mapped Divide and Square Root Module (MMDVSQ) FSLESL_ON/FSLESL_OFF   
*  configuration. It is recommended to use MMDVSQ for KV1x devices, because Div,  
*  Rcp and Sqrt operations are quicker. */
    
/* The MMDVSQ can be enabled or disabled by the definition of thesymbol in IDE
*  preprocessor setting.
*  To enable MMDVSQ module please define symbol: FSLESL_MMDVSQ_ON, to disable FSLESL_MMDVSQ please
*  define FSLESL_MMDVSQ_OFF (Div,Rcp of Sqrt functions which use them  will be
*  calculated by core).
*  If no symbol FSLESL_MMDVSQ_XXX is defined the FSLESL_MMDVSQ setting will be taken from 
*  this header file, see next paragraph. */
    
#if (defined (FSLESL_MMDVSQ_ON))   
    #define FSLESL_MMDVSQ FSLESL_ON
#elif (defined (FSLESL_MMDVSQ_OFF))
    #define FSLESL_MMDVSQ FSLESL_OFF
#else    
    /* User option to enable or disable MMDVSQ module when IDE preprocessor setting 
    *  was not used. Set the following define as FSLESL_ON or FSLESL_OFF to enable or  
    *  disable hardware MMDVSQ support. */  
    
    /* Next line can be modified by user */
    #define FSLESL_MMDVSQ FSLESL_OFF     
    
    /* Independent function call can be used as well, for example
    *  MLIB_Div_F16 ... depend on setting
    *  MLIB_DivHw_F16_C always make calculation in MMDVSQ module
    *  MLIB_Div_F16_Ci always make calculation in core */ 
#endif     

/* Warning if FSLESL_MMDVSQ was not correctly defined */   
#ifndef FSLESL_MMDVSQ 
    #warning "FSLESL_MMDVSQ was not defined !" 
#endif    
/* Warning if FSLESL_MMDVSQ_ON and FSLESL_MMDVSQ_OFF are defined in IDE */       
#if defined(FSLESL_MMDVSQ_ON) && defined(FSLESL_MMDVSQ_OFF)    
    #warning "FSLESL_MMDVSQ_ON and FSLESL_MMDVSQ_OFF are defined !" 
#endif        
    
#endif  /*_FSLESL_CFG_H_*/
