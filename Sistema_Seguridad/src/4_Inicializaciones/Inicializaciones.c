/*
===============================================================================
INICIALIZACIONES
===============================================================================
*/
#include "Header.h"

/*Decalracion de Variables externas*/
extern uint8_t	MasterPass[];
extern uint16_t Valor_Objeto;

//---------------------------------------------------------------------------------
/*********************FUNCION PRINCIPAL DE INICIALIZACION*************************/
void Inicializar( void )
{
	InitPLL();
	InitSysTick();
	InitTimer0();
	InitUART0();
	InitUART1();
	InitGPIOs();
	InitADC();
	InitTeclado();
	InitDisplay();
	InitAlerta();
	InitAntiPanico();
	Init_LCD();
	InitPassword();
	InitObjeto();
}
/****************************************************/


//---------------------------------------------------------------------------------

/*****************Inicializar SysTick****************/
void InitSysTick( void )
{
	STRELOAD = (STCALIB / DIVISOR) - 1;  //Modifico la Base de tiempo, si (DIVISOR=1) -> (t=10ms)
	STCURR = 0;				//Reinicio el contador
	ENABLE = 1;				//Habilito la SysTick
	TICKINT = 1;			//Habilito la Interrupcion
	CLKSOURCE = 1;			//Selecciono el clock del CPU
}
/****************************************************/


/*****************Inicializar Alerta******************/
void InitAlerta( void )
{
	/*Inicializo la Entrada Digital IN1 como interrupcion externa*/
	SetPINSEL(IN2, FUNCION_1); 	 	//Inicializo como EINT1
	SetPINMODE(IN2, PULL_UP);		//Le asigno un pull-up a la entrada para que tome la alta impedancia recivida como un '1'
	EXTMODE |= (0x01 << 1);			//Modo de Disparo por flanco
	EXTPOLAR &= ~(0x01 << 1);		//Flanco Descendente
	ISER0 |= (0x01 << 19);			//Activo la Interrupcion por EINT1
	EXTINT |= (0x01 << 1);			//Limpio el Flag de interrupcion, escribiendo un 1
}
/***************************************************/


/*****************Inicializa el Boton Antipanico******************/
void InitAntiPanico( void )
{
	/*Inicializo el SW3 del teclado 4x1 como interrupcion externa*/
	SetPINSEL(KEY3, FUNCION_1); //Inicializo como EINT3
	EXTMODE |= (0x01 << 3);		//Modo de Disparo por flanco
	EXTPOLAR &= ~(0x01 << 3);	//Flanco Ascendente, porque el pulsador funciona distinto a los demas
	ISER0 |= (0x01 << 21);		//Activo la Interrupcion por EINT3
	EXTINT |= (0x01 << 3);		//Limpio el Flag de interrupcion, escribiendo un 1
}
/***************************************************/


/*****************Inicializar UART0****************/
void InitUART0 (void)
{
	//1.- Registro PCONP (0x400FC0C4) - bit 3 en 1 prende la UART0:
	PCONP |= (0x01<<3);
	//2.- Registro PCLKSEL0 (0x400FC1A8) - bits 6 y 7 en 0 seleccionan que el clk de la UART0 sea CCLK/4:
	PCLKSEL0 &= ~(0x03<<6);	//con un CCLOK=100Mhz, nos queda PCLOCK=25Mhz
	//3.- Registro U0LCR (0x4001000C) - transmision de 8 bits, 1 bit de stop, sin paridad, sin break cond, DLAB = 1:
	U0LCR = 0x00000083;
	//4.- Registros U0DLL (0x40010000) y U0DLM (0x40010004) - 9600 baudios:
	U0DLM = 0;
	U0DLL = 0xA3;//0xA3 para 9600
	//5.- Registros PINSEL0 (0x4002C000) y PINSEL1 (0x4002C004) - habilitan las funciones especiales de los pines:
	//T01D : PIN ??	->
	SetPINSEL(TX0,FUNCION_1);
	//RX0D : PIN ??	-> 		7
	SetPINSEL(RX0,FUNCION_1);
	//6.- Registro U0LCR, pongo DLAB en 0:
	U0LCR = 0x03;
	//7. Habilito las interrupciones (En la UART -IER- y en el NVIC -ISER)
	U0IER = 0x03;
	ISER0 |= (1<<5);
}
/***************************************************/


