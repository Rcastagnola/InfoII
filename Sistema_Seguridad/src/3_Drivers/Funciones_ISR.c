/*
===============================================================================
Funciones de Atencion de Interrupciones
===============================================================================
*/
#include "Header.h"

/*Variables Externas*/
extern uint8_t Estado;
extern uint8_t Sensor_Infrarrojo;
extern uint8_t Sensor_Peso;

/*Variables Externas UART0 y UART1*/
extern uint8_t enviando0;
extern uint8_t enviando1;

/*Variables Globales de GSM*/
extern uint8_t EstadoGSM;
extern uint8_t	flagEnvioGSM;

/************************Funcion de Interruocion por SysTick*****************************/
void SysTick_Handler (void)
{
	/*Declaracion de Variables*/
	static uint32_t Contador_Teclado = TIMER_TECLADO;
	static uint32_t Contador_EnvioEstadoActual = TIMER_ESTADO_ACTUAL;
	static uint32_t Contador_Display = TIMER_DISPLAY;


	/*Decremento los contadores*/
	Contador_Display  --;
	Contador_Teclado --;
	Contador_EnvioEstadoActual --;

	/*Barrido del Display*/
	if( Contador_Display == 0 )
	{
		Barrido_Display();
		Contador_Display = TIMER_DISPLAY;
	}

	/*Barrido de Teclado*/
	if(Contador_Teclado == 0)
	{
		Validacion_Teclado();
		Contador_Teclado = TIMER_TECLADO;
	}

	/*Envio ciclico de Estado Actual del Sistema*/
	if(Contador_EnvioEstadoActual  == 0)
	{
		Estado_Sistema();	//Envio la trama con la informacion del sistema
		Contador_EnvioEstadoActual = TIMER_ESTADO_ACTUAL;
	}

	return;
}
/****************************************************************************************/


/************************Interruocion por Sensor Infrarrojo******************************/
void EINT1_IRQHandler( void )	// Funcion de Atencion de interrupcion por sensor infrarrojo
{
	EXTINT |= (0x01 << 1);		//Limpio el flag de atencion

	/*Pone el flag del sensor infrarrojo en Estado Alto*/
	Sensor_Infrarrojo = TRUE;
}
/****************************************************************************************/

/************************Interruocion por Sensor de Peso******************************/
void EINT3_IRQHandler( void ) 	// Funcion de Atencion de interrupcion por sensor de peso
{
	EXTINT |= (0x01 << 3);		//Limpio el flag de atencion

	//Pone el flag del sensor de peso en Estado Alto
	Sensor_Peso = TRUE;
}
/****************************************************************************************/


/************************Interruocion valor procesado del ADC****************************/
void ADC_IRQHandler(void) 	// Funcion de Atencion de interrupcion por ADC
{
	uint32_t ResultADC = 0;	//Guardo el valor actual del ADC

	/*Si hubo OVERRUN leo el valor Actual y ... */
	if( ((AD0DR2 >> OVERRUN)&(0x01)) == 1  )
	{
		/*Tomo el valor actual del ADC*/
		ResultADC = (AD0DR2 >> RESULT)&(0x00000FFF);	//Decarto los ultimos dos bits
	}
	else
	{
		/*Tomo el valor actual del ADC*/
		ResultADC = (AD0DR2 >> RESULT)&(0x00000FFF);	//Decarto los ultimos dos bits
	}
	/*Promedio el resultado del ADC*/
	Integrador_ADC(ResultADC);
}
/****************************************************************************************/

/************************Atencion de Iterrupcion de la TIMER0****************************/
void TIMER0_IRQHandler (void)
{
	/*Pregunto por que match interrumpio*/
	if (T0IR & (1<< IRMR0))
	{
		/*Limpiael flag de interrupcion*/
		T0IR = (1<< IRMR0);
		/*Indico por un flag que se puede enviar el proximo comando*/
		flagEnvioGSM = TRUE;
	}
}
/****************************************************************************************/


