/*
 * Drivers_UART.c
 *
 *  Created on: Sep 21, 2015
 *      Author: owner
 */

#include "Header.h"

/*Variables Externas UART0*/
extern uint8_t BufferRx0[];
extern uint8_t BufferTx0[];
extern uint8_t indiceRx0In;
extern uint8_t indiceRx0Out;
extern uint8_t indiceTx0In;
extern uint8_t indiceTx0Out;
extern uint8_t enviando0;

/*Variables Externas UART1*/
extern uint8_t BufferRx1[];
extern uint8_t BufferTx1[];
extern uint8_t indiceRx1In;
extern uint8_t indiceRx1Out;
extern uint8_t indiceTx1In;
extern uint8_t indiceTx1Out;
extern uint8_t enviando1;

// Drivers UART0 --------------------------------------------------------------------------------------

/***************** Toma Datos de Buffer de UART0 ******************/
uint8_t PopTx0(void)
{
	/*Declaracion de Variables*/
	int aux = -1;

	/*Chequeo si hay datos que enviar*/
	if(indiceTx0In != indiceTx0Out)
	{
		aux = BufferTx0[indiceTx0Out];	//Devuelvo el dato a enviar
		indiceTx0Out ++;
		indiceTx0Out %= TOPE0;
	}
	return aux;
}
/******************************************************************/

/**************** Mete Datos en el Buffer de UART0 ****************/
void PushRx0 (uint8_t dato)
{
	BufferRx0[indiceRx0In] = dato;		//Guardo el dato recivido en el Buffer
	indiceRx0In ++;
	indiceRx0In %= TOPE0;
}
/******************************************************************/

// Drivers UART1 --------------------------------------------------------------------------------------
/***************** Toma Datos de Buffer de UART1 ******************/
uint8_t PopTx1(void)
{
	/*Declaracion de Variables*/
	int aux = -1;

	/*Chequeo si hay datos que enviar*/
	if(indiceTx1In != indiceTx1Out)
	{
		aux = BufferTx1[indiceTx1Out];	//Devuelvo el dato a enviar
		indiceTx1Out ++;
		indiceTx1Out %= TOPE1;
	}
	return aux;
}
/******************************************************************/

/**************** Mete Datos en el Buffer de UART1 ****************/
void PushRx1 (uint8_t dato)
{
	BufferRx1[indiceRx1In] = dato;		//Guardo el dato recivido en el Buffer
	indiceRx1In ++;
	indiceRx1In %= TOPE1;
}
/******************************************************************/
// ----------------------------------------------------------------------------------------------------
