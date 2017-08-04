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
* @brief  Elimination of the DC-Bus voltage ripple with index
* 
*******************************************************************************/
#ifndef _GMCLIB_ELIMDCBUSRIPHW_A32_H_
#define _GMCLIB_ELIMDCBUSRIPHW_A32_H_

#if defined(__cplusplus) 
extern "C" {
#endif

/*******************************************************************************
* Includes
*******************************************************************************/  
#include "mlib.h"
#include "gmclib_types.h"  

/*******************************************************************************
* Macros 
*******************************************************************************/     
#define GMCLIB_ElimDcBusRipHw_F16sas_C(f16UDCBus, a32IdxMod, psUAlBe, psUAlBeComp) \
        GMCLIB_ElimDcBusRipHw_F16sas_FC(f16UDCBus, a32IdxMod, psUAlBe, psUAlBeComp)
#define GMCLIB_ElimDcBusRipHw_F16sas_Asm(f16UDCBus, a32IdxMod, psUAlBe, psUAlBeComp) \
        GMCLIB_ElimDcBusRipHw_F16sas_FAsm(f16UDCBus, a32IdxMod, psUAlBe, &gu16CntMmdvsq, psUAlBeComp)
/*******************************************************************************
* Exported function prototypes
*******************************************************************************/
extern void GMCLIB_ElimDcBusRipHw_F16sas_FC(frac16_t f16UDCBus,
                                            acc32_t a32IdxMod, 
                                            const GMCLIB_2COOR_ALBE_T_F16 *psUAlBe,
                                            GMCLIB_2COOR_ALBE_T_F16 *psUAlBeComp);
extern void GMCLIB_ElimDcBusRipHw_F16sas_FAsm(frac16_t f16UDCBus,
                                              acc32_t a32IdxMod,
                                              const GMCLIB_2COOR_ALBE_T_F16 *psUAlBe,
                                              const volatile uint16_t *pVal,
                                              GMCLIB_2COOR_ALBE_T_F16 *psUAlBeComp);

#if defined(__cplusplus) 
}
#endif

#endif  /* _GMCLIB_ELIMDCBUSRIPHW_A32_H_ */
