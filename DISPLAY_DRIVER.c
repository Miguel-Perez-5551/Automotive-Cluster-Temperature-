/*
 * DISPLAY_DRIVER.c
 *
 *  Created on: 22 jun. 2021
 *      Author: danov
 */


#include "PortsActivation.h"
#include "MKL25Z4.h"
#include "DISPLAY_DRIVER.h"



void DPY_vfnDriverInit (void);
void DPY_bfnWriteMsg(unsigned char *bpMsgSrc);
/*
uint_8 DPY_bfnClearScreen (void);
uint_8 DPY_bfnWriteMsg (uint_8 *bpMsgSrc, uint_8 bMsgSize);
*/
void InitVar(void);
void Paso1Clear(void);
void Paso2ReturnHome(void);
void Paso3EnteryModeSet(void);
void Paso4DisplayON(void);
void Paso4DisplayOFF(void);
void Paso5Cursor(void);
void Paso6Set(void);
void WriteDatatoRam(void);
void Delay(long n);
void RENGLON1(void);
void RENGLON2(void);
//////////////////////////////////////////
void cero(void);
void uno(void);
void dos(void);
void tres(void);
void cuatro(void);
void cinco(void);
void seis(void);
void siete(void);
void ocho(void);
void nueve(void);
void LetraC(void);
void signogrados(void);



void DPY_vfnDriverInit (void)
{
	char i = 0;


	InitVar();
	Paso4DisplayOFF();
	Paso1Clear();
	Paso4DisplayON();
	Paso2ReturnHome();
	Paso6Set();
	//WriteDatatoRam();
	//Paso1Clear();
	//Paso4DisplayOFF();


	i++;//Para aqui
}

void RENGLON1(){
		DigitalWrite('C',11,0);//RS
		DigitalWrite('C',10,0);//RW
		DigitalWrite('C',6,1);//E
		DigitalWrite('D', 7, 0);//D0
		DigitalWrite('D', 6, 0);//D1
		DigitalWrite('A', 17, 0);//D2
		DigitalWrite('A', 16, 0);//D3
		DigitalWrite('C', 17, 0);//D4
		DigitalWrite('C', 16, 0);//D5
		DigitalWrite('C', 13, 0);//D6
		DigitalWrite('C', 12, 1);//D7
		DigitalWrite('C',6,0);//E
		DigitalWrite('C', 12, 0);//D7
		Delay(0xFFFF);
}
void RENGLON2(){
			DigitalWrite('C',11,0);//RS
			DigitalWrite('C',10,0);//RW
			DigitalWrite('C',6,1);//E
			DigitalWrite('D', 7, 0);//D0
			DigitalWrite('D', 6, 0);//D1
			DigitalWrite('A', 17, 0);//D2
			DigitalWrite('A', 16, 0);//D3
			DigitalWrite('C', 17, 0);//D4
			DigitalWrite('C', 16, 0);//D5
			DigitalWrite('C', 13, 1);//D6
			DigitalWrite('C', 12, 1);//D7
			DigitalWrite('C',6,0);//E
			DigitalWrite('C', 12, 0);//D7
			DigitalWrite('C', 13, 0);//D6
			Delay(0xFFFF);
}

void DPY_bfnWriteMsg (unsigned char *bpMsgSrc)
{
	Paso1Clear();
	Paso4DisplayOFF();

	unsigned char X = 0;
		unsigned char Division = 0;
		unsigned char Modulo = 0;
		unsigned char VAR[3] = {0,0,0};
		unsigned char count = 0;
		void (*Num[])(void) = {cero, uno, dos, tres, cuatro, cinco, seis, siete, ocho, nueve, signogrados, LetraC};

		X = *bpMsgSrc;

	        Division = 1;

			while(Division != 0)
			{
			Modulo = X % 10;
			Division = X / 10;
			X /= 10;
			VAR[count] = Modulo;
			count++;
			}
			while(count != 0)
			{
			count--;
			(*Num[VAR[count]])();
			}

			(*Num[10])();
			(*Num[11])();

	//Delay(0xFFFFF);
}

