/*
===============================================================================
Funciones Primitivas
===============================================================================
*/
#include "Header.h"

/*Variables Externas*/
extern uint8_t Estado;
extern uint8_t Buffer_Display[];
extern uint8_t Buffer_Teclado;
extern uint16_t Resultado_ADC;
extern uint8_t passPC[];
extern uint8_t MasterPass[];
extern uint8_t NewPass[];

// FUNCIONES DE TECLADO Y DISPLAY ---------------------------------------------------------------------------
/********************* Funcion Primitiva del Teclado ***********************/
uint8_t Teclado( void )
{
	/*Declaracion de Variables*/
	uint8_t tecla = NO_KEY;

	/*Si hay Tecla*/
	if (Buffer_Teclado != NO_KEY )
	{
		tecla = Buffer_Teclado;		//Tomo la tecla
		Buffer_Teclado = NO_KEY;	//Limpio el Buffer
	}
	return tecla;
}
/****************************************************************/

/********** Funcion Primitiva del Display 7 Segmentos ***********/
void Display_7Seg( uint32_t valor )
{
	/*Declaracion de Variables*/
	uint8_t 	i;

	/*Si tiene 6 Digitos lo Mando*/
	if(valor < 1000000)
	{
		/*Fracionamiento del valor en Digitos*/
		for(i = 0; i < CANT_DIGITOS; i++)		//Tomo digito por digito
		{
			/*Tomo el valor del digito, lo meto en la tabla y obtengo el valor correspondiente en 7Seg*/
			Buffer_Display[CANT_DIGITOS - 1 - i] = valor%10;	//Copio el codigo al Buffer
			valor = valor / 10;		//Divido por 10 para pasar al digito siguiente
		}
	}
	/*Si tiene mas de 6 Digitos pongo Error*/
	else
	{
		/* Deshabilito todos lo digitos */
		for(i=0; i < CANT_DIGITOS; i++ )
		{
			Buffer_Display[i] = 0;
		}
	}
}
/****************************************************************/
//----------------------------------------------------------------------------------------------------------

// Funciones Primitivas ADC --------------------------------------------------------------------------------
/***************** Pasa del Codigo del ADC a gramos ******************/
uint16_t Medicion_Peso (void)
{
	/*Declaracion de Variables*/
	uint16_t aux;

	/*Por debajo de este rango la balanza no sensa*/
	if( Resultado_ADC < 912 ) return 0;

	/*Rango de convercio 1*/
	if( (Resultado_ADC > 912) && (Resultado_ADC < 1706) )
	{
		/*Transformo el valor del ADC a gramos*/
		aux = Resultado_ADC * CONV1_CUENTAS_GRAMOS;
		return aux;
	}

	/*Rango de convercio 2*/
	if( (Resultado_ADC > 1706) && (Resultado_ADC < 2809) )
	{
		/*Transformo el valor del ADC a gramos*/
		aux = Resultado_ADC * CONV2_CUENTAS_GRAMOS;
		return aux;
	}

	/*Rango de convercio 3*/
	if( (Resultado_ADC > 2809) && (Resultado_ADC < 4092) )
	{
		/*Transformo el valor del ADC a gramos*/
		aux = Resultado_ADC * CONV3_CUENTAS_GRAMOS;
		return aux;
	}

	/*Si no entro a ningun if devuelvo un valor fijo indicando error*/
	return 11111;
}
/********************************************************************/
//----------------------------------------------------------------------------------------------------------


// FUNCIONES DEL LCD ---------------------------------------------------------------------------------------
/************* Funcion Principal del LCD ********************/ //NUEVO
void Display_lcd( char* msg , char renglon , char posicion )
{
	  unsigned char i ;

	if( renglon )
        posicion = posicion + 0xc0 ;
	else
		posicion = posicion + 0x80 ;

	Dato_LCD( posicion , LCD_CONTROL );
	for( i = 0 ; msg[ i ] != '\0' ; i++ )
		Dato_LCD( msg[ i ] , LCD_DATA );
}
/**********************************************************/
//----------------------------------------------------------------------------------------------------------


// FUNCIONES DE UTILIZACION DE UART -------------------------------------------------------------------------

/*********** Transmite trama por UART1 ********************/
void Transmitir1 ( char* p )	//BORRAR
{
	/*Declaracion de Variables*/
	uint8_t i;

	/*Cargo los datos en el buffer*/
	for(i = 0; p[i]; i++ )
	{
		PushTx1( p[i] );
	}
}
/******************************************************************************/

