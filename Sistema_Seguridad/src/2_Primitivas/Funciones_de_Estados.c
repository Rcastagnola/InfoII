/*
===============================================================================
Funciones Principales de los Estados del Sistema de Seguridad
===============================================================================
*/
#include "Header.h"

/*Variables Externas*/
extern uint8_t Estado;
extern uint8_t Sensor_Peso;
extern uint8_t Sensor_Infrarrojo;
extern uint8_t Pass[];
extern uint8_t	MasterPass[];

/*Variables Globales de GSM*/
extern uint8_t EstadoGSM;
extern uint8_t flagEnvioGSM;

/*************************Funcion de Validacion de Contraseña****************************/
uint8_t Password( void )
{
	/*Declaracion de Variables*/
	static uint8_t i = 0;
	uint8_t condicion = NO_KEY;

	/*Guarda la tecla precionada en el pass del teclado*/
	Pass[i]=Teclado();

	/*Muestro que se leyo el boton pulsado*/
	if(Pass[i] != NO_KEY)
	{
		if( i % 2 )
		{
			SetPIN(RGBR,OFF);
			SetPIN(RGBG,OFF);
			SetPIN(RGBB,ON);
		}
		else
		{
			SetPIN(RGBR,OFF);
			SetPIN(RGBG,ON);
			SetPIN(RGBB,OFF);
		}
	}

	/*Si no se ingreso ninguna tecla*/
	if( Pass[i] == NO_KEY )		      //BORRAR ESTO, "Aca decia que Pass[i-1]!=NO_Key"
	{
		condicion = NO_KEY;
	}
	else
	{
		i++;	//Como Aumento cuando entra entonces comparo directamente con NUM_PASS
		/*Si no se completo la Contraseña*/
		if( i < NUM_PASS )
		{
			Display_lcd("                ", 0, 0);	//Borro asi no dice la Password Invalid hasta tener una completa que chequear
			condicion = NO_KEY;
		}
		/*Hasta que la Password no es del largo correcto no la chequea*/
		if( i == NUM_PASS )
		{
			/*Compruebo la contrasena*/
			condicion = Check_Pass();
			/*Reset del contador del largo da la Password*/
			i = 0;
		}
	}
	return condicion;
}
/*************************************************************************************************/

/***************************Funcion de Modulo SIM, envio de mensaje SMS***************************/
void EnvioSMS(void)
{
	/**/
	switch( EstadoGSM )
	{
	case INICIO_GSM:
		/*Si el flag es verdadero comienzo el envio del SMS*/
		if( flagEnvioGSM == TRUE )
		{
			Transmitir1("AT\r");
			flagEnvioGSM = FALSE;
			EstadoGSM = MODO_TEXTO;
			/*Activo el timer para el proximo envio*/
			ActivarTimer();
		}
		break;

	case MODO_TEXTO:
		/*Configura modo texto*/
		if( flagEnvioGSM == TRUE )
		{
			Transmitir1("AT+CMGF=1 \r");
			flagEnvioGSM = FALSE;
			EstadoGSM = CONFIG_CEL;
		}
		break;

	case CONFIG_CEL:
		/*Configura el numero de telefono*/
		if( flagEnvioGSM == TRUE )
		{
			Transmitir1("AT+CMGS=\"1130794433\" \r");
			flagEnvioGSM = FALSE;
			EstadoGSM = ENVIO_SMS;
		}
		break;

	case ENVIO_SMS:
		/*Envia el Mensaje*/
		if( flagEnvioGSM == TRUE )
		{
			/*Detengo el Timer0*/
			DesactivarTimer();
			Transmitir1("Alarma Sistema de Seguridad \032");
			flagEnvioGSM = FALSE;
			EstadoGSM = INICIO_GSM;
		}
		break;

	default:
		//No hace nada para que no se envien muchos mensajes fallados
		break;
	}
}
/******************************************************************************************/

/*******************************Inicia secuencia de envio de SMS***************************/
void InicioGSM( void )
{
	/*Cargo el Primer Estado*/
	EstadoGSM = INICIO_GSM;
	/*Indico que uede empezar a trasnmitir los comandos*/
	flagEnvioGSM = TRUE;
}
/******************************************************************************************/