void InitVar()
{
	PinMode('C',11,1);//Rs
	PinMode('C',10,1);//Rw
	PinMode('C',6,1);//E
	PinMode('D',7,1);//D0
	PinMode('D',6,1);//D1
	PinMode('A',17,1);//D2
	PinMode('A',16,1);//D3
	PinMode('C',17,1);//D4
	PinMode('C',16,1);//D5
	PinMode('C',13,1);//D6
	PinMode('C',12,1);//D7
    Delay(0xFFFF);
}
void Paso1Clear()
{
	DigitalWrite('C',11,0);//RS
	DigitalWrite('C',10,0);//RW
	DigitalWrite('C',6,1);//E
	DigitalWrite('D', 7, 1);//D0
	DigitalWrite('D', 6, 0);//D1
	DigitalWrite('A', 17, 0);//D2
	DigitalWrite('A', 16, 0);//D3
	DigitalWrite('C', 17, 0);//D4
	DigitalWrite('C', 16, 0);//D5
	DigitalWrite('C', 13, 0);//D6
	DigitalWrite('C', 12, 0);//D7
	DigitalWrite('C',6,0);//E
	DigitalWrite('D', 7, 0);//D0
	Delay(0xFFFF);

}

void Paso2ReturnHome()
{
	DigitalWrite('C',11,0);//RS
	DigitalWrite('C',10,0);//RW
	DigitalWrite('C',6,1);//E
	DigitalWrite('D', 7, 0);//D0
	DigitalWrite('D', 6, 1);//D1
	DigitalWrite('A', 17, 0);//D2
	DigitalWrite('A', 16, 0);//D3
	DigitalWrite('C', 17, 0);//D4
	DigitalWrite('C', 16, 0);//D5
	DigitalWrite('C', 13, 0);//D6
	DigitalWrite('C', 12, 0);//D7
	DigitalWrite('C',6,0);//E
	DigitalWrite('D', 6, 0);//D1
	Delay(0xFFFF);

}

void Paso3EnteryModeSet()
{




}

void Paso4DisplayON()
{
	DigitalWrite('C',6,1);//E
	DigitalWrite('C',11,0);//Rs LOW
	DigitalWrite('C',10,0);//Rw LOW
	DigitalWrite('C',6,1);//E
	DigitalWrite('D', 7, 1);//D0
	DigitalWrite('D', 6, 0);//D1
	DigitalWrite('A', 17, 1);//D2
	DigitalWrite('A', 16, 1);//D3
	DigitalWrite('C', 17, 0);//D4
	DigitalWrite('C', 16, 0);//D5
	DigitalWrite('C', 13, 0);//D6
	DigitalWrite('C', 12, 0);//D7
	DigitalWrite('C',6,0);//E
	DigitalWrite('D',7,0);//D0 LOW
	DigitalWrite('A',17,0);//D2 LOW
	DigitalWrite('A',16,0);//D3 LOW
	Delay(0xFFFF);

}
void Paso4DisplayOFF()
{
	DigitalWrite('C',6,1);//E
	DigitalWrite('C',11,0);//Rs LOW
	DigitalWrite('C',10,0);//Rw LOW
	DigitalWrite('C',6,1);//E
	DigitalWrite('D', 7, 0);//D0
	DigitalWrite('D', 6, 0);//D1
	DigitalWrite('A', 17, 1);//D2
	DigitalWrite('A', 16, 1);//D3
	DigitalWrite('C', 17, 0);//D4
	DigitalWrite('C', 16, 0);//D5
	DigitalWrite('C', 13, 0);//D6
	DigitalWrite('C', 12, 0);//D7
	DigitalWrite('C',6,0);//E
	DigitalWrite('A',17,0);//D2 LOW
	DigitalWrite('A',16,0);//D3 LOW
	Delay(0xFFFF);

}

