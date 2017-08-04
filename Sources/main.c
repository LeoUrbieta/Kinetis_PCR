/* ###################################################################
 **     Filename    : main.c
 **     Project     : PCR
 **     Processor   : MKE06Z128VLK4
 **     Version     : Driver 01.01
 **     Compiler    : GNU C Compiler
 **     Date/Time   : 2016-07-25, 19:48, # CodeGen: 0
 **     Abstract    :
 **         Main module.
 **         This module contains user's application code.
 **     Settings    :
 **     Contents    :
 **         No public methods
 **
 ** ###################################################################*/
/*!
 ** @file main.c
 ** @version 01.01
 ** @brief
 **         Main module.
 **         This module contains user's application code.
 */
/*!
 **  @addtogroup main_module main module documentation
 **  @{
 */
/* MODULE main */


/* Including needed modules to compile this module/procedure */
#include "Cpu.h"
#include "Events.h"
#include "LidPWM.h"
#include "PwmLdd1.h"
#include "Pins1.h"
#include "Term1.h"
#include "Inhr1.h"
#include "ASerialLdd1.h"
#include "AD1.h"
#include "HOTPWM.h"
#include "PwmLdd3.h"
#include "Ventilador.h"
#include "BitIoLdd6.h"
#include "Enable2.h"
#include "BitIoLdd7.h"
#include "COLDPWM.h"
#include "PwmLdd2.h"
#include "TU1.h"
#include "UTIL1.h"
#include "MCUC1.h"
#include "Clock.h"
#include "TU2.h"
#include "LEDGREEN.h"
#include "BitIoLdd3.h"
#include "LEDRED.h"
#include "BitIoLdd4.h"
#include "LEDBLUE.h"
#include "BitIoLdd5.h"
/* Including shared modules, which are used for whole project */
#include "PE_Types.h"
#include "PE_Error.h"
#include "PE_Const.h"
#include "IO_Map.h"
#include "PDD_Includes.h"
#include "Init_Config.h"
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include "mlib.h"
#include "pclib.h"

/* User includes (#include below this line is not maintained by Processor Expert) */
const float Vin = 3.127;
const float ADC = 4096.0;
const float Rdiv = 10000.0;  //9810
const float Rdiv2 = 10000.0; //9900
float tempDenatInicial = 95.0;
float TempDenat = 95.0;
float TempPrimers = 58.0;
float TempAnnealing = 72.0;
float tempAnnealingFinal = 72.0;
const float PWMMax = 65535.0;
const float PWMMaxLid = 35400;
const float PWMMin = 0.0;
const float tempLid = 105.0;
float temperature[2];
uint16_t volatile valueVolt[2];
int32_t numCiclos = 30;

LDD_TDeviceData *RelojCicloPCR;
LDD_TDeviceData *RelojTotal;
LDD_TDeviceData *ADCTemp;
LDD_TDeviceData *MyADCPtr;

static PCLIB_CTRL_PID_T_F16 sParam;

float tiempoCicloPCR = 0.0;
float tiempoTotal = 0.0;
float tiempoDenat = 30.0; //30
float tiempoPrimers = 40.0; // 40
float tiempoAnnealing = 45.0; // 45
float tiempoInitDenat = 120.0;
float tiempoFinalExtension = 30.0;
float volatile ratio = 65535.0;
float volatile ratioLid = 0.0;
float volatile ratioCold = 65535.0;

int ciclo = 0;
int escalon = -1;
float proportionalBand = 1.0;

const float a = 15269.948;
const float b = -15269.547;
const float c = 0.0;

float u0 = 0;
float u1 = 0;
float e1 = 0;
float e0 = 0;
float e2 = 0;

unsigned char tempsEnviadas[32];
volatile bool interruptRXActivado = FALSE;

int32_t infoCiclo[12];
unsigned char infoCicloString[40];
unsigned char buf[40];
const unsigned char *j;


