/*
 * Servo.c
 *
 *  Created on: 6 jul. 2021
 *      Author: MP
 */
#include "MKL25Z4.h"
#include "Libreria_ojo.h"

#define scgc_TPM0			0x1000000
#define Activar_mux			0x400
#define Activar_clk_C		0x800
#define Activar_SOPT2		0x1000000
#define Activar_SC			0xD//DIVIDE ENTRE 32
#define Activar_CnSC		0x28
//#define Activar_CnSC		0x22
//#define Activar_MOD			26249
#define Activar_MOD			14999


//Valores de interpolacion
//#define Ciclo_Trabajo_180	3200
//#define Ciclo_Trabajo_0		1312
#define Ciclo_Trabajo_180	1500
#define Ciclo_Trabajo_0		750
#define zero_degrees			0
#define cientoochenta_grados			45
/*
 * 2300 TE DA 0 GRADOS
 * 720 TE DA 90 GRADOS CON LA CONFIGURACION NORMAL
 */




//void PWM_vfnDriverInit (void);
void DPY_bInitialPosition (void);
void PWM_bfnAngleAdjustment (int bNewAngle);//int bNewAngle


void PWM_vfnDriverInit (void)
{
	//MCG->C4 = 0x80; //Reloj en 24MHz

	SIM->SCGC5 |= Activar_clk_C;//Reloj puerto C
	SIM->SCGC6 |= scgc_TPM0;//Reloj para el PWM (24MHz)
	PORTC->PCR[2] = Activar_mux;//Puerto C2 con MUX canal 1
	SIM->SOPT2 |= Activar_SOPT2;
	TPM0->SC = 0;
	TPM0->CONTROLS[1].CnSC = Activar_CnSC;
	TPM0->MOD = Activar_MOD;
	TPM0->CONTROLS[1].CnV = Ciclo_Trabajo_0;
	TPM0->SC = Activar_SC;
	return;
}

void DPY_bInitialPosition (void)
{

	TPM0->CONTROLS[1].CnV = 300;//Ciclo_Trabajo_0;

	return;

}

void PWM_bfnAngleAdjustment (int bNewAngle)//int bNewAngle
{
	/*if(bNewAngle == 180){
	TPM0->MOD = 26249;
	TPM0->SC = 0xC;
	ADC_read8b(8, &Result1);
	TPM0->CONTROLS[1].CnV = 1990; //+ Result1*5/8;

	}else
	if(bNewAngle == 90)
	{
		ADC_read8b(8, &Result1);
		TPM0->CONTROLS[1].CnV = 800;//+ Result2/4;(720)
	}else if(bNewAngle == 0)
	{
		ADC_read8b(8, &Result1);
		TPM0->CONTROLS[1].CnV = 300;//+ Result2/4;(720)
	}*/


	int X;

	X = (((bNewAngle - zero_degrees)*(Ciclo_Trabajo_180 - Ciclo_Trabajo_0))/(cientoochenta_grados - zero_degrees)) + Ciclo_Trabajo_0;


     TPM0->CONTROLS[1].CnV = X;
		return;
}
