/*
===============================================================================
 Name        : main.c
 Author      : $(author)
 Version     :
 Copyright   : $(copyright)
 Description : main definition
===============================================================================
*/

#ifdef __USE_CMSIS
#include "LPC17xx.h"
#endif

#include <cr_section_macros.h>
#include <NXP/crp.h>


/* Includes Propios */
#include "Header.h"

/******************** Variables Globales *******************/
uint8_t Estado = DESACTIVADO;	//Estado del sistema de seguridad

/*Flag de alarma por sensores disparados*/		//Si el sensor esta en TRUE, este se encuentra alarmado
uint8_t Sensor_Peso = FALSE;
uint8_t Sensor_Infrarrojo = FALSE;

/*Buffer de almacenamiento del password ingresado*/
uint8_t	MasterPass[NUM_PASS];				//En realidad se tomaria e valor del registro en al inicializacion del mismo
uint8_t Pass[NUM_PASS] = {NO_KEY, NO_KEY, NO_KEY, NO_KEY};   	//Alamacena el pass ingresado por teclado
uint8_t passPC[NUM_PASS] = {NO_KEY, NO_KEY, NO_KEY, NO_KEY};	//Alamacena el pass ingresado por PC
uint8_t NewPass[NUM_PASS];

/*Buffers de Teclado y Dislplat*/
uint8_t Buffer_Display[CANT_DIGITOS];
uint8_t Buffer_Teclado = NO_KEY;

/*Valor obtenido del canal 2 del ADC*/
uint16_t Resultado_ADC = 0;
uint16_t Valor_Objeto;	//Inicializar como registro o alo asi

/*Variables UART0*/
uint8_t BufferRx0[TOPE0];
uint8_t BufferTx0[TOPE0];
uint8_t indiceRx0In = 0;
uint8_t indiceRx0Out = 0;
uint8_t indiceTx0In = 0;
uint8_t indiceTx0Out = 0;
uint8_t enviando0 = FALSE;

/*Variables UART1*/
uint8_t BufferRx1[TOPE1];
uint8_t BufferTx1[TOPE1];
uint8_t indiceRx1In = 0;
uint8_t indiceRx1Out = 0;
uint8_t indiceTx1In = 0;
uint8_t indiceTx1Out = 0;
uint8_t enviando1 = FALSE;

/*Variables Globales de GSM*/
uint8_t EstadoGSM = INICIO_GSM;
uint8_t	flagEnvioGSM = FALSE;

/************************Inicio de la Aplicacion*****************************/
int main(void)
{
	/*Declaracion de Variables Auxiliares*/
	uint16_t peso;

	/* Inicializacion del Programa */
 	Inicializar( );

	/* Ejecucion secuencial del Programa */
	while( 1 )
	{
		/*Proceso la Maquina de Estado*/
		Maquina_Sistema_Seguridad();

		/*Muestro el peso de la balanza por Display 7 segmentos*/
		peso = Medicion_Peso();
		Display_7Seg( peso );

		/*Recivo los datos por UART0*/
		RecibirDatos();

		/*Envia el SMS de Alarma por UART1*/
		EnvioSMS();
	}
    return 0;
}
/*****************************************************************************/
