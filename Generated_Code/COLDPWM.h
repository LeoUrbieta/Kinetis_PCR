/* ###################################################################
**     This component module is generated by Processor Expert. Do not modify it.
**     Filename    : COLDPWM.h
**     Project     : PCR_Final
**     Processor   : MKE06Z128VLK4
**     Component   : PWM
**     Version     : Component 02.241, Driver 01.01, CPU db: 3.00.000
**     Repository  : Kinetis
**     Compiler    : GNU C Compiler
**     Date/Time   : 2017-04-19, 09:53, # CodeGen: 0
**     Abstract    :
**         This component implements a pulse-width modulation generator
**         that generates signal with variable duty and fixed cycle. 
**     Settings    :
**          Component name                                 : COLDPWM
**          PWM or PPG device                              : FTM2_C0V
**          Duty compare                                   : 
**          Output pin                                     : PTH0/KBI1_P24/FTM2_CH0
**          Counter                                        : FTM2_CNT
**          Interrupt service/event                        : Enabled
**            Interrupt                                    : INT_FTM2
**            Interrupt on duty                            : 
**            Interrupt overflow                           : INT_FTM2
**            Interrupt priority                           : medium priority
**            Iterations before action/event               : 1
**          Period                                         : 2 ms
**          Starting pulse width                           : 0 ms
**          Initial polarity                               : low
**          Same period in modes                           : no
**          Component uses entire timer                    : no
**          Initialization                                 : 
**            Enabled in init. code                        : yes
**            Events enabled in init.                      : yes
**          CPU clock/speed selection                      : 
**            High speed mode                              : This component enabled
**            Low speed mode                               : This component disabled
**            Slow speed mode                              : This component disabled
**          Referenced components                          : 
**            PWM_LDD                                      : PWM_LDD
**     Contents    :
**         Enable       - byte COLDPWM_Enable(void);
**         Disable      - byte COLDPWM_Disable(void);
**         EnableEvent  - byte COLDPWM_EnableEvent(void);
**         DisableEvent - byte COLDPWM_DisableEvent(void);
**         SetRatio16   - byte COLDPWM_SetRatio16(word Ratio);
**         SetValue     - byte COLDPWM_SetValue(void);
**         ClrValue     - byte COLDPWM_ClrValue(void);
**
**     Copyright : 1997 - 2015 Freescale Semiconductor, Inc. 
**     All Rights Reserved.
**     
**     Redistribution and use in source and binary forms, with or without modification,
**     are permitted provided that the following conditions are met:
**     
**     o Redistributions of source code must retain the above copyright notice, this list
**       of conditions and the following disclaimer.
**     
**     o Redistributions in binary form must reproduce the above copyright notice, this
**       list of conditions and the following disclaimer in the documentation and/or
**       other materials provided with the distribution.
**     
**     o Neither the name of Freescale Semiconductor, Inc. nor the names of its
**       contributors may be used to endorse or promote products derived from this
**       software without specific prior written permission.
**     
**     THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
**     ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
**     WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
**     DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR
**     ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
**     (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
**     LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON
**     ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
**     (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
**     SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
**     
**     http: www.freescale.com
**     mail: support@freescale.com
** ###################################################################*/
/*!
** @file COLDPWM.h
** @version 01.01
** @brief
**         This component implements a pulse-width modulation generator
**         that generates signal with variable duty and fixed cycle. 
*/         
/*!
**  @addtogroup COLDPWM_module COLDPWM module documentation
**  @{
*/         

#ifndef __COLDPWM_H
#define __COLDPWM_H

/* MODULE COLDPWM. */

/* Include shared modules, which are used for whole project */
#include "PE_Types.h"
#include "PE_Error.h"
#include "PE_Const.h"
#include "IO_Map.h"
/* Include inherited beans */
#include "PwmLdd2.h"

#include "Cpu.h"

