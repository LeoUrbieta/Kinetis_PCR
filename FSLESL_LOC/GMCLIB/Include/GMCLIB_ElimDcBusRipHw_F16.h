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
* @brief  Elimination of the DC-Bus voltage ripple for FOC
* 
*******************************************************************************/
#ifndef _GMCLIB_ELIMDCBUSRIPHW_F16_H_
#define _GMCLIB_ELIMDCBUSRIPHW_F16_H_

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
#define GMCLIB_ElimDcBusRipFOCHw_F16_C(f16UDCBus, psUAlBe, psUAlBeComp)   \
        GMCLIB_ElimDcBusRipFOCHw_F16_FC(f16UDCBus, psUAlBe, psUAlBeComp)                        
#define GMCLIB_ElimDcBusRipFOCHw_F16_Asm(f16UDCBus, psUAlBe, psUAlBeComp) \
	GMCLIB_ElimDcBusRipFOCHw_F16_FAsm(f16UDCBus, psUAlBe, psUAlBeComp, &gu16CntMmdvsq)
/*******************************************************************************
* Exported function prototypes
*******************************************************************************/
extern void GMCLIB_ElimDcBusRipFOCHw_F16_FC(frac16_t f16UDCBus,
                                            const GMCLIB_2COOR_ALBE_T_F16 *psUAlBe,
                                            GMCLIB_2COOR_ALBE_T_F16 *psUAlBeComp);
extern void GMCLIB_ElimDcBusRipFOCHw_F16_FAsm(frac16_t f16UDCBus,
                                            const GMCLIB_2COOR_ALBE_T_F16 *psUAlBe,
                                            GMCLIB_2COOR_ALBE_T_F16 *psUAlBeComp,
                                            const volatile uint16_t *pVal);

#if defined(__cplusplus) 
}
#endif

#endif  /* _GMCLIB_ELIMDCBUSRIPHW_F16_H_ */