void Paso5Cursor()
{




}

void Paso6Set()
{
	DigitalWrite('C',11,0);//Rs LOW
	DigitalWrite('C',10,0);//Rw LOW
	DigitalWrite('C',6,1);//E
	DigitalWrite('D',7,0);//D0 Indiferente
	DigitalWrite('D',6,0);//D1 Indiferente
	DigitalWrite('A',17,0);//D2 HIGH = cuadricula de 5x11 LOW = cuadricula de 5x8
	DigitalWrite('A',16,1);//D3 HIGH = 2-Line LOW = 1-Line
	DigitalWrite('C',17,1);//D4 HIGH = 8-Bits LOW = 4-Bits
	DigitalWrite('C',16,1);//D5 Set
	DigitalWrite('C',13,0);//D6 LOW
	DigitalWrite('C',12,0);//D7 LOW
	DigitalWrite('C',6,0);//E HIGH (Se requiere darle alrededor de 3 segundos para que el display recibe el Paso)
	DigitalWrite('A',16,0);//D3 HIGH = 2-Line LOW = 1-Line
	DigitalWrite('C',17,0);//D4 HIGH = 8-Bits LOW = 4-Bits
	DigitalWrite('C',16,0);//D5 Set
	Delay(0xFFFF);

}





/* aqui tenemos una function de retard en milisegun dos*/
void Delay(long n){
	while(n--);
	return;
	}

void cero(void)
{
	DigitalWrite('C',11,1);//RS
	DigitalWrite('C',10,0);//RW
	DigitalWrite('C',6,1);//E

	DigitalWrite('D', 7, 0);//D0
	DigitalWrite('D', 6, 0);//D1
	DigitalWrite('A', 17, 0);//D2
	DigitalWrite('A', 16, 0);//D3
	DigitalWrite('C', 17, 1);//D4
	DigitalWrite('C', 16, 1);//D5
	DigitalWrite('C', 13, 0);//D6
	DigitalWrite('C', 12, 0);//D7

	DigitalWrite('C',6,0);//E
	DigitalWrite('C', 17, 0);//D4
	DigitalWrite('C', 16, 0);//D5

	Delay(0xFFFF);
}