/******************** Envia el estado actual del sistema **********************/
void Estado_Sistema( void )
{
	/*Declaracion de Variables*/
	char dato;
	uint16_t peso;
	char stringPeso[4];
	uint8_t aux;
	uint8_t i;

	/*Indico que voy a enviar un paquete de datos con la informacion del estado actual del sistema*/
	PushTx0('$');

	/*Envio el Estado de Sensor Infrarrojo*/
	aux = Estado_Infrarrojo();
	dato = itoa(aux);
	PushTx0(dato);

	/*Envio el Estado de Sensor Peso*/
	aux = Estado_Balanza();
	dato = itoa(aux);
	PushTx0(dato);

	/*Envio el Estado Actual del Sistema*/
	if(Estado == DESACTIVADO)	PushTx0('D');
	if(Estado == ESPERA)		PushTx0('E');
	if(Estado == ALERTA)		PushTx0('A');
	if(Estado == ALARMA)		PushTx0('!');

	/*Indico que despues de la ',' voy a enviar el peso de la balanza*/
	PushTx0(',');

	/*Envio el Peso indicado por la Balanza*/
	peso =  Medicion_Peso();	//Obtengo el valor en gramos de la balanza

	/*Cargo el string que contiene el peso de la balanza*/
	for(i=0; i < 4; i++)
	{
		aux = peso % 10;
		stringPeso[3 - i] = itoa(aux);	//Guardo los numeros de atras para adelante
		peso = peso / 10;
	}
	/*Envio el string con el peso de la balanza*/
	for(i=0; i < 4; i++)	PushTx0(stringPeso[i]);

	/*Indico que el final del paquete*/
	PushTx0('/');
}
/******************************************************************************/

/*************** Maquina de Estado, Desentramado de Resepcion *****************/
void RecibirDatos( void )
{
	/*Declaracion de Varibles*/
	static uint8_t Estado_Resepcion = ESPERO_INICIADOR;
	uint8_t dato;
	uint8_t aux;
	static uint8_t i = 0;

	/*Leo el dato*/
	dato = PopRx0();

	switch(Estado_Resepcion)
	{
	/*Espera inicio de trama*/
	case ESPERO_INICIADOR:
 		/*Chequeo el inicio de trama correspondiente*/
		if(dato == '%')	Estado_Resepcion = RECIVO_PASS;
		else			Estado_Resepcion = ESPERO_INICIADOR;
		break;

	/*Recivo el password*/
	case RECIVO_PASS:
		/*Recivo el pass hasta que me llegue el separador*/
		if( dato != ',' )
		{
			/*Tomo el dato y lo paso a int*/
			aux = atoi(dato);
			/*Si el dato es un dato valido*/
			if( aux != (0xFF) )
			{
				passPC[i] = aux;	//Copio el codigo al Buffer
				i++;
				Estado_Resepcion = RECIVO_PASS;
			}
			/*Se perdio el dato o el dato es invalido, se descarta la trama*/
			else
			{
				i = 0;	//Reinicio el contador
				Estado_Resepcion = ESPERO_INICIADOR;
			}
		}
		/*Llego el separador de trama, paso a leer la accion*/
		else
		{
			i = 0;	//Reinicio el contador
			Estado_Resepcion = ESPERO_ACCION;
		}
		break;

	/*Leo la accion a realizar*/
	case ESPERO_ACCION:
		if( dato == 'D' )	Estado_Resepcion = SISTEMA_ON_OFF;
		if( dato == '!' )	Estado_Resepcion = ALARMA_ON_OFF;
		if( dato == 'C' )	Estado_Resepcion = CAMBIAR_PASS;
		if( dato == 'S' )	Estado_Resepcion = CAMBIAR_OBJETO;
		if( ((dato!='!') && (dato!='D')) && ((dato!='C') && (dato!='S')) ) Estado_Resepcion = ESPERO_INICIADOR;
		break;

	/*Cambio el estado del sistema si se recive el fin de trama*/
	case SISTEMA_ON_OFF:
		/*Si se recive el fin de trama valido el pass y realizo las acciones correspondientes*/
		if( dato == '/' )
		{
			/*Chequeo el pass*/
			aux = ValidarPassPC();
			/*Si se valida el pass se activa o desactiva el sistema*/
			if( aux == TRUE )	Sistema_OnOff();
		}
		/*Vuelvo al inicio*/
		Estado_Resepcion = ESPERO_INICIADOR;
		break;

	/*Cambio el estado del sistema si se recive el fin de trama*/
	case ALARMA_ON_OFF:
		/*Si se recive el fin de trama valido el pass y realizo las acciones correspondientes*/
		if( dato == '/' )
		{
			/*Chequeo el pass*/
			aux = ValidarPassPC();
			/*Si se valida el pass se activa o desactiva la alarma*/
			if( aux == TRUE )	Alarma_OnOff();
		}
		/*Vuelvo al inicio*/
		Estado_Resepcion = ESPERO_INICIADOR;
		break;

	/*Cambia el password del sistema*/
	case CAMBIAR_PASS:
		/*Recibo el nuevo pass hasta que llegue el fin de trama*/
		if( dato != '/' )
		{
			/*Tomo el dato y lo paso a int*/
			aux = atoi(dato);
			/*Si el dato es un dato valido*/
			if( aux != (0xFF) )
			{
				NewPass[i] = aux;	//Copio el codigo al Buffer
				i++;
				Estado_Resepcion = CAMBIAR_PASS;
			}
			/*Se perdio el dato o el dato es invalido, se descarta la trama*/
			else
			{
				i = 0;	//Reinicio el contador
				Estado_Resepcion = ESPERO_INICIADOR;
			}
		}
		/*Llego el fin de trama Guardo el pass en MastePass*/
		if( dato == '/')
		{
			i = 0;	//Reinicio el contador
			/*Chequeo el pass anterior fue valido*/
			aux = ValidarPassPC();
			/*Si se valida el pass anterior se cambia al nuevo pass*/
			if( aux == TRUE )	CambirPass();
			/*Vuelvo al inicio*/
			Estado_Resepcion = ESPERO_INICIADOR;
		}
		break;

		/*Cambia el valor de referencia del objeto a protejer*/
		case CAMBIAR_OBJETO:
			if( dato == '/' )
			{
				/*Chequeo el pass*/
				aux = ValidarPassPC();
				/*Si se valida el pass se activa o desactiva la alarma*/
				if( aux == TRUE )	CambirObjeto();
			}
			/*Vuelvo al inicio*/
			Estado_Resepcion = ESPERO_INICIADOR;
			break;

	default:
		Estado_Resepcion = ESPERO_INICIADOR;
		break;
	}

}
/*******************************************************************/
//----------------------------------------------------------------------------------------------------------


