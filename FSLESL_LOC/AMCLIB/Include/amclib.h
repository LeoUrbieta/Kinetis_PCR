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
* @brief Main AMCLIB header file for devices without FPU.  
* 
*******************************************************************************/
#ifndef _AMCLIB_H_
#define _AMCLIB_H_

#if defined(__cplusplus) 
extern "C" {
#endif	
  
/*******************************************************************************
* Includes
*******************************************************************************/
#include "mlib.h"    
#include "AMCLIB_AngleTrackObsrv_F32.h"    
#include "AMCLIB_PMSMBemfObsrvDQ_A32.h"
#include "AMCLIB_TrackObsrv_F32.h"  

#include "AMCLIB_PMSMBemfObsrvDQHw_A32.h"
    
/*******************************************************************************
* Macros 
*******************************************************************************/        
#define AMCLIB_AngleTrackObsrvInit_F16(f16ThetaInit, psCtrl)                   \
        AMCLIB_AngleTrackObsrvInit_F16_C(f16ThetaInit, psCtrl)          
#define AMCLIB_AngleTrackObsrv_F16(f16ThetaErr, psCtrl)                        \
        AMCLIB_AngleTrackObsrv_F16_C(f16ThetaErr, psCtrl)              
#define AMCLIB_PMSMBemfObsrvDQInit_F16(psCtrl)                                 \
        AMCLIB_PMSMBemfObsrvDQInit_F16_Ci(psCtrl)
#define AMCLIB_TrackObsrvInit_F16(f16ThetaInit, psCtrl)                        \
        AMCLIB_TrackObsrvInit_F16_Ci(f16ThetaInit, psCtrl)           
#define AMCLIB_TrackObsrv_F16(f16ThetaErr, psCtrl)                             \
        AMCLIB_TrackObsrv_F16_Asm(f16ThetaErr, psCtrl)  
        
#if (FSLESL_MMDVSQ)     
#define AMCLIB_PMSMBemfObsrvDQ_F16(psIDQ, psUDQ, f16Speed, psCtrl)             \
        AMCLIB_PMSMBemfObsrvDQHw_F16_Asm(psIDQ, psUDQ, f16Speed, psCtrl)
#else            
#define AMCLIB_PMSMBemfObsrvDQ_F16(psIDQ, psUDQ, f16Speed, psCtrl)             \
        AMCLIB_PMSMBemfObsrvDQ_F16_Asm(psIDQ, psUDQ, f16Speed, psCtrl)
#endif            
            
#if defined(__cplusplus) 
}
#endif

#endif /* _AMCLIB_H_ */ 