void uno(void)
{
	DigitalWrite('C',11,1);//RS
	DigitalWrite('C',10,0);//RW
	DigitalWrite('C',6,1);//E

	DigitalWrite('D', 7, 1);//D0
	DigitalWrite('D', 6, 0);//D1
	DigitalWrite('A', 17, 0);//D2
	DigitalWrite('A', 16, 0);//D3
	DigitalWrite('C', 17, 1);//D4
	DigitalWrite('C', 16, 1);//D5
	DigitalWrite('C', 13, 0);//D6
	DigitalWrite('C', 12, 0);//D7

	DigitalWrite('C',6,0);//E
	DigitalWrite('D', 7, 0);//D0
	DigitalWrite('C', 17, 0);//D4
	DigitalWrite('C', 16, 0);//D5

	Delay(0xFFFF);
}
void dos(void)
{
	DigitalWrite('C',11,1);//RS
	DigitalWrite('C',10,0);//RW
	DigitalWrite('C',6,1);//E

	DigitalWrite('D', 7, 0);//D0
	DigitalWrite('D', 6, 1);//D1
	DigitalWrite('A', 17, 0);//D2
	DigitalWrite('A', 16, 0);//D3
	DigitalWrite('C', 17, 1);//D4
	DigitalWrite('C', 16, 1);//D5
	DigitalWrite('C', 13, 0);//D6
	DigitalWrite('C', 12, 0);//D7

	DigitalWrite('C',6,0);//E
	DigitalWrite('D', 6, 0);//D1
	DigitalWrite('C', 17, 0);//D4
	DigitalWrite('C', 16, 0);//D5

	Delay(0xFFFF);
}
void tres(void)
{
	DigitalWrite('C',11,1);//RS
	DigitalWrite('C',10,0);//RW
	DigitalWrite('C',6,1);//E

	DigitalWrite('D', 7, 1);//D0
	DigitalWrite('D', 6, 1);//D1
	DigitalWrite('A', 17, 0);//D2
	DigitalWrite('A', 16, 0);//D3
	DigitalWrite('C', 17, 1);//D4
	DigitalWrite('C', 16, 1);//D5
	DigitalWrite('C', 13, 0);//D6
	DigitalWrite('C', 12, 0);//D7

	DigitalWrite('C',6,0);//E
	DigitalWrite('D', 7, 0);//D0
	DigitalWrite('D', 6, 0);//D1
	DigitalWrite('C', 17, 0);//D4
	DigitalWrite('C', 16, 0);//D5

	Delay(0xFFFF);
}
void cuatro(void)
{
	DigitalWrite('C',11,1);//RS
	DigitalWrite('C',10,0);//RW
	DigitalWrite('C',6,1);//E

	DigitalWrite('D', 7, 0);//D0
	DigitalWrite('D', 6, 0);//D1
	DigitalWrite('A', 17, 1);//D2
	DigitalWrite('A', 16, 0);//D3
	DigitalWrite('C', 17, 1);//D4
	DigitalWrite('C', 16, 1);//D5
	DigitalWrite('C', 13, 0);//D6
	DigitalWrite('C', 12, 0);//D7

	DigitalWrite('C',6,0);//E
	DigitalWrite('A', 17, 0);//D2
	DigitalWrite('C', 17, 0);//D4
	DigitalWrite('C', 16, 0);//D5

	Delay(0xFFFF);
}
void cinco(void)
{
	DigitalWrite('C',11,1);//RS
	DigitalWrite('C',10,0);//RW
	DigitalWrite('C',6,1);//E

	DigitalWrite('D', 7, 1);//D0
	DigitalWrite('D', 6, 0);//D1
	DigitalWrite('A', 17, 1);//D2
	DigitalWrite('A', 16, 0);//D3
	DigitalWrite('C', 17, 1);//D4
	DigitalWrite('C', 16, 1);//D5
	DigitalWrite('C', 13, 0);//D6
	DigitalWrite('C', 12, 0);//D7

	DigitalWrite('C',6,0);//E
	DigitalWrite('D', 7, 0);//D0
	DigitalWrite('A', 17, 0);//D2
	DigitalWrite('C', 17, 0);//D4
	DigitalWrite('C', 16, 0);//D5

	Delay(0xFFFF);
}
void seis(void)
{
	DigitalWrite('C',11,1);//RS
	DigitalWrite('C',10,0);//RW
	DigitalWrite('C',6,1);//E

	DigitalWrite('D', 7, 0);//D0
	DigitalWrite('D', 6, 1);//D1
	DigitalWrite('A', 17, 1);//D2
	DigitalWrite('A', 16, 0);//D3
	DigitalWrite('C', 17, 1);//D4
	DigitalWrite('C', 16, 1);//D5
	DigitalWrite('C', 13, 0);//D6
	DigitalWrite('C', 12, 0);//D7

	DigitalWrite('C',6,0);//E
	DigitalWrite('D', 6, 0);//D1
	DigitalWrite('A', 17, 0);//D2
	DigitalWrite('C', 17, 0);//D4
	DigitalWrite('C', 16, 0);//D5

	Delay(0xFFFF);
}
void siete(void)
{
	DigitalWrite('C',11,1);//RS
	DigitalWrite('C',10,0);//RW
	DigitalWrite('C',6,1);//E

	DigitalWrite('D', 7, 1);//D0
	DigitalWrite('D', 6, 1);//D1
	DigitalWrite('A', 17, 1);//D2
	DigitalWrite('A', 16, 0);//D3
	DigitalWrite('C', 17, 1);//D4
	DigitalWrite('C', 16, 1);//D5
	DigitalWrite('C', 13, 0);//D6
	DigitalWrite('C', 12, 0);//D7

	DigitalWrite('C',6,0);//E
	DigitalWrite('D', 7, 0);//D0
	DigitalWrite('D', 6, 0);//D1
	DigitalWrite('A', 17, 0);//D2
	DigitalWrite('C', 17, 0);//D4
	DigitalWrite('C', 16, 0);//D5

	Delay(0xFFFF);
}