// FUNCIONES MODIFICADORAS DESDE PC -------------------------------------------------------------------------

/*******************Activa o Desactiva el Sistema*******************/
void Sistema_OnOff( void )
{
	/*Decalracion de variables axuiliares*/
	uint8_t aux;

	/*Chequeo el estado actual del sistema*/
	if( Estado == DESACTIVADO )
	{
		/*Verifico si hay sensores activos*/
		aux = Check_Sensores();
		if( aux == FALSE)
		{
			Activar_Sistema();
			/*Limpio el Display*/
			Display_lcd("                ", 0, 0);
			Display_lcd("                ", 1, 0);
			Estado = ESPERA;
		}
	}
	else
	{
		Desactivar_Sistema();
		/*Limpio el Display*/
		Display_lcd("                ", 0, 0);
		Display_lcd("                ", 1, 0);
		Estado = DESACTIVADO;
	}
}
/*******************************************************************/

/*******************Activa o Desactiva la Alarma*******************/
void Alarma_OnOff( void )
{
	/*Chequeo el estado actual del sistema*/
	if( Estado == ALARMA )
	{
			Desactivar_Alarma();
			Desactivar_Sistema();
			/*Limpio el Display*/
			Display_lcd("                ", 0, 0);
			Display_lcd("                ", 1, 0);
			Estado = DESACTIVADO;
	}
	else
	{
		/*Activo la Alarma y Paso al Estado de ALARMA*/
		Desactivar_Alerta();
		Activar_Alarma();
		/*Limpio el Display*/
		Display_lcd("                ", 0, 0);
		Display_lcd("                ", 1, 0);
		Estado = ALARMA;
	}
}
/*******************************************************************/


/*******************Cambia el pass del Sistema**********************/
void CambirPass( void )
{
	/*Declaracion de Variables Auxiliares*/
	uint8_t i;

	/*Guardo el nuevo pass en el pass Maestro*/
	for(i=0; i < NUM_PASS; i++)
	{
		MasterPass[i] = NewPass[i];
	}

	/*Guardo el nuevo pass en un registro*/
}
/*******************************************************************/

/************Cambia el valor de referencia del objeto***************/
void CambirObjeto( void )
{
	/*Cambio el valor de referencia del objeto*/
	Valor_Objeto = Resultado_ADC;
	//Lo guardo en un registro

	/*Para cambiar el objeto, el sistema se debe encontrar en modo desactivado, el nuevo objeto sobre el sensor de peso
	 * se preciona el boton SetPeso en la aplicacion y se recivira la trama que realiza la modificacion */
}
/*******************************************************************/

/*****************Alamacena y Compara el passPC*********************/
uint8_t ValidarPassPC( void )
{
	/*Declaracion de Variables Auxiliares*/
	uint8_t validacion = FALSE;

	/*Comparo el passPC con el MasterPass*/
	if( ((passPC[0] == MasterPass[0])&&(passPC[1] == MasterPass[1])) && ((passPC[2] == MasterPass[2])&&(passPC[3] == MasterPass[3])) )
	{
		validacion = TRUE;
	}

	return validacion;
}
/*******************************************************************/
//----------------------------------------------------------------------------------------------------------