/*************************Funcion de Validacion de Contrasena*****************************/
uint8_t Check_Pass( void )
{
	/*Declaracion de Variables*/
	uint8_t validacion = FALSE;

	/*Chequeo el pass para probar el sistema*/
	if( ((Pass[0] == MasterPass[0])&&(Pass[1] == MasterPass[1])) && ((Pass[2] == MasterPass[2])&&(Pass[3] == MasterPass[3])) )
	{
		validacion = TRUE;
	}

	/*BORRAR el if de abajo*/
	if(validacion == FALSE)
	{
		SetPIN(RGBR,ON);
		SetPIN(RGBG,OFF);
		SetPIN(RGBB,ON);
	}

	return validacion;
}
/****************************************************************************************************/


/*****************************Funcion de Validacion de Contrasena***********************************/
uint8_t Check_Sensores( void )
{
	/*Declaracion de Variables*/
	uint8_t estado = TRUE;

	/*Compruebo el estado de los sensores*/
	if( (Estado_Balanza()==FALSE) && (Estado_Infrarrojo()==FALSE) )
	{
		/*Limpio los flag por si se activaron mientras el sistema estubo desactivado*/
		Sensor_Peso = FALSE;
		Sensor_Infrarrojo = FALSE;
		estado = FALSE;
	}
	/*Si se encuentra activo algun sensor informo por display y levanto un flag*/
	if( (Estado_Balanza()==TRUE) || (Estado_Infrarrojo()==TRUE) )
	{
		/*Informo los sensores alarmados*/
		if( Estado_Balanza() == TRUE )
		{
			Display_lcd("                 ", 0, 0);
			Display_lcd("SensorPeso Error", 0, 0);
			Sensor_Peso = FALSE;		//Limpio el flag
		}
		if( Estado_Infrarrojo() == TRUE )
		{
			Display_lcd("                ", 0, 0);
			Display_lcd(" Sensor Ir Error", 0, 0);
			Sensor_Infrarrojo = FALSE;	//Limpio el flag
		}

		/*Indico que hay sensores activos devolviendo TRUE*/
		estado = TRUE;
	}
	return estado;
}
/****************************************************************************************************/


/******************************Activacion del Sistema de Seguridad***********************************/
void Activar_Sistema( void )
{

	/*Activacion Sistema de Seguridad*/
	//Habilita la interrupciones del alerta y alarma

	/*Desactivo las indicaiones luminosas*/
	SetPIN(RGBR, OFF);
	SetPIN(RGBG, OFF);
	SetPIN(RGBB, OFF);

	/*Enciende el ADC*/
	//ActivarADC();
}
/****************************************************************************************************/


/*****************************Desactivacion del Sistema de Seguridad*********************************/
void Desactivar_Sistema( void )
{
	/*Desactivacion Sistema de Seguridad*/
	Sensor_Peso = FALSE;
	Sensor_Infrarrojo = FALSE;

	/*Desactivo todas las indicaiones*/
	SetPIN(RGBR, OFF);
	SetPIN(RGBG, OFF);
	SetPIN(RGBB, OFF);
	SetPIN(BUZZ, ON);		//Apago el buzzer


	//deshabilita la interrupciones del alerta y alarma

	/*Enciende el ADC*/
	//DesactivarADC();

}
/****************************************************************************************************/


/************************************Activacion de la Alerta*****************************************/
void Activar_Alerta( void )
{
	/*Enciendo el Led RGB de color Amarillo*/
	SetPIN(RGBR, ON);
	SetPIN(RGBG, ON);
	SetPIN(RGBB, OFF);
}
/****************************************************************************************************/


/***********************************Desactivacion de la Alerta***************************************/
void Desactivar_Alerta( void )
{
	/*Apago el Led RGB*/
	SetPIN(RGBR, OFF);
	SetPIN(RGBG, OFF);
	SetPIN(RGBB, OFF);
}
/****************************************************************************************************/


/************************************Activacion de la Alarma*****************************************/
void Activar_Alarma( void )
{
	/*Enciendo el Led RGB de color Rojo y el Buzzer*/
	SetPIN(RGBR, ON);
	SetPIN(RGBG, OFF);
	SetPIN(RGBB, OFF);
	SetPIN(BUZZ, OFF);		//Enciendo el buzzer

	/*Indico el flag para en envio del SMS*/
	InicioGSM();
}
/****************************************************************************************************/


/***********************************Desactivacion de la Alarma***************************************/
void Desactivar_Alarma( void )
{
	/*Apago el Led RGB y el Buzzer*/
	SetPIN(RGBR, OFF);
	SetPIN(RGBG, OFF);
	SetPIN(RGBB, OFF);
	SetPIN(BUZZ, ON);		//Apago el buzzer
}
/****************************************************************************************************/