/*****************Inicializar UART0****************/
void InitUART1 (void)
{
	//1.- Registro PCONP (0x400FC0C4) - bit 4 en 1 prende la UART1:
	PCONP |= (0x01<<4);
	//2.- Registro PCLKSEL0 (0x400FC1A8) - bits 6 y 7 en 0 seleccionan que el clk de la UART0 sea CCLK/4:
	PCLKSEL0 &= ~(0x03<<8);	//con un CCLOK=100Mhz, nos queda PCLOCK=25Mhz
	//3.- Registro U1LCR (0x4001000C) - transmision de 8 bits, 1 bit de stop, sin paridad, sin break cond, DLAB = 1:
	U1LCR = 0x00000083;
	//4.- Registros U1DLL (0x40010000) y U1DLM (0x40010004) - 9600 baudios:
	U1DLM = 0;
	U1DLL = 0xA3;//0xA3 para 9600
	//5.- Registros PINSEL0 (0x4002C000) y PINSEL1 (0x4002C004) - habilitan las funciones especiales de los pines:
	//TX1D : PIN ??	->
	SetPINSEL(TX1,FUNCION_1);
	//RX1D : PIN ??	-> 		7
	SetPINSEL(RX1,FUNCION_1);
	//6.- Registro U1LCR, pongo DLAB en 0:
	U1LCR = 0x03;
	//7. Habilito las interrupciones (En la UART -IER- y en el NVIC -ISER)
	U1IER = 0x03;
	ISER0 |= (1<<6);
}
/***************************************************/


/*****************Inicializar Modulo GSM****************/
void InitADC(void)
{
	PCONP |= (0x01 << 12);			//Energiso el ADC
	PCLKSEL0 |= (0x03 << 24);		//Le asigno el valor del CCLK/8 = 12,5MHz, porque con pll puse el clk en 100MHz
	AD0CR &= ~(0xFF << CLKDIV);		//Configuro en 0 el divisor del clock para muestrear al aproximadamente 200KHz
	SetPINSEL(ADC2, FUNCION_1);		//Configuro el pin del canal 2 como entrada analogica
	AD0CR &= ~(0xFF << SEL);		//Desactivo todos los canales del ADC
	AD0CR |= (0x01 << 2);			//Activo el canal 2
	AD0INTEN &= ~(0x01 << ADGINTEN);//Configuro Interrupciones por canal
	AD0INTEN |= (0x01 << ADINTEN2);	//Activo Interrupcion por Canal 2
	IPR5 |= (0x1F << 19);			//Interrupcion del ADC en mínima prioridad
	ISER0 |= (0x01 << 22);			//Activo las Interrupciones del ADC
	AD0CR &= ~(0x07 << START);		//Configuro START "000"
	AD0CR |= (0x01 << PDN);			//Enciendo el ADC
	AD0CR |= (0x01 << BURST);		//EL ADC comienza a muestrear de forma automatica
}
/****************************************************/


/*****************Inicializar GPIOs******************/
void InitGPIOs( void )
{
	/* Buzzer como Salida */
	SetPINSEL(BUZZ, FUNCION_GPIO);
	SetDIR(BUZZ, SALIDA);
	SetPIN(BUZZ, ON);		//Apaga el Buzzer

	/* Led RGB como Salida */
	SetPINSEL(RGBB, FUNCION_GPIO);
	SetPINSEL(RGBG, FUNCION_GPIO);
	SetPINSEL(RGBR, FUNCION_GPIO);
	SetDIR(RGBB, SALIDA);
	SetDIR(RGBG, SALIDA);
	SetDIR(RGBR, SALIDA);
	/*Seteo todos como Apagados*/
	SetPIN(RGBR, OFF);
	SetPIN(RGBG, OFF);
	SetPIN(RGBB, OFF);

	/* Apago Led del Rele Testigo */
	SetPINSEL(LED_R3, FUNCION_GPIO);
	SetPINSEL(LED_R2, FUNCION_GPIO);
	SetPINSEL(LED_R1, FUNCION_GPIO);
	SetPINSEL(LED_R0, FUNCION_GPIO);
	/*Los pongo como salida*/
	SetDIR(LED_R3, SALIDA);
	SetDIR(LED_R2, SALIDA);
	SetDIR(LED_R1, SALIDA);
	SetDIR(LED_R0, SALIDA);
	/*Seteo todos como Apagados*/
	SetPIN(LED_R3, OFF);
	SetPIN(LED_R2, OFF);
	SetPIN(LED_R1, OFF);
	SetPIN(LED_R0, OFF);
}
/***************************************************/

/***************Inicializar Password****************/
void InitPassword( void )
{
	/*Declaracion de Variables auxiliares*/
	uint8_t i;

	/*Leo el nuevo pass del registro flash del LPC*/
	for(i=0; i < NUM_PASS; i++)
	{
		MasterPass[i] = i+1;	//Simulo un pass 1234
	}
}
/***************************************************/

/***************Inicializar Objeto****************/
void InitObjeto( void )
{
	/*Leo el peso del objeto del registro flash del LPC*/
	Valor_Objeto = 2042;		//Es un valor simulado para un objeto de 2kg
}
/***************************************************/


