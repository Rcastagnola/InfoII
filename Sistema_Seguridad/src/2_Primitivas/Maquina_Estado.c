/*
===============================================================================
Maquina de Estado del Sistema de Seguridad
===============================================================================
*/
#include "Header.h"

/*Variables Externas*/
extern uint8_t Estado;
extern uint8_t Sensor_Peso;
extern uint8_t Sensor_Infrarrojo;


/**************************** Maquina de Estado *******************************/
void Maquina_Sistema_Seguridad(void)
{
	/*Declaracion de Variables*/
	uint8_t flag_actividad = TRUE;
	uint8_t flag_pass = NO_KEY;

	switch(Estado)
	{

	/* Sistema de Seguridad Desactivado */
	case DESACTIVADO:
		/*BORRAR HASTA LA LINEA*/
		SetPIN(LED_R3, ON);
		SetPIN(LED_R2, OFF);
		SetPIN(LED_R1, OFF);
		SetPIN(LED_R0, OFF);
		Display_lcd("Desactivado", 1, 2);							//Muestro estado actual de la maquina
		/*-------------------------*/

		/*Verifico si se ingreso o se esta ingresando algun password*/
		flag_pass = Password();

		/*Si la Contrasena es Correcta*/
		if( flag_pass == TRUE )
		{
			/*Compruebo el Sistema de Seguridad*/
			flag_actividad = Check_Sensores();

			/*Si algun sensor se encuentra alarmado, NO se arma el Sistema*/
			if( flag_actividad == TRUE )
			{
				/*Continuo en Estado Desactivado*/
				Estado = DESACTIVADO;
				break;
			}

			/*Si los sensores se encuentran en estado NO alarmado*/
			if( flag_actividad == FALSE )
			{
				/*Activar Sistema de Seguridad*/
				Activar_Sistema();
				Display_lcd("                ", 0, 0);  //Si entro aca es porque se puso la pass correcta y
														//no tiene que haber cartel de error en los sensores

				/*Paso al Estado de Espera*/
				Estado = ESPERA;
				Display_lcd("             ", 1, 0);		//Limpio DISPLAY, el estado se muestra en el siguiente CASE
				break;
			}
		}

		/*Si la Contrasena es invalida*/
		if( flag_pass == FALSE )
		{
			/*Permanesco en Estado Desactivado*/
			Estado = DESACTIVADO;

			//Password invalida por DISPLAY
			Display_lcd("                ", 0, 0);
			Display_lcd("Password invalid", 0, 0);
			break;
		}

		/*Si NO se preciono Tecla o no se termino de ingresar la contrasena*/
		if( flag_pass == NO_KEY )
		{
			/*Permanesco en Estado Desactivado*/
			Estado = DESACTIVADO;
			break;
		}
		break;


	/* Sistema de Seguridad Activado */
	case ESPERA:
		/*BORRAR HAST LA LINEA*/
		SetPIN(LED_R3, OFF);
		SetPIN(LED_R2, ON);
		SetPIN(LED_R1, OFF);
		SetPIN(LED_R0, OFF);
		Display_lcd("Activado", 1, 4);  	//Muestro estado actual de la maquina
		/*-------------------------*/

		/*Si se Activa el Sensor de Peso*/
		if( Sensor_Peso == TRUE )
		{
			/*Activo la Alarma y Paso al Estado de ALARMA*/
			Activar_Alarma();
			Estado = ALARMA;
			Display_lcd("              ", 1, 0);	//Limpio DISPLAY, el estado se muestra en el siguiente CASE
			break;
		}

		/*Si se Activa el Sensor Infrarrojo*/
		if( Sensor_Infrarrojo == TRUE )
		{
			/*Activo la Alerta y Paso al Estado de ALERTA*/
			Activar_Alerta();
			Estado = ALERTA;
			Display_lcd("             ", 1, 0);
			break;
		}

		/*Verifico si se ingreso o se esta ingresando alguna contrasena*/
		flag_pass = Password();
		/*Si la Contrasena es Correcta*/
		if( flag_pass == TRUE )
		{
			/*Desactivo el Sistema y voy al estado Desactivado*/
			Desactivar_Sistema();
			Estado = DESACTIVADO;
			Display_lcd("                ", 0, 0);	//Si entro aca es porque se puso la pass correcta y
													//no tiene que haber cartel de error en los sensores

			Display_lcd("              ", 1, 0);	//Limpio DISPLAY, el estado se muestra en el siguiente CASE
			break;
		}
		/*Si la Contrasena es invalida*/
		if( flag_pass == FALSE )
		{
			/*Permanezco en Estado de Espera*/
			Estado = ESPERA;

			//Password invalida por DISPLAY
			Display_lcd("                ", 0, 0);
			Display_lcd("Password invalid", 0, 0);
			break;
		}
		/*Si NO se preciono Tecla o no se termino de ingresar la contrasena*/
		if( flag_pass == NO_KEY )
		{
			/*Permanezco en Estado de Espera*/
			Estado = ESPERA;
			break;
		}
		break;


	/* Sistema de Seguridad Alertado */
	case ALERTA:
		/*BORRAR HAST LA LINEA*/
		SetPIN(LED_R3, OFF);
		SetPIN(LED_R2, OFF);
		SetPIN(LED_R1, ON);
		SetPIN(LED_R0, OFF);
		Display_lcd("Alerta", 1, 5);			//Muestro estado actual de la maquin

		/*-------------------------*/
		/*Si se Activa el Sensor de Peso*/
		if( Sensor_Peso == TRUE )
		{
			/*Activo la Alarma y Paso al Estado de ALARMA*/
			Desactivar_Alerta();
			Activar_Alarma();
			Estado = ALARMA;
			Display_lcd("             ", 1, 0);
			break;
		}

		/*Verifico si se ingreso o se esta ingresando alguna contrasena*/
		flag_pass = Password();
		/*Si la Contrasena es Correcta*/
		if( flag_pass == TRUE )
		{
			/*Desactivo la Alerta, desactivo el Sistema y voy al estado Desactivado*/
			Desactivar_Alerta();
			Desactivar_Sistema();
			Estado = DESACTIVADO;

			Display_lcd("                ", 0, 0);	//Si entro aca es porque se puso la pass correcta y
													//no tiene que haber cartel de error en los sensores

			Display_lcd("              ", 1, 0);	//Limpio DISPLAY, el estado se muestra en el siguiente CASE
			break;
		}
		/*Si la Contrasena es invalida*/
		if( flag_pass == FALSE )
		{
			/*Permanesco en Estado Alerta*/
			Estado = ALERTA;

			//Password invalida por DISPLAY
			Display_lcd("                ", 0, 0);
			Display_lcd("Password invalid", 0, 0);
			break;
		}
		/*Si NO se preciono Tecla o no se termino de ingresar la contrasena*/
		if( flag_pass == NO_KEY )
		{
			/*Permanesco en Estado de Alerta*/
			Estado = ALERTA;
			break;
		}
		break;


	/* Sistema de Seguridad Alarmado */
	case ALARMA:
		/*BORRAR HAST LA LINEA*/
		SetPIN(LED_R3, OFF);
		SetPIN(LED_R2, OFF);
		SetPIN(LED_R1, OFF);
		SetPIN(LED_R0, ON);
		Display_lcd("Alarma", 1, 5);		//Muestro estado actual de la maquina
		/*-------------------------*/
		/*Verifico si se ingreso o se esta ingresando alguna contrasena*/
		flag_pass = Password();

		/*Si la Contrasena es Correcta*/
		if( flag_pass == TRUE )
		{
			/*Desactivo la Alarma, desactivo el Sistema y voy al estado Desactivado*/
			Desactivar_Alarma();
			Desactivar_Sistema();
			Estado = DESACTIVADO;

			Display_lcd("                ", 0, 0);	//Si entro aca es porque se puso la pass correcta y
													//no tiene que haber cartel de error en los sensores

			Display_lcd("              ", 1, 0);	//Limpio DISPLAY, el estado se muestra en el siguiente CASE
			break;
		}

		/*Si la Contrasena es invalida*/
		if( flag_pass == FALSE )
		{
			//Password invalida por DISPLAY
			Display_lcd("                ", 0, 0);
			Display_lcd("Password invalid", 0, 0);

		/*Permanezco en Estado Alarma*/
		Estado = ALARMA;
		break;
		}

		/*Si NO se preciono Tecla o no se termino de ingresar la contrasena*/
		if( flag_pass == NO_KEY )
		{
			/*Permanezco en Estado de Alarma*/
			Estado = ALARMA;
			break;
		}
		break;


	/* Estado de Error */
	default:
		/*Se lleva el sistema al estado de Alerta*/
		/*BORRAR*/
		SetPIN(LED_R3, OFF);
		SetPIN(LED_R2, OFF);
		SetPIN(LED_R1, OFF);
		SetPIN(LED_R0, OFF);
		/*-----------------*/
		Activar_Alerta();
		Estado = ALERTA;
		break;
	}
}
/*****************************************************************************/
