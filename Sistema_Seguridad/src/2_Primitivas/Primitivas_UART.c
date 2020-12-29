/*
 * Primitivas_UART.c
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


// FUNCIONES PRIMITIVAS DE LA UART0 -----------------------------------------------------------------------
/***************** Ingresa datos al BufferTx0 *******************/
void PushTx0(uint8_t dato)
{
	BufferTx0[indiceTx0In] = dato;	//Escribo el dato en el Buffer
	indiceTx0In ++;
	indiceTx0In %= TOPE0;
	if( enviando0 == FALSE ) //Si no se esta enviando nada, debo forzar el primer envio. No hay interrupcion que lo llame
	{
		enviando0 = TRUE;
		U0THR = PopTx0(); //Fuerzo el primer envio
	}
}
/****************************************************************/

/******************* Toma datos del BufferRx0 ********************/
uint8_t PopRx0(void)
{
	/*Declaracion de Variables*/
	int aux = -1;

	/*Chequeo si hay datos que sacar*/
	if(indiceRx0In != indiceRx0Out)
	{
		aux = BufferRx0[indiceRx0Out];	//Devuelvo el dato recivido
		indiceRx0Out ++;
		indiceRx0Out %= TOPE0;
	}
	return aux;
}
/***************************************************************/
//-------------------------------------------------------------------------------------------------------------


// FUNCIONES PRIMITIVAS DE LA UART1----------------------------------------------------------------------------
/***************** Ingresa datos al BufferTx1 *******************/
void PushTx1(uint8_t dato)
{
	BufferTx1[indiceTx1In] = dato;	//Escribo el dato en el Buffer
	indiceTx1In ++;
	indiceTx1In %= TOPE1;
	if( enviando1 == FALSE ) //Si no se esta enviando nada, debo forzar el primer envio. No hay interrupcion que lo llame
	{
		enviando1 = TRUE;
		U1THR = PopTx1(); //Fuerzo el primer envio
	}
}
/****************************************************************/

/******************* Toma datos del BufferRx1 ********************/
uint8_t PopRx1(void)
{
	/*Declaracion de Variables*/
	int aux = -1;

	/*Chequeo si hay datos que sacar*/
	if(indiceRx1In != indiceRx1Out)
	{
		aux = BufferRx1[indiceRx1Out];	//Devuelvo el dato recivido
		indiceRx1Out ++;
		indiceRx1Out %= TOPE1;
	}
	return aux;
}
//----------------------------------------------------------------------------------------------------------
