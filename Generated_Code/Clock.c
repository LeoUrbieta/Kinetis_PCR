/* ###################################################################
**     This component module is generated by Processor Expert. Do not modify it.
**     Filename    : Clock.c
**     Project     : PCR_Final
**     Processor   : MKE06Z128VLK4
**     Component   : RealTime_LDD
**     Version     : Component 01.007, Driver 01.01, CPU db: 3.00.000
**     Repository  : Kinetis
**     Compiler    : GNU C Compiler
**     Date/Time   : 2017-04-19, 09:53, # CodeGen: 0
**     Abstract    :
**          This component "RealTime_LDD" implements a free running counter
**          for time measurement.
**          This RealTime component provides a high level API for unified
**          hardware access to various timer devices using the TimerUnit
**          component.
**     Settings    :
**          Component name                                 : Clock
**          Periodic interrupt source                      : FTM0_C0V
**          Counter                                        : FTM0_CNT
**          Interrupt service/event                        : Enabled
**            Interrupt                                    : INT_FTM0
**            Interrupt priority                           : medium priority
**          Resolution                                     : 2.730667 ms
**          SW counter                                     : 32-bit
**          Maximum time of event                          : 11728052.4468224 sec
**          Initialization                                 : 
**            Enabled in init. code                        : yes
**            Auto initialization                          : no
**          CPU clock/configuration selection              : 
**            Clock configuration 0                        : This component enabled
**            Clock configuration 1                        : This component disabled
**            Clock configuration 2                        : This component disabled
**            Clock configuration 3                        : This component disabled
**            Clock configuration 4                        : This component disabled
**            Clock configuration 5                        : This component disabled
**            Clock configuration 6                        : This component disabled
**            Clock configuration 7                        : This component disabled
**          Referenced components                          : 
**            Linked TimerUnit                             : TU2
**     Contents    :
**         Init        - LDD_TDeviceData* Clock_Init(LDD_TUserData *UserDataPtr);
**         Reset       - LDD_TError Clock_Reset(LDD_TDeviceData *DeviceDataPtr);
**         GetTimeMS   - LDD_TError Clock_GetTimeMS(LDD_TDeviceData *DeviceDataPtr, uint16_t *TimePtr);
**         GetTimeReal - LDD_TError Clock_GetTimeReal(LDD_TDeviceData *DeviceDataPtr,...
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
** @file Clock.c
** @version 01.01
** @brief
**          This component "RealTime_LDD" implements a free running counter
**          for time measurement.
**          This RealTime component provides a high level API for unified
**          hardware access to various timer devices using the TimerUnit
**          component.
*/         
/*!
**  @addtogroup Clock_module Clock module documentation
**  @{
*/         

/* MODULE Clock. */

#include "Clock.h"
/* {Default RTOS Adapter} No RTOS includes */

