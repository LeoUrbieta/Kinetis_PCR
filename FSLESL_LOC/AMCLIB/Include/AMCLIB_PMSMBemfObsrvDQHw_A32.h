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
* @brief  Algorithm of PMSM Back Electromotive Force observer in rotating 
*         reference frame     
* 
*******************************************************************************/
#ifndef _AMCLIB_PMSM_BEMF_OBSRVHW_A32_DQ_H_
#define _AMCLIB_PMSM_BEMF_OBSRVHW_A32_DQ_H_

#if defined(__cplusplus) 
extern "C" {
#endif

/*******************************************************************************
* Includes
*******************************************************************************/
#include "mlib.h"
#include "gflib.h"
#include "AMCLIB_PMSMBemfObsrvDQ_A32.h"   
#include "GFLIB_AtanYXHw_A32.h"
    
/*******************************************************************************
* Macros 
*******************************************************************************/    
#define AMCLIB_PMSMBemfObsrvDQHw_F16_C(psIDQ, psUDQ, f16Speed, psCtrl)       \
        AMCLIB_PMSMBemfObsrvDQHw_F16_FC(psIDQ, psUDQ, f16Speed, psCtrl)
#define AMCLIB_PMSMBemfObsrvDQHw_F16_Asm(psIDQ, psUDQ, f16Speed, psCtrl)     \
        AMCLIB_PMSMBemfObsrvDQHw_F16_FAsm(psIDQ, psUDQ, f16Speed, psCtrl)

/*******************************************************************************
* Types
*******************************************************************************/

   
/*******************************************************************************
* Exported function prototypes
*******************************************************************************/
extern frac16_t AMCLIB_PMSMBemfObsrvDQHw_F16_FC(const GMCLIB_2COOR_DQ_T_F16 *psIDQ,
                                                const GMCLIB_2COOR_DQ_T_F16 *psUDQ,
                                                frac16_t f16Speed, 
                                                AMCLIB_BEMF_OBSRV_DQ_T_A32 *psCtrl);

extern frac16_t AMCLIB_PMSMBemfObsrvDQHw_F16_FAsm(const GMCLIB_2COOR_DQ_T_F16 *psIDQ,
                                                  const GMCLIB_2COOR_DQ_T_F16 *psUDQ,
                                                  frac16_t f16Speed,
                                                  AMCLIB_BEMF_OBSRV_DQ_T_A32 *psCtrl);
#if defined(__cplusplus) 
}
#endif

#endif /* _AMCLIB_PMSM_BEMF_OBSRVHW_A32_DQ_H_ */       