#ifdef __cplusplus
extern "C" {
#endif 


#define COLDPWM_PERIOD_VALUE PwmLdd2_PERIOD_VALUE /* Initial period value in ticks of the timer. It is available only if the bean is enabled in high speed mode. */
#define COLDPWM_PERIOD_VALUE_HIGH PwmLdd2_PERIOD_VALUE_0 /* Period value in ticks of the timer in high speed mode. It is available only if the bean is enabled in high speed mode. */


/*
** ===================================================================
**     Method      :  COLDPWM_OnEnd (component PWM)
**
**     Description :
**         This method is internal. It is used by Processor Expert only.
** ===================================================================
*/
void PwmLdd2_OnEnd(LDD_TUserData *UserDataPtr);

/*
** ===================================================================
**     Method      :  COLDPWM_Enable (component PWM)
**     Description :
**         This method enables the component - it starts the signal
**         generation. Events may be generated (<DisableEvent>
**         /<EnableEvent>).
**     Parameters  : None
**     Returns     :
**         ---             - Error code, possible codes:
**                           ERR_OK - OK
**                           ERR_SPEED - This device does not work in
**                           the active speed mode
** ===================================================================
*/
#define COLDPWM_Enable() (PwmLdd2_Enable(PwmLdd2_DeviceData))

/*
** ===================================================================
**     Method      :  COLDPWM_Disable (component PWM)
**     Description :
**         This method disables the component - it stops the signal
**         generation and events calling. When the timer is disabled,
**         it is possible to call <ClrValue> and <SetValue> methods.
**     Parameters  : None
**     Returns     :
**         ---             - Error code, possible codes:
**                           ERR_OK - OK
**                           ERR_SPEED - This device does not work in
**                           the active speed mode
** ===================================================================
*/
#define COLDPWM_Disable() (PwmLdd2_Disable(PwmLdd2_DeviceData))

/*
** ===================================================================
**     Method      :  COLDPWM_EnableEvent (component PWM)
**     Description :
**         This method enables the events. The method is available only
**         if any event is selected.
**     Parameters  : None
**     Returns     :
**         ---             - Error code, possible codes:
**                           ERR_OK - OK
**                           ERR_SPEED - This device does not work in
**                           the active speed mode
** ===================================================================
*/
#define COLDPWM_EnableEvent() (PwmLdd2_SetEventMask(PwmLdd2_DeviceData, LDD_PWM_ON_END))

/*
** ===================================================================
**     Method      :  COLDPWM_DisableEvent (component PWM)
**     Description :
**         This method disables the events. The method is available
**         only if any event is selected.
**     Parameters  : None
**     Returns     :
**         ---             - Error code, possible codes:
**                           ERR_OK - OK
**                           ERR_SPEED - This device does not work in
**                           the active speed mode
** ===================================================================
*/
#define COLDPWM_DisableEvent() (PwmLdd2_SetEventMask(PwmLdd2_DeviceData, 0U))

/*
** ===================================================================
**     Method      :  COLDPWM_SetRatio16 (component PWM)
**     Description :
**         This method sets a new duty-cycle ratio. Ratio is expressed
**         as a 16-bit unsigned integer number. 0 - FFFF value is
**         proportional to ratio 0 - 100%. The method is available
**         only if it is not selected list of predefined values in
**         <Starting pulse width> property. 
**         Note: Calculated duty depends on the timer possibilities and
**         on the selected period.
**     Parameters  :
**         NAME            - DESCRIPTION
**         Ratio           - Ratio to set. 0 - 65535 value is
**                           proportional to ratio 0 - 100%
**     Returns     :
**         ---             - Error code, possible codes:
**                           ERR_OK - OK
**                           ERR_SPEED - This device does not work in
**                           the active speed mode
** ===================================================================
*/
#define COLDPWM_SetRatio16(Ratio) (PwmLdd2_SetRatio16(PwmLdd2_DeviceData, Ratio))

/*
** ===================================================================
**     Method      :  COLDPWM_SetValue (component PWM)
**     Description :
**         This method sets (set to "1" = "High") timer flip-flop
**         output signal level. It allows to the user to directly set
**         the output pin value (=flip-flop state), and can set the
**         signal polarity. This method only works when the timer is
**         disabled (<Disable> method) otherwise it returns the error
**         code. <ClrValue> and <SetValue> methods are used for setting
**         the initial state.
**     Parameters  : None
**     Returns     :
**         ---             - Error code, possible codes:
**                           ERR_OK - OK
**                           ERR_SPEED - This device does not work in
**                           the active speed mode
**                           ERR_ENABLED - Component is enabled.
**                           Component must be disabled (see "Disable
**                           method")
** ===================================================================
*/
#define COLDPWM_SetValue() (PwmLdd2_SetValue(PwmLdd2_DeviceData))

/*
** ===================================================================
**     Method      :  COLDPWM_ClrValue (component PWM)
**     Description :
**         This method clears (set to "0" = "Low") timer flip-flop
**         output signal level. It allows to the user to directly set
**         the output pin value (=flip-flop state), and can set the
**         signal polarity. This method only works when the timer is
**         disabled (<Disable> otherwise it returns the error code.
**         <ClrValue> and <SetValue> methods are used for setting the
**         initial state.
**     Parameters  : None
**     Returns     :
**         ---             - Error code, possible codes:
**                           ERR_OK - OK
**                           ERR_SPEED - This device does not work in
**                           the active speed mode
**                           ERR_ENABLED - Component is enabled.
**                           Component must be disabled (see "Disable
**                           method")
** ===================================================================
*/
#define COLDPWM_ClrValue() (PwmLdd2_ClearValue(PwmLdd2_DeviceData))

/* END COLDPWM. */

#ifdef __cplusplus
}  /* extern "C" */
#endif 

#endif 
/* ifndef __COLDPWM_H */
/*!
** @}
*/
/*
** ###################################################################
**
**     This file was created by Processor Expert 10.5 [05.21]
**     for the Freescale Kinetis series of microcontrollers.
**
** ###################################################################
*/
