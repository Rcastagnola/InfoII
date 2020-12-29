/*
===============================================================================
Funciones Basicas
===============================================================================
*/
#include "Header.h"

/*Variables Externas*/
extern uint8_t Buffer_Display[];
extern uint8_t Buffer_Teclado;

/*Manejo de Balanza*/
extern uint16_t Resultado_ADC;
extern uint8_t Sensor_Peso;

extern uint8_t flagEnvio; //BORRAR ESTO

// FUNCIONES DE TECLADO Y DISPLAY --------------------------------------------------------------------------------------------------

/*********************Barrido de Teclado***********************/
uint8_t Barrido_Teclado (void)
{
	//Teclado de 5*1
	if( GetPIN(KEY1) == OFF )	return 9; //MODIFICADO
	if( GetPIN(KEY2) == OFF )	return 0; //MODIFICADO


	//Teclado de 4*2
	//Selecciono FILA 1
	SetPIN(FILA_0, ON); SetPIN(FILA_1, OFF);SetPIN(FILA_2, OFF); SetPIN(FILA_3, OFF);
	SetPIN(FILA_0, ON); SetPIN(FILA_1, OFF);SetPIN(FILA_2, OFF); SetPIN(FILA_3, OFF);
	SetPIN(FILA_0, ON); SetPIN(FILA_1, OFF);SetPIN(FILA_2, OFF); SetPIN(FILA_3, OFF);
	//Barro las Columnas
	if( GetPIN(COL_0) == ON )	return 4;
	if( GetPIN(COL_1) == ON )	return 5;

 	//Selecciono FILA 2
	SetPIN(FILA_0, OFF); SetPIN(FILA_1, ON);SetPIN(FILA_2, OFF); SetPIN(FILA_3, OFF);
	SetPIN(FILA_0, OFF); SetPIN(FILA_1, ON);SetPIN(FILA_2, OFF); SetPIN(FILA_3, OFF);
	SetPIN(FILA_0, OFF); SetPIN(FILA_1, ON);SetPIN(FILA_2, OFF); SetPIN(FILA_3, OFF);
	//Barro las Columnas
	if( GetPIN(COL_0) == ON )	return 1;
	if( GetPIN(COL_1) == ON )	return 8;

	// Selecciono FILA 3
	SetPIN(FILA_0, OFF); SetPIN(FILA_1, OFF);SetPIN(FILA_2, ON); SetPIN(FILA_3, OFF);
	SetPIN(FILA_0, OFF); SetPIN(FILA_1, OFF);SetPIN(FILA_2, ON); SetPIN(FILA_3, OFF);
	SetPIN(FILA_0, OFF); SetPIN(FILA_1, OFF);SetPIN(FILA_2, ON); SetPIN(FILA_3, OFF);
	//Barro las Columnas
	if( GetPIN(COL_0) == ON )	return 3;
	if( GetPIN(COL_1) == ON )	return 6;

	//Selecciono FILA 4
	SetPIN(FILA_0, OFF); SetPIN(FILA_1, OFF);SetPIN(FILA_2, OFF); SetPIN(FILA_3, ON);
	SetPIN(FILA_0, OFF); SetPIN(FILA_1, OFF);SetPIN(FILA_2, OFF); SetPIN(FILA_3, ON);
	SetPIN(FILA_0, OFF); SetPIN(FILA_1, OFF);SetPIN(FILA_2, OFF); SetPIN(FILA_3, ON);
	//Barro las Columnas
	if( GetPIN(COL_0) == ON )	return 2;
	if( GetPIN(COL_1) == ON )	return 7;

	/*No se presiono ningun pulsador*/
	return NO_KEY;
}
/****************************************************************/

/*********************Validacion de Teclado***********************/
void Validacion_Teclado (void)
{
	/*Declaracion de Variables*/
	uint8_t tecla_actual = NO_KEY;
	static uint8_t tecla_anterior = NO_KEY;
	static uint8_t cont = VALIDACION;

	/*Guardo la Tecla devuleta por Barrido_Teclado*/
	tecla_actual = Barrido_Teclado();

	/*Proceso la Tecla*/
	if( tecla_actual == NO_KEY )
	{
		tecla_anterior = NO_KEY;
		return; //Pongo return aca para no seguir con la ejecucion
	}

	/*Si la tecla actual es IGUAL a la anterior*/
	if( tecla_actual == tecla_anterior )
	{
		cont--;		// Decremento el Contador
		/*Si el contador llego a 0 valido la tecla*/
		if( cont == 0 )
		{
			Buffer_Teclado = tecla_actual;
			cont = VALIDACION;
		}
		return;
	}
	/*Si la tecla actual es DISTINTA a la anterior*/
	else
	{
		tecla_anterior = tecla_actual;
		cont = VALIDACION;
		return;
	}
}
/****************************************************************/


/*********************Barrido de Display***********************/
void Barrido_Display (void)
{
	/*Declaracion de Variables*/
	static uint8_t digito = 0;
	uint8_t valor;

	/*Tomo el Valor del Digito y los cargo*/
	valor = Buffer_Display[digito];
	//Encendido de los segmentos correspondientes
	SetPIN(BCD_A , ((valor >> 0)& ((uint8_t) 0x01)) );		//Al hacer la and con 1 tomo unicamente el valor del bit desplazado
	SetPIN(BCD_B , ((valor >> 1)& ((uint8_t) 0x01)) );
	SetPIN(BCD_C,  ((valor >> 2)& ((uint8_t) 0x01)) );
	SetPIN(BCD_D , ((valor >> 3)& ((uint8_t) 0x01)) );

	// Selección del digito a encender ( cíclico en modulo 6 )
	if( !digito )
	{
		SetPIN(RST,ON);
		SetPIN(RST,OFF);
	}
	else
	{
		SetPIN(CLK,ON);
		SetPIN(CLK,OFF);
	}

	digito ++;             //Cambio al proximo digito
	digito = digito % CANT_DIGITOS; //Si llega al valor maximo, reinicia a 0
}
/****************************************************************/
//--------------------------------------------------------------------------------------------------------------------------------------------------