void ocho(void)
{
	DigitalWrite('C',11,1);//RS
	DigitalWrite('C',10,0);//RW
	DigitalWrite('C',6,1);//E

	DigitalWrite('D', 7, 0);//D0
	DigitalWrite('D', 6, 0);//D1
	DigitalWrite('A', 17, 0);//D2
	DigitalWrite('A', 16, 1);//D3
	DigitalWrite('C', 17, 1);//D4
	DigitalWrite('C', 16, 1);//D5
	DigitalWrite('C', 13, 0);//D6
	DigitalWrite('C', 12, 0);//D7

	DigitalWrite('C',6,0);//E
	DigitalWrite('A', 16, 0);//D3
	DigitalWrite('C', 17, 0);//D4
	DigitalWrite('C', 16, 0);//D5

	Delay(0xFFFF);
}
void nueve(void)
{
	DigitalWrite('C',11,1);//RS
	DigitalWrite('C',10,0);//RW
	DigitalWrite('C',6,1);//E

	DigitalWrite('D', 7, 1);//D0
	DigitalWrite('D', 6, 0);//D1
	DigitalWrite('A', 17, 0);//D2
	DigitalWrite('A', 16, 1);//D3
	DigitalWrite('C', 17, 1);//D4
	DigitalWrite('C', 16, 1);//D5
	DigitalWrite('C', 13, 0);//D6
	DigitalWrite('C', 12, 0);//D7

	DigitalWrite('C',6,0);//E
	DigitalWrite('D', 7, 0);//D0
	DigitalWrite('A', 16, 0);//D3
	DigitalWrite('C', 17, 0);//D4
	DigitalWrite('C', 16, 0);//D5

	Delay(0xFFFF);
}
void signogrados()
{
	DigitalWrite('C',11,1);//RS
		DigitalWrite('C',10,0);//RW
		DigitalWrite('C',6,1);//E

		DigitalWrite('D', 7, 0);//D0
		DigitalWrite('D', 6, 0);//D1
		DigitalWrite('A', 17, 0);//D2
		DigitalWrite('A', 16, 1);//D3
		DigitalWrite('C', 17, 1);//D4
		DigitalWrite('C', 16, 1);//D5
		DigitalWrite('C', 13, 1);//D6
		DigitalWrite('C', 12, 1);//D7
		DigitalWrite('C',6,0);//E
		DigitalWrite('A', 16, 0);//D3
		DigitalWrite('C', 17, 0);//D4
		DigitalWrite('C', 16, 0);//D5
		DigitalWrite('C', 13, 0);//D6
		DigitalWrite('C', 12, 0);//D7


		Delay(0xFFFF);

}
void LetraC()
{
	DigitalWrite('C',11,1);//RS
	DigitalWrite('C',10,0);//RW
	DigitalWrite('C',6,1);//E

	DigitalWrite('D', 7, 1);//D0
	DigitalWrite('D', 6, 1);//D1
	DigitalWrite('A', 17, 0);//D2
	DigitalWrite('A', 16, 0);//D3
	DigitalWrite('C', 17, 0);//D4
	DigitalWrite('C', 16, 0);//D5
	DigitalWrite('C', 13, 1);//D6
	DigitalWrite('C', 12, 0);//D7

	DigitalWrite('C',6,0);//E
	DigitalWrite('D', 7, 0);//D0
	DigitalWrite('D', 6, 0);//D1
	DigitalWrite('C', 13, 0);//D6

	Delay(0xFFFF);
}