/************************Atencion de Iterrupcion de la UART0*****************************/
void UART0_IRQHandler (void)
{
	/*Declaracion de Variables*/
	uint8_t iir;
	//uint8_t	lsr;  //BORRAR ESTO
	uint8_t dato;

	do
	{
		/* Guardo U0IIR que se resetea por HW una vez leido */
		iir = U0IIR;
		/* Guardo U0IIR que se resetea por HW una vez leido */ //BORRAR ESTA LINEA Y LA DE ABAJO
		//lsr = U0LSR;

		/* Llego un dato */
		if( iir & 0x04 ) //Data ready
		{
			dato = U0RBR;	//Leo el dato y limpio el registro
			PushRx0(dato);	//Guardo el dato en el buffer
		}

		/* Esta listo para enviar otro dato */
		if ( iir & 0x02 ) 	//THRE
		{
			/*Pregunto por datos para enviar*/
			dato = PopTx0();//Devuelve -1 cuando no hay mas datos que enviar

			/*Si hay dato lo envio*/
			if( dato != (0xFF))		U0THR = dato;

			/*Si no hay dato aviso que termine de transmitir*/
			else	enviando0 = FALSE;
		}

		/* Se detecto error en la resepcion o la linea RX
		if( iir & 0x06 ) //Errores
		{

			//BORAR ESTO LEDS
			SetPIN(RGBR, ON);
			SetPIN(RGBG, ON);
			SetPIN(RGBB, OFF);

			dato = U0RBR;	//Leo el dato y limpio el registro

			//Consulto por fifo vacia
			if( lsr & 0x01)
			{
				dato = U0RBR;	//Leo el dato y limpio el registro
			}

			//Consulto por error de OVERRUN
			if( lsr & 0x02)
			{
				//Se piso el dato anterior
				//BORRAR los LEDS
				SetPIN(LED_R3, ON);
				SetPIN(LED_R2, OFF);
				SetPIN(LED_R1, OFF);
				SetPIN(LED_R0, OFF);
			}

			//Consulto por error de PARIDAD
			if( lsr & 0x04)
			{
				//No deberia entrar aca por que la trama no tiene paridad
				//BORRAR los LEDS
				SetPIN(LED_R3, OFF);
				SetPIN(LED_R2, ON);
				SetPIN(LED_R1, OFF);
				SetPIN(LED_R0, OFF);
			}

			//Consulto por error de STOP
			if( lsr & 0x08)
			{
				//No se leyo el bit de stop cuando era esperado
				//BORRAR los LEDS
				SetPIN(LED_R3, OFF);
				SetPIN(LED_R2, OFF);
				SetPIN(LED_R1, ON);
				SetPIN(LED_R0, OFF);
			}

			//Consulto por error de BREAK
			if( lsr & 0x10)
			{
				//Se corto la linea fisica
				//BORRAR los LEDS
				SetPIN(LED_R3, OFF);
				SetPIN(LED_R2, OFF);
				SetPIN(LED_R1, OFF);
				SetPIN(LED_R0, ON);
			}

			//Consulto por THRE
			if( lsr & 0x20)
			{
				dato = U0RBR;	//Leo el dato y limpio el registro
			}

			//Consulto por TEMT
			if( lsr & 0x40)
			{
				dato = U0RBR;	//Leo el dato y limpio el registro
			}

			//Consulto por RXFE
			if( lsr & 0x80)
			{
				dato = U0RBR;	//Leo el dato y limpio el registro
			}
		}*/

	}	while( ! (iir & 0x01) ); //Antes de irme vuelvo a chequear si llego otra interrupcion. Espero un 0 xq es activo bajo
}
/****************************************************************************************/


/************************Atencion de Iterrupcion de la UART0*****************************/
void UART1_IRQHandler (void)
{
	/*Declaracion de Variables*/
	uint8_t iir;
	uint8_t dato;

	do
	{
		/* Guardo U1IIR que se resetea por HW una vez que lo leido */
		iir = U1IIR;

		/* Llego un dato */
		if( iir & 0x04 ) //Data ready
		{
			dato = U1RBR;	//Leo el dato y limpio el registro
			PushRx1(dato);	//Guardo el dato en el buffer
		}

		/* Esta listo para enviar otro dato */
		if ( iir & 0x02 ) 	//THRE
		{
			/*Pregunto por datos para enviar*/
			dato = PopTx1(); //Devuelve -1 cuando no hay mas datos que enviar

			/*Si hay dato lo envio*/
			if( dato != (0xFF))		U1THR = dato;

			/*Si no hay dato aviso que termine de transmitir*/
			else	enviando1 = FALSE;
		}

		/* Se detecto error en la resepcion o la linea RX
		if( iir & 0x06 ) //Errores
		{

		} VER */

	}	while( ! (iir & 0x01) ); //Antes de irme vuelvo a chequear si llego otra interrupcion. Espero un 0 xq es activo bajo
}
/****************************************************************************************/