/****************************** LCD **************************/ //NUEVO
void Dato_LCD ( unsigned char data , unsigned char control )
{
	int q , i = 1;
	int data_d4,data_d5,data_d6,data_d7;

	do
	{
		data_d4 = ( data >> ( 0 + i * 4 ) ) & 0x01 ;
		data_d5 = ( data >> ( 1 + i * 4 ) ) & 0x01 ;
		data_d6 = ( data >> ( 2 + i * 4 ) ) & 0x01 ;
		data_d7 = ( data >> ( 3 + i * 4 ) ) & 0x01 ;

		LCD_DATO(data_d4,data_d5,data_d6,data_d7);

		if( control == LCD_CONTROL )
			LCD_RS_OFF;
		else
			LCD_RS_ON;

		LCD_E_ON;
		for( q = 0 ; q < 400 ; q++ );
		LCD_E_OFF;		for( q = 0 ; q < 14000 ; q++ );
	}
	while ( i-- );
}
/********************************************************************/

// Convercion del ADC a gramos ------------------------------------------------------------------
/*********************** Enciende el ADC *****************************/
void ActivarADC( void )
{
	AD0CR |= (0x01 << PDN);			//Enciendo el ADC
	AD0CR |= (0x01 << BURST);		//EL ADC comienza a muestrear de forma automatica
}
/********************************************************************/

/************************ Apaga el ADC *******************************/
void DesactivarADC( void )
{
	AD0CR &= ~(0x01 << BURST);		//EL ADC deja de muestrear
	AD0CR &= ~(0x01 << PDN);		//Apagar el ADC
}
/********************************************************************/

/********************** Integrador del ADC **************************/
void Integrador_ADC ( uint32_t ResultADC)
{
	/*Declaracion de Variables*/
	static uint32_t Acumulador = 0;
	static uint32_t cont = 0;

	/*Acumulo una cierta cantidad de resultados*/
	Acumulador = Acumulador + ResultADC;
	cont ++;
	/*Promedio el valor obtenido*/
	if(cont == INTEGRADOR_ADC)
	{
		Resultado_ADC = (Acumulador/INTEGRADOR_ADC);	//Saco el valor por un buffer
		Deteccion_Variacion_Peso();						//Llamo a la funcionque cheque el peso
		Acumulador = 0;	//Reinicio el acumulador a 0
		cont = 0;		//Reinicio el contador
	}
}
/********************************************************************/

/************************Deteccion de Variacion de Peso******************************/
uint8_t Deteccion_Variacion_Peso( void )	//Es llamada por el Integrador una vez que se consigue un promedio
{
	/*Chequea que el valor medido no se pase de los limites indicados, sino dispara la alarna*/
	if( (Resultado_ADC > TOLERANCIA_SUPERIOR) || (Resultado_ADC < TOLERANCIA_INFERIOR) )
	{
		/*Pone el flag del sensor de peso en Estado Alto*/
		Sensor_Peso = TRUE;
		return TRUE;
	}
	return FALSE;
}
/****************************************************************************************/
// ----------------------------------------------------------------------------------------------

/*************** Pasa numeros enteros a numeros ascii ***************/
char itoa ( int num )
{
	switch( num )
	{
	case 0: return '0';	break;
	case 1: return '1';	break;
	case 2: return '2';	break;
	case 3: return '3';	break;
	case 4: return '4';	break;
	case 5: return '5';	break;
	case 6: return '6';	break;
	case 7: return '7';	break;
	case 8: return '8';	break;
	case 9: return '9';	break;
	default: return (0xFF); break;
	}
}
/********************************************************************/

/**************** Pasa numeros char a numeros enteros ***************/
int atoi ( char num )
{
	switch( num )
	{
	case '0': return 0;	break;
	case '1': return 1;	break;
	case '2': return 2;	break;
	case '3': return 3;	break;
	case '4': return 4;	break;
	case '5': return 5;	break;
	case '6': return 6;	break;
	case '7': return 7;	break;
	case '8': return 8;	break;
	case '9': return 9;	break;
	default: return (0xFF); break;
	}
}
/********************************************************************/

// Estados Actuales de los Sensores -------------------------------------------------------------
/***********Indica el Estado Actual del Sensor Infrarojo***********/
uint8_t Estado_Infrarrojo (void)
{
	if(GetPIN(IN2) == 0)	return TRUE;	//Es Activo Bajo
	else					return FALSE;
}
/****************************************************************/

/***********Indica el Estado Actual del Sensor de Peso***********/
uint8_t Estado_Balanza (void)
{
	return Deteccion_Variacion_Peso();	//Devuelve TRUE o FALSE segun este dentro de la tolerancia o fuera de la misma
}
/****************************************************************/
// ----------------------------------------------------------------------------------------------


// Funciones de Control de Timer0 ---------------------------------------------------------------
/***********************Activa el Timer0************************/
void ActivarTimer( void )
{
	/*Reseteo y Activo el Timer0*/
	T0TCR = 0x00000002;
	T0TCR = 0x00000001;
}
/****************************************************************/

/*********************Desactiva el Timer0************************/
void DesactivarTimer( void )
{
	/*Desactivo y Reseteo el Timer0*/
	T0TCR = 0x00000002;
	T0TCR = 0x00000000;
}
/****************************************************************/
// ----------------------------------------------------------------------------------------------

