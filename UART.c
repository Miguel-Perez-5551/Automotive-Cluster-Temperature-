/*
 * UART.c
 *
 *  Created on: 21 jul. 2021
 *      Author: danov
 */

#include <stdio.h>
#include <stdint.h>
#include "board.h"
#include "peripherals.h"
#include "pin_mux.h"
#include "clock_config.h"
#include "MKL25Z4.h"
#include "fsl_debug_console.h"

void UART_vfnDriverInit (void){

	//Inicializar reloj a 24 MHz

		MCG->C4 |= 0xA0;//necesito activar el MCG_C4

		//Habilito reloj para UART

		SIM->SOPT2 |= SIM_SOPT2_UART0SRC(1);//necesito activar el SOPT2 el bit 26 UART0SRC 0x4000000

		SIM->SCGC4 |= SIM_SCGC4_UART0_MASK;//necesito mandar un 1 en el bit 10 para activar el reloj del UART 0 0x400

		//Habilitar puerto de lectura del UART

		SIM->SCGC5 |= SIM_SCGC5_PORTA_MASK; //Habilitar reloj del puerto A 0x200

		PORTA->PCR[2] |= PORT_PCR_MUX(2);//Habilitar multiplexor en A2 alternativa 2 para el UART (TX) ESCRIBE-TRANSMITE
		PORTA->PCR[1] |= PORT_PCR_MUX(2);//Habilitar multiplexor en A1 alternativa 2 para el UART (RX) LEE

		//Programar baudios de UART 9600 SBR = 500 OSR = 4

		UART0->BDH = 0x1;//Se mandan los 5 bits de la parte alta

		UART0->BDL = 0x38;//Semandarn los 8 bits de la parte baja (F4)

		UART0->C4 = 0x20;//Se configura el OSR para los baudios

		//Configurar el tamaño del dato que se enviara

		UART0->C1 = 0x00;//8 data bits, no paridad y 1 stop bit

		//Registro donde llega la informacion

		//UART0->C2 = 0xC;
		//UART0->C2  |= UART_C2_RIE(1);     // Rx Interrupt enabled
		//UART0->C2  |= UART_C2_RE(1);  // Rx Enabled
		UART0->C2 = 0xC;
		//UART0->C3 = 0x20;
		//UART0->C5 = 0x20;
}

void UART_bfnRead (unsigned char *bpRxData){

	UART0->C2 = 0x4;
	*bpRxData = UART0 ->D;

	if(*bpRxData == 0)
	{
	*bpRxData = UART0 ->D;
	}



}

void UART_bfnSend (unsigned char bTxData){

	UART0->C2 = 0x8;
	//while(UART0->S1 & 0x80){
	UART0->D = bTxData;

	}