float pid(float temp)
{

	e0 = temp - temperature[1];
	u1 = u0 + a * e0 + b * e1 + c * e2;

	u0 = u1;
	e2 = e1;
	e1 = e0;


	if(u1 > PWMMaxLid){
		return PWMMaxLid;
	}
	if(u1 < PWMMin){
		return PWMMin;
	}

	return u1;
}

void printToConsole(void){

	UTIL1_strcatNumFloat(tempsEnviadas, sizeof(tempsEnviadas), temperature[0], 1);
	UTIL1_chcat(tempsEnviadas, sizeof(tempsEnviadas), 32);
	UTIL1_strcatNumFloat(tempsEnviadas, sizeof(tempsEnviadas), temperature[1], 1);
	UTIL1_chcat(tempsEnviadas, sizeof(tempsEnviadas), 32);
	UTIL1_strcatNum8u(tempsEnviadas, sizeof(tempsEnviadas), ciclo);
	UTIL1_chcat(tempsEnviadas, sizeof(tempsEnviadas), 32);
	UTIL1_strcatNum8u(tempsEnviadas, sizeof(tempsEnviadas), escalon);
	UTIL1_chcat(tempsEnviadas,sizeof(tempsEnviadas),13);
	UTIL1_chcat(tempsEnviadas,sizeof(tempsEnviadas),10);
	Term1_SendStr(tempsEnviadas);
	memset(tempsEnviadas,0,strlen(tempsEnviadas));
	tempsEnviadas[0] = '\0';

}

void ObtainTemp(float ADCInt, float VinInt, float rdivInt, float rdivInt2 ){

	float resActInt;
	float voltageInt;
	float TempInt;
	float TempIntLid;
	float resActIntLid;
	float voltageIntLid;
	float temperatureBase;
	float temperatureLid;

	/************************************************************
	 * Measuring temperature without using interrupts but rather polling mode
	//Temp_Measure(TRUE);
	//Temp_GetValue((uint16_t*)valueVolt);

	 *************************************************************/
	//Obtain voltage from the read measurement of Thermistor
	voltageInt = (valueVolt[0] / ADCInt) * VinInt;
	voltageIntLid = (valueVolt[1] / ADCInt) * VinInt;

	//Obtain Resistance of the thermistor
	resActInt = (rdivInt * voltageInt) / (VinInt - voltageInt);
	resActIntLid = (rdivInt2 * voltageIntLid) / (VinInt - voltageIntLid);

	//Obtain Temperature from a linearization of the thermistor behavior.
	temperatureBase = (log(resActInt) - 13.477) / -0.04 - 6.0;
	temperatureLid = (log(resActIntLid) - 13.477) / -0.04 - 6.0;

	//Finally calibrate to thermocouple measurements
	//temperature[0] = (1.16 * temperatureBase - 10.33) + 1.0;
	//temperature[1] = (1.16 * temperatureLid - 10.33) + 1.0;
	//temperature[0] = 1.14 * temperatureBase - 7.71;
	//temperature[1] = 1.14 * temperatureLid - 7.71; Este renglón y el anterior corresponden a calibracion con termopar
	temperature[0] = temperatureBase + (0.093*temperatureBase - 2.554); //0.932 * ((temperatureBase - 0.707) / 1.008) + 2.75;
	temperature[1] = temperatureLid + (0.093*temperatureLid - 2.554);//0.932 * ((temperatureLid - 0.707) / 1.008) + 2.75;
}

float EstableceTemperaturaCiclo(float nuevaTemp){
	return nuevaTemp;
}

float PIDControl(float temp) {

	float errortemp, result, quotient, scaledResult;
	frac16_t resultado, errorPID;

	errortemp = (temp-temperature[0]) / proportionalBand ;
	errorPID = FRAC16(errortemp);
	if(errortemp < -1.0){
		errorPID = -32768.0;
	}
	resultado = PCLIB_CtrlPID_F16(errorPID, &sParam);
	result = resultado / 32768.0 ;
	quotient = PWMMax - result * PWMMax;

	if(quotient < PWMMin){
		return PWMMin;
	}

	return quotient;
}