/**************Inicializar Teclado*****************/
 void InitTeclado( void )
{
	//TECLADO 5 x 1 PLACA BASE
	 SetPINSEL( KEY1, FUNCION_GPIO );
	 SetPINSEL( KEY2, FUNCION_GPIO );

	 SetDIR( KEY1, ENTRADA );
	 SetDIR( KEY2, ENTRADA );

	 SetPINMODE( KEY1, PULL_UP );
	 SetPINMODE( KEY2, PULL_UP );

	//TECLADO 4 x 2 EXPANSION 3
	SetPINSEL( FILA_0, FUNCION_GPIO );
	SetPINSEL( FILA_1, FUNCION_GPIO );
	SetPINSEL( FILA_2, FUNCION_GPIO );
	SetPINSEL( FILA_3, FUNCION_GPIO );
	SetPINSEL( COL_0, FUNCION_GPIO );
	SetPINSEL( COL_1, FUNCION_GPIO );

	//Configuro como ENTRADA
	SetDIR( FILA_0, SALIDA );
	SetDIR( FILA_1, SALIDA );
	SetDIR( FILA_2, SALIDA );
	SetDIR( FILA_3, SALIDA );
	SetDIR( COL_0, ENTRADA );
	SetDIR( COL_1, ENTRADA );

	// Las Setteo segun su configuracion, generalmente pull-up
	SetPINMODE( COL_0, PULL_DOWN );
	SetPINMODE( COL_1, PULL_DOWN );
}
/***************************************************/


/**************Inicializar Display*****************/
void InitDisplay( void )
{
	//Display 7 Segmentos, Expansion 3

	//Inicializo como GPIO
	SetPINSEL( BCD_A , FUNCION_GPIO );
	SetPINSEL( BCD_B, FUNCION_GPIO );
	SetPINSEL( BCD_C, FUNCION_GPIO );
	SetPINSEL( BCD_D, FUNCION_GPIO );
	SetPINSEL( CLK, FUNCION_GPIO );
	SetPINSEL( RST, FUNCION_GPIO );

	//Establesco como SALIDA
	SetDIR( BCD_A, SALIDA );
	SetDIR( BCD_B, SALIDA );
	SetDIR( BCD_C, SALIDA );
	SetDIR( BCD_D, SALIDA );
	SetDIR( CLK, SALIDA );
	SetDIR( RST, SALIDA );
}
/***************************************************/


/*******************Inicializacion del TIMER0*****************************/
void InitTimer0(void)
{
	/*Alimento el timer0*/
	PCONP |= 1 << 1 ;
	PCLKSEL0 |= 0 << 2 ;
	/*Cargo el valor de Match*/
	T0MR0 = 0x6ffffff;
	/*Habilito interrupcion y reseteo cuando se llega al valor de match*/
	T0MCR  = ( ( 1 << MR0I ) | ( 1 << MR0R ) | ( 0 << MR0S ) ) ;
	/*habilito la interrupcion de timer0*/
	ISER0 |= ( 1 << 1 ) ;
}
/***********************************************************************/


/*******************Inicializacion del LCD*****************************/ //NUEVO
void Init_LCD ( void )
{
	unsigned int i,j;

	//1.- Selecciono los bits del puerto como GPIOs y los direccion DE e/s:
	SetPINSEL ( LCD_D4 , FUNCION_GPIO);
	SetPINSEL ( LCD_D5 , FUNCION_GPIO);
	SetPINSEL ( LCD_D6 , FUNCION_GPIO);
	SetPINSEL ( LCD_D7 , FUNCION_GPIO);
	SetPINSEL ( LCD_RS , FUNCION_GPIO);
	SetPINSEL ( LCD_BF , FUNCION_GPIO);
	SetPINSEL ( LCD_E , FUNCION_GPIO);

	SetDIR ( LCD_D4 , SALIDA);
	SetDIR ( LCD_D5 , SALIDA);
	SetDIR ( LCD_D6 , SALIDA);
	SetDIR ( LCD_D7 , SALIDA);
	SetDIR ( LCD_RS , SALIDA);
	SetDIR ( LCD_BF , ENTRADA);
	SetDIR ( LCD_E , SALIDA);

	// Inicializacion del LCD => en D7-D4; envio comando (RS=0), 0x3 tres veces c/demora

	for( i = 0 ; i < 3 ; i++ )
	{
		LCD_E_OFF;
		for ( j = 0 ; j < 500000 ; j++ ); // 300000
		LCD_DATO(1,1,0,0);

		LCD_RS_OFF;
		LCD_E_ON;

		for( j = 0 ; j < 10000 ; j++ );//4500

		LCD_E_OFF;
	}

	LCD_E_OFF;

	//envio comando (RS=0), 0x2 una vez c/demora

	for ( j = 0 ; j < 500000 ; j++ ); // 300000

	LCD_DATO(0,1,0,0);

	LCD_RS_OFF;
	LCD_E_ON;

	for( j = 0 ; j < 10000 ; j++ );//4500

	LCD_E_OFF;

	// A partir de aca pasa a 4 bits
	Dato_LCD( 0x28 , LCD_CONTROL );
	Dato_LCD( 0x08 , LCD_CONTROL);	// display OFF
	Dato_LCD( 0x01 , LCD_CONTROL);	// clear display
	for( j = 0 ; j < 10000 ; j++ );	//delay por la instruccion clear display
	Dato_LCD( 0x06 , LCD_CONTROL);	// programo el LCD para mis necesidades
	Dato_LCD( 0x0C , LCD_CONTROL);	// display ON,sin cursor y blinking OFF del cursor
}
/*******************************************************************************************/