#ifdef __cplusplus
extern "C" {
#endif 

typedef struct {
  LDD_TDeviceData *LinkedDeviceDataPtr;
  bool EnUser;                         /* Enable/Disable device */
  uint32_t TimerTicks;                 /* Counter of timer ticks */
  bool Overflow;                       /* Counter overflow flag */
  uint16_t CmpVal;                     /* Value periodically addded to compare register */
  LDD_TUserData *UserDataPtr;          /* RTOS device data structure */
} Clock_TDeviceData;

typedef Clock_TDeviceData *Clock_TDeviceDataPtr; /* Pointer to the device data structure. */

/* {Default RTOS Adapter} Static object used for simulation of dynamic driver memory allocation */
static Clock_TDeviceData DeviceDataPrv__DEFAULT_RTOS_ALLOC;

#define CHANNEL 0x00U
/*
** ===================================================================
**     Method      :  Clock_Init (component RealTime_LDD)
*/
/*!
**     @brief
**         Initializes the device. Allocates memory for the device data
**         structure, allocates interrupt vectors and sets interrupt
**         priority, sets pin routing, sets timing, etc. If the
**         property ["Enable in init. code"] is set to "yes" value then
**         the device is also enabled (see the description of the
**         [Enable] method). In this case the [Enable] method is not
**         necessary and needn't to be generated. This method can be
**         called only once. Before the second call of Init the [Deinit]
**         must be called first.
**     @param
**         UserDataPtr     - Pointer to the user or
**                           RTOS specific data. This pointer will be
**                           passed as an event or callback parameter.
**     @return
**                         - Pointer to the dynamically allocated private
**                           structure or NULL if there was an error.
*/
/* ===================================================================*/
LDD_TDeviceData* Clock_Init(LDD_TUserData *UserDataPtr)
{
  /* Allocate device structure */
  Clock_TDeviceData *DeviceDataPrv;
  /* {Default RTOS Adapter} Driver memory allocation: Dynamic allocation is simulated by a pointer to the static object */
  DeviceDataPrv = &DeviceDataPrv__DEFAULT_RTOS_ALLOC;
  DeviceDataPrv->UserDataPtr = UserDataPtr; /* Store the RTOS device structure */
  DeviceDataPrv->TimerTicks = 0U;      /* Counter of timer ticks */
  DeviceDataPrv->Overflow = FALSE;     /* Counter overflow flag */
  DeviceDataPrv->EnUser = TRUE;        /* Set the flag "device enabled" */
  DeviceDataPrv->CmpVal = 0xD555U;     /* Initial value periodically addded to compare register */
  /* Registration of the device structure */
  PE_LDD_RegisterDeviceStructure(PE_LDD_COMPONENT_Clock_ID,DeviceDataPrv);
  DeviceDataPrv->LinkedDeviceDataPtr = TU2_Init((LDD_TUserData *)NULL);
  if (DeviceDataPrv->LinkedDeviceDataPtr == NULL) { /* Is initialization of TimerUnit unsuccessful? */
    /* Unregistration of the device structure */
    PE_LDD_UnregisterDeviceStructure(PE_LDD_COMPONENT_Clock_ID);
    /* Deallocation of the device structure */
    /* {Default RTOS Adapter} Driver memory deallocation: Dynamic allocation is simulated, no deallocation code is generated */
    return NULL;                       /* If so, then the TimeDate initialization is also unsuccessful */
  }
  (void)TU2_SetEventMask(DeviceDataPrv->LinkedDeviceDataPtr, TU2_GetEventMask(DeviceDataPrv->LinkedDeviceDataPtr) | LDD_TIMERUNIT_ON_CHANNEL_0); /* Enable TimerUnit event */
  return ((LDD_TDeviceData *)DeviceDataPrv); /* Return pointer to the device data structure */
}

/*
** ===================================================================
**     Method      :  Clock_Reset (component RealTime_LDD)
*/
/*!
**     @brief
**         This method resets software counter.
**     @param
**         DeviceDataPtr   - Device data structure
**                           pointer returned by [Init] method.
**     @return
**                         - Error code, possible codes:
**                           ERR_OK - OK
**                           ERR_SPEED - This device does not work in
**                           the active clock configuration
*/
/* ===================================================================*/
LDD_TError Clock_Reset(LDD_TDeviceData *DeviceDataPtr)
{
  Clock_TDeviceData *DeviceDataPrv = (Clock_TDeviceData *)DeviceDataPtr;

  /* {Default RTOS Adapter} Critical section begin, general PE function is used */
  EnterCritical();
  (void)TU2_SetOffsetTicks(DeviceDataPrv->LinkedDeviceDataPtr, CHANNEL, TU2_GetCounterValue(DeviceDataPrv->LinkedDeviceDataPtr) + DeviceDataPrv->CmpVal);
  DeviceDataPrv->TimerTicks =  0U;     /* Reset counter of timer ticks */
  DeviceDataPrv->Overflow = FALSE;     /* Reset counter overflow flag */
  /* {Default RTOS Adapter} Critical section end, general PE function is used */
  ExitCritical();
  return ERR_OK;
}

/*
** ===================================================================
**     Method      :  Clock_GetTimeMS (component RealTime_LDD)
*/
/*!
**     @brief
**         This method returns the time (as a 16-bit unsigned integer)
**         in milliseconds since the last Reset method call.
**     @param
**         DeviceDataPtr   - Device data structure
**                           pointer returned by [Init] method.
**     @param
**         TimePtr         - A pointer to the returned 16-bit
**                           value in milliseconds
**     @return
**                         - Error code, possible codes:
**                           ERR_OK - OK
**                           ERR_SPEED - This device does not work in
**                           the active clock configuration
**                           ERR_OVERFLOW - Software counter overflow
**                           ERR_MATH - Overflow during evaluation
*/
/* ===================================================================*/
LDD_TError Clock_GetTimeMS(LDD_TDeviceData *DeviceDataPtr, uint16_t *TimePtr)
{
  Clock_TDeviceData *DeviceDataPrv = (Clock_TDeviceData *)DeviceDataPtr;
  uint32_t CopyTicks;                  /* Working copy of variable TimerTicks */
  bool CopyOverflow;                   /* Working copy of variable Overflow */
  LDD_RealTime_Tfloat rtval;           /* Result of multiplication */

  /* {Default RTOS Adapter} Critical section begin, general PE function is used */
  EnterCritical();
  CopyTicks = DeviceDataPrv->TimerTicks; /* Loading actual number of timer ticks */
  CopyOverflow = DeviceDataPrv->Overflow; /* Loading actual state of "overflow flag" */
  /* {Default RTOS Adapter} Critical section end, general PE function is used */
  ExitCritical();
  if (CopyOverflow) {                  /* Testing counter overflow */
    return ERR_OVERFLOW;               /* If yes then error */
  }
  rtval = CopyTicks * 2.73065F;        /* Multiply ticks and clock configuration 0 coefficient */
  if (rtval > 0xFFFFUL) {              /* Is the result greater than 65535 ? */
    return ERR_MATH;                   /* If yes then error */
  }
  else {
    *TimePtr = (uint16_t)rtval;
  }
  return ERR_OK;
}

/*
** ===================================================================
**     Method      :  Clock_GetTimeReal (component RealTime_LDD)
*/
/*!
**     @brief
**         This method returns the time (as a floating point) in
**         seconds since the last Reset method call.
**     @param
**         DeviceDataPtr   - Device data structure
**                           pointer returned by [Init] method.
**     @param
**         TimePtr         - A pointer to the returned floating
**                           point value in seconds
**     @return
**                         - Error code, possible codes:
**                           ERR_OK - OK
**                           ERR_SPEED - This device does not work in
**                           the active speed mode
**                           ERR_OVERFLOW - Software counter overflow
**                           ERR_MATH - Overflow during evaluation
*/
/* ===================================================================*/
LDD_TError Clock_GetTimeReal(LDD_TDeviceData *DeviceDataPtr, LDD_RealTime_Tfloat *TimePtr)
{
  Clock_TDeviceData *DeviceDataPrv = (Clock_TDeviceData *)DeviceDataPtr;
  uint32_t CopyTicks;                  /* Working copy of variable TimerTicks */
  bool CopyOverflow;                   /* Working copy of variable Overflow */

  /* {Default RTOS Adapter} Critical section begin, general PE function is used */
  EnterCritical();
  CopyTicks = DeviceDataPrv->TimerTicks; /* Loading actual number of timer ticks */
  CopyOverflow = DeviceDataPrv->Overflow; /* Loading actual state of "overflow flag" */
  /* {Default RTOS Adapter} Critical section end, general PE function is used */
  ExitCritical();
  if (CopyOverflow) {                  /* Testing counter overflow */
    return ERR_OVERFLOW;               /* If yes then error */
  }
  *TimePtr = (LDD_RealTime_Tfloat)CopyTicks * 0.00273065F; /* Multiply ticks and clock configuration 0 coefficient */
  return ERR_OK;
}

/*
** ===================================================================
**     Method      :  Clock_TU2_OnChannel0 (component RealTime_LDD)
**
**     Description :
**         The method services the event of the linked component TU2.
**         This method is internal. It is used by Processor Expert only.
** ===================================================================
*/
void TU2_OnChannel0(LDD_TUserData *UserDataPtr)
{
  Clock_TDeviceData *DeviceDataPrv = PE_LDD_DeviceDataList[PE_LDD_COMPONENT_Clock_ID];
  uint16_t Ticks;

  (void)UserDataPtr;                   /* Parameter is not used, suppress unused argument warning */
  (void)TU2_GetOffsetTicks(DeviceDataPrv->LinkedDeviceDataPtr, CHANNEL, &Ticks);
  Ticks += DeviceDataPrv->CmpVal;
  (void)TU2_SetOffsetTicks(DeviceDataPrv->LinkedDeviceDataPtr, CHANNEL, Ticks);
  DeviceDataPrv->TimerTicks++;         /* Increment counter of timer ticks */
  if (DeviceDataPrv->TimerTicks == 0U) { /* Testing counter overflow */
    DeviceDataPrv->Overflow = TRUE;    /* If yes then set overflow flag */
  }
}

/* END Clock. */

#ifdef __cplusplus
}  /* extern "C" */
#endif 

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