void ChecarLid(float temperaturaCiclo) {
	ratioLid = pid(temperaturaCiclo);
}

void HeatLid(float temperaturaCiclo){

	if(temperature[1] < tempLid) {
		ratioLid = 65535.0;
		while(temperature[1] < 65.0){
			ObtainTemp(ADC, Vin, Rdiv, Rdiv2);
			printToConsole();
		}
		ratioLid = 65535.0; //Disminuir el ratio de 65535 a 450000 para evitar que la resistencia se queme.
		while(temperature[1] < tempLid){
			ObtainTemp(ADC, Vin, Rdiv, Rdiv2);
			printToConsole();
		}
	}
	for(int i = 0 ; i < 1000 ; i++) { //Esperar un tiempo antes de encender la Peltier.
		ObtainTemp(ADC, Vin, Rdiv, Rdiv2);
		ChecarLid(tempLid);
		printToConsole();
	}
}


void DenaturationCycle(float temperaturaCiclo, float tiempoCicloDenaturacion){

	escalon++;
	proportionalBand = 1.00;
	sParam.f16Ka = FRAC16(1.0);
	sParam.f16Kb = FRAC16(-0.9999);
	sParam.f16Kc = FRAC16(0.0);
	while(temperature[0] < (temperaturaCiclo - 2.0)){
		ObtainTemp(ADC, Vin, Rdiv, Rdiv2);
		ratio = PIDControl(temperaturaCiclo);
		printToConsole();
		ChecarLid(tempLid);
	}
	ratio = 65535.0;
	for(int i = 0 ; i < 1000 ; i++) {
		ObtainTemp(ADC, Vin, Rdiv, Rdiv2);
		PIDControl(temperaturaCiclo);
		ChecarLid(tempLid);
		printToConsole();
	}
	Clock_Reset(RelojCicloPCR);
	Clock_Reset(RelojTotal);
	Clock_GetTimeReal(RelojCicloPCR, &tiempoCicloPCR);
	while(tiempoCicloPCR < tiempoCicloDenaturacion){
		ObtainTemp(ADC, Vin, Rdiv, Rdiv2);
		ratio = PIDControl(temperaturaCiclo);
		ChecarLid(tempLid);
		printToConsole();
		Clock_GetTimeReal(RelojCicloPCR, &tiempoCicloPCR);
		Clock_GetTimeReal(RelojTotal, &tiempoTotal);
	}
}

void EnfriaSistema(void){
	Enable2_PutVal(1);
	Inhr1_ClearRxBuf();
	interruptRXActivado=TRUE;
	ratioCold = 0.0;

	//Este for loop Espera a prender el ventilador de manera que no se demande una corriente mayora a 4.74 A.
	for(int m = 0 ; m <= 6000 ; m++){
		printToConsole();
		ObtainTemp(ADC, Vin, Rdiv, Rdiv2);
	}

	Ventilador_PutVal(1);

	for(;;){
		printToConsole();
		ObtainTemp(ADC, Vin, Rdiv, Rdiv2);
	}
}

void FinalExtension(float temperaturaCiclo){

	Clock_Reset(RelojCicloPCR);
	Clock_GetTimeReal(RelojCicloPCR, &tiempoCicloPCR);
	while(tiempoCicloPCR < tiempoFinalExtension){
		ObtainTemp(ADC, Vin, Rdiv, Rdiv2);
		ratio = PIDControl(temperaturaCiclo);
		printToConsole();
		ChecarLid(tempLid);
		Clock_GetTimeReal(RelojCicloPCR, &tiempoCicloPCR);
		Clock_GetTimeReal(RelojTotal, &tiempoTotal);
	}
}

void ApagarSistemaYEsperarParaActivarPeltier(void){
	ratio = 65535.0;
	ratioLid = 0.0;
	Ventilador_PutVal(1);

	while(temperature[0] > 50.0){
		ObtainTemp(ADC, Vin, Rdiv, Rdiv2);
		printToConsole();
	}

	Ventilador_PutVal(0);
}

void HeatBlock(float temperaturaCiclo , float tiempoCiclo){

	HeatLid(tempLid);
	DenaturationCycle(temperaturaCiclo,tiempoCiclo);
	ApagarSistemaYEsperarParaActivarPeltier();
	for(;;){
		ObtainTemp(ADC, Vin, Rdiv, Rdiv2);
		printToConsole();
	}
}

void PreparaEstadoInicial(void){
	valueVolt[0] = 4000.0;
	valueVolt[1] = 4000.0;
	MyADCPtr = AD1_Init((LDD_TUserData *)NULL);
	AD1_SelectSampleGroup(MyADCPtr, 0);
	AD1_StartLoopTriggeredMeasurement(MyADCPtr);
	(void)PCLIB_CtrlPIDInit_F16(&sParam);
	(void)LEDRED_SetVal();
	(void)LEDGREEN_SetVal();
	(void)LEDBLUE_SetVal();
	(void)Ventilador_ClrVal();
	(void)Enable2_ClrVal();
}

/*lint -save  -e970 Disable MISRA rule (6.3) checking. */
int main(void)
/*lint -restore Enable MISRA rule (6.3) checking. */
{
	/* Write your local variable definition here */

	/*** Processor Expert internal initialization. DON'T REMOVE THIS CODE!!! ***/

	PE_low_level_init();
	PreparaEstadoInicial();
	/*** End of Processor Expert internal initialization.                    ***/
	float tempCiclo = 0.0;
	float ka = 0.8;
	float kb = -0.7996;
	float kc = 0.0000;
	sParam.f16Ka = FRAC16(ka);
	sParam.f16Kb = FRAC16(kb);
	sParam.f16Kc = FRAC16(kc);
	sParam.f16UpperLimit = FRAC16(1.0);
	sParam.f16LowerLimit = FRAC16(0.0);

	RelojCicloPCR = Clock_Init((LDD_TUserData *)NULL);
	RelojTotal = Clock_Init((LDD_TUserData *)NULL);
	LEDGREEN_PutVal(0);
	LEDBLUE_PutVal(0);
	LEDRED_PutVal(0);

	Inhr1_ClearRxBuf();
	Inhr1_ClearTxBuf();
	Term1_ReadLine(buf);
	j = buf;
	UTIL1_xatoi(&j, &infoCiclo[0]);

	if(infoCiclo[0] == 2){
		EnfriaSistema();
	}

	else if(infoCiclo[0] == 1)
	{
		int tempHeatBlock, tiempoHeatBlock;
		for(int h = 0; h <= 2 ; h++){
			UTIL1_xatoi(&j, &infoCiclo[h]);
			if( h != 2) {
				UTIL1_strncmp((char*)j, (char*)" ", sizeof(" ")-1)==0;
			}
		}
		for(int i = 0; i <= 1; i = i + 2){
			UTIL1_strcatNum32u(infoCicloString, sizeof(infoCicloString), infoCiclo[i]);
			UTIL1_chcat(infoCicloString, sizeof(infoCicloString), 46);
			UTIL1_strcatNum32u(infoCicloString, sizeof(infoCicloString), infoCiclo[i+1]);
			switch(i){
			case 0:
				tempHeatBlock = strtof(infoCicloString,NULL); //-1.0
			}
			memset(infoCicloString,0,strlen(infoCicloString));
			infoCicloString[0] = '\0';
		}
		for(int i = 2; i <= 2; i++){
			UTIL1_strcatNum32u(infoCicloString, sizeof(infoCicloString), infoCiclo[i]);
			switch(i){
			case 2:
				tiempoHeatBlock = strtof(infoCicloString,NULL);
			}
			memset(infoCicloString,0,strlen(infoCicloString));
			infoCicloString[0] = '\0';
		}
		Inhr1_ClearRxBuf();
		interruptRXActivado=TRUE;
		Enable2_PutVal(1);

		HeatBlock(tempHeatBlock,tiempoHeatBlock);
	}
	else if(infoCiclo[0] == 0) {

		for(int h = 0; h <= 11 ; h++){
			UTIL1_xatoi(&j, &infoCiclo[h]);
			if( h != 11) {
				UTIL1_strncmp((char*)j, (char*)" ", sizeof(" ")-1)==0;
			}
		}

		for(int i = 0; i <= 5; i = i + 2){
			UTIL1_strcatNum32u(infoCicloString, sizeof(infoCicloString), infoCiclo[i]);
			UTIL1_chcat(infoCicloString, sizeof(infoCicloString), 46);
			UTIL1_strcatNum32u(infoCicloString, sizeof(infoCicloString), infoCiclo[i+1]);
			switch(i){
			case 0:
				TempDenat = strtof(infoCicloString,NULL);// - 1.0;
			case 2:
				TempPrimers = strtof(infoCicloString,NULL);// + 3.0;
			case 4:
				TempAnnealing = strtof(infoCicloString,NULL);// + 1.0;
			}
			memset(infoCicloString,0,strlen(infoCicloString));
			infoCicloString[0] = '\0';
		}

		for(int i = 6; i <= 11; i++){
			UTIL1_strcatNum32u(infoCicloString, sizeof(infoCicloString), infoCiclo[i]);
			switch(i){
			case 6:
				tiempoInitDenat = strtof(infoCicloString,NULL);
			case 7:
				tiempoDenat = strtof(infoCicloString,NULL);
			case 8:
				tiempoPrimers = strtof(infoCicloString,NULL);
			case 9:
				tiempoAnnealing = strtof(infoCicloString,NULL);
			case 10:
				tiempoFinalExtension = strtof(infoCicloString,NULL);
			case 11:
				numCiclos = strtof(infoCicloString,NULL);
			}
			memset(infoCicloString,0,strlen(infoCicloString));
			infoCicloString[0] = '\0';
		}

		Inhr1_ClearRxBuf();
		interruptRXActivado=TRUE;

		LEDGREEN_PutVal(0);
		LEDBLUE_PutVal(1);
		LEDRED_PutVal(0);
		//Permite el funcionamiento del Peltier
		Enable2_PutVal(1);

		HeatLid(tempLid);

		tempCiclo = EstableceTemperaturaCiclo(TempDenat);
		LEDRED_PutVal(1);
		LEDBLUE_PutVal(0);
		LEDGREEN_PutVal(1);
		DenaturationCycle(tempCiclo, tiempoInitDenat);
		Clock_Reset(RelojCicloPCR);
		Clock_Reset(RelojTotal);
		ciclo++;
		escalon++;
		while(TRUE)
		{
			Clock_GetTimeReal(RelojCicloPCR, &tiempoCicloPCR);
			Clock_GetTimeReal(RelojTotal, &tiempoTotal);

			if(tiempoCicloPCR > tiempoDenat && escalon == 1) {
				escalon = 2;
				sParam.f16Ka = FRAC16(ka);
				sParam.f16Kb = FRAC16(kb);
				sParam.f16Kc = FRAC16(kc);
				LEDBLUE_PutVal(1);
				LEDRED_PutVal(0);
				tempCiclo = EstableceTemperaturaCiclo(TempPrimers);
				Clock_GetTimeReal(RelojTotal, &tiempoTotal);
				ratio = 65535.0;
				proportionalBand = 3.0;
				Ventilador_PutVal(1);
				while(temperature[0] > (tempCiclo)){
					Clock_GetTimeReal(RelojTotal, &tiempoTotal);
					printToConsole();
					ObtainTemp(ADC, Vin, Rdiv, Rdiv2);
					ratio = PIDControl(tempCiclo);
					ChecarLid(tempLid);
				}
				Ventilador_PutVal(0);
				Clock_Reset(RelojCicloPCR);
				Clock_GetTimeReal(RelojCicloPCR, &tiempoCicloPCR);
				Clock_GetTimeReal(RelojTotal, &tiempoTotal);


			}

			if(tiempoCicloPCR > tiempoPrimers && escalon == 2) {
				escalon = 3;
				LEDRED_PutVal(1);
				LEDGREEN_PutVal(0);
				tempCiclo = EstableceTemperaturaCiclo(TempAnnealing);
				Clock_GetTimeReal(RelojTotal, &tiempoTotal);
				proportionalBand = 0.5;
				while((temperature[0] < tempCiclo - 3.0)){
					Clock_GetTimeReal(RelojTotal, &tiempoTotal);
					ObtainTemp(ADC, Vin, Rdiv, Rdiv2);
					printToConsole();
					ratio = PIDControl(tempCiclo);
					ChecarLid(tempLid);
				}
				ratio = 65535.0;
				for(int i = 0 ; i < 5000 ; i++) {
					ObtainTemp(ADC, Vin, Rdiv, Rdiv2);
					PIDControl(tempCiclo);
					printToConsole();
					ChecarLid(tempLid);
				}
				Clock_GetTimeReal(RelojTotal, &tiempoTotal);
				Clock_Reset(RelojCicloPCR);
				Clock_GetTimeReal(RelojCicloPCR, &tiempoCicloPCR);
			}

			if(tiempoCicloPCR > tiempoAnnealing && escalon == 3) {

				ciclo++;
				if(ciclo == numCiclos + 1){
					escalon++;
					break;
				}
				escalon = 1;
				LEDGREEN_PutVal(1);
				LEDBLUE_PutVal(0);
				tempCiclo = EstableceTemperaturaCiclo(TempDenat);
				Clock_GetTimeReal(RelojTotal, &tiempoTotal);
				proportionalBand = 1.0;
				while(temperature[0] < (tempCiclo - 2.0)){
					Clock_GetTimeReal(RelojTotal, &tiempoTotal);
					printToConsole();
					ObtainTemp(ADC, Vin, Rdiv, Rdiv2);
					ratio = PIDControl(tempCiclo);
					ChecarLid(tempLid);
				}
				ratio = 65535.0;
				for(int i = 0 ; i < 1000 ; i++) {
					ObtainTemp(ADC, Vin, Rdiv, Rdiv2);
					PIDControl(tempCiclo);
					ChecarLid(tempLid);
					printToConsole();
				}
				sParam.f16Ka = FRAC16(1.0);
				sParam.f16Kb = FRAC16(-0.9999);
				sParam.f16Kc = FRAC16(0.0);
				Clock_GetTimeReal(RelojTotal, &tiempoTotal);
				Clock_Reset(RelojCicloPCR);
				Clock_GetTimeReal(RelojCicloPCR, &tiempoCicloPCR);
			}

			ObtainTemp(ADC, Vin, Rdiv, Rdiv2);
			ratio = PIDControl(tempCiclo);
			printToConsole();
			ChecarLid(tempLid);

		}

		FinalExtension(tempCiclo);
		ApagarSistemaYEsperarParaActivarPeltier();
		EnfriaSistema();
	}
	/*** Don't write any code pass this line, or it will be deleted during code generation. ***/
  /*** RTOS startup code. Macro PEX_RTOS_START is defined by the RTOS component. DON'T MODIFY THIS CODE!!! ***/
  #ifdef PEX_RTOS_START
    PEX_RTOS_START();                  /* Startup of the selected RTOS. Macro is defined by the RTOS component. */
  #endif
  /*** End of RTOS startup code.  ***/
  /*** Processor Expert end of main routine. DON'T MODIFY THIS CODE!!! ***/
  for(;;){}
  /*** Processor Expert end of main routine. DON'T WRITE CODE BELOW!!! ***/
} /*** End of main routine. DO NOT MODIFY THIS TEXT!!! ***/

/* END main */
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
