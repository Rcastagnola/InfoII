/*
===============================================================================
Definiciones Utiles
===============================================================================
*/
#ifndef DEFUTILES_H_
#define DEFUTILES_H_

/*Variables Externas*/
extern uint16_t Valor_Objeto;	// VER

/*********************Cambiar Objeto************************* // VER
void CambiarObjeto( void )	//Mientras el sistema esta desactivado se debe colocar el nuevo objeto sobre el sensor, un vez esto desde la pc se envia
{							//al trama de reemplazar objeto y se llama a esta funcion que lo que hace es leer el valor actual del ADC y tomarlo como
							//nuevo punto de partida
	Valor_Objeto = Resultado_ADC;
}
************************************************************/


// DEFINICIONES UTILES --------------------------------------------------------------------------

/* Largo maximo de buffer UART0 y UART1 */
#define		TOPE0			48
#define		TOPE1			48

/*Maquina de Estado Desentramado de Resepcion de UART1*/
#define		ESPERO_INICIADOR		0
#define		RECIVO_PASS				1
#define		ESPERO_ACCION			2
#define		SISTEMA_ON_OFF			3
#define		ALARMA_ON_OFF			4
#define		CAMBIAR_PASS			5
#define		CAMBIAR_OBJETO			6

/*Maquina de Estado de envio de mensajes por GSM*/
#define		INICIO_GSM				1
#define		MODO_TEXTO				2
#define		CONFIG_CEL				3
#define		ENVIO_SMS				4


/* Valores de Ajuste del ADC */
#define		CONV1_CUENTAS_GRAMOS	1.07634
#define		CONV2_CUENTAS_GRAMOS	0.98452
#define		CONV3_CUENTAS_GRAMOS	0.80696
#define		INTEGRADOR_ADC			31250	//64 veces por segundo


/* Constantes de Deteccion de Variacoin de Peso */
#define		TOLERANCIA_SUPERIOR		(Valor_Objeto * 1.07)	//Limite superior una variacion del 7% por encima
#define		TOLERANCIA_INFERIOR		(Valor_Objeto * 0.93)	//Limite inferior una variacion del 7% por debajo


/* Divisor de Base de tiempo de la SysTick */
#define 	DIVISOR					4		//Interrupciones cada 2.5ms - Dividir por 1 equivale a interrupciones cada 10ms
#define 	TIMER_ESTADO_ACTUAL		40		//Envia cada 100ms
#define		TIMER_TECLADO			2		//Lee cada 5ms
#define		TIMER_DISPLAY			1		//Barre cada 2.5ms


/* Utilizaciones en Teclado */
#define		NO_KEY			(uint8_t) 0xFF
#define 	VALIDACION		20			//Equivale a la cantidad de veces que debera leerse la misma tecla para validarla


/* Largo del vector del Password */
#define		NUM_PASS		4

/* Display 7 Segmentos */
#define 	CANT_DIGITOS	6

/* Estados de la Maquina */
#define 	DESACTIVADO		0
#define 	ESPERA			1
#define 	ALERTA			2
#define 	ALARMA			3

/* Estados Logicos */
#define 	ON 				1
#define 	OFF 			0
#define 	TRUE  			1
#define 	FALSE  			0
#define 	SI 				1
#define 	NO	 			0

/* Estados de Actividad */
#define 	ACTIVO_ALTO 	1
#define		ACTIVO_BAJO 	0

/* Direccion del Pin */
#define		ENTRADA			0
#define		SALIDA 			1

/* Funcion del Pin */
#define		FUNCION_GPIO	0
#define		FUNCION_1		1
#define		FUNCION_2		2
#define		FUNCION_3		3

/* Modo del Pin */
#define 	PULL_UP			0
#define 	REPEATER		1
#define 	NONE			2  	//No es ni PULL-UP, ni PULL-DOWN
#define 	PULL_DOWN		3


// PLACA BASE--------------------------------------------------------------------------------

/* Puertos Asociados a Entradas Analogicas del ADC */
#define		ADC0			P0,23		//Funcion 01
#define		ADC1			P0,24		//Funcion 01
#define		ADC2			P0,25		//Funcion 01
#define		ADC3			P0,26		//Funcion 01
#define		ADC4			P1,30		//Funcion 11
#define		ADC5			P1,31		//Funcion 11
#define		ADC6			P0,3		//Funcion 10
#define		ADC7			P0,2		//Funcion 10

/* Puertos Asociados a Interrupciones Externas */
#define		EINT0      		P2,10
#define		EINT1     		P2,11
#define		EINT2      		P2,12
#define		EINT3     		P2,13

/* Puertos de entrada y salida de UARTs */
#define 	TX0				PORT0, 2		//Tx de la UART0
#define 	RX0				PORT0, 3		//Rx de la UART0
#define 	TX1				PORT0,15		//Tx de la UART1
#define 	RX1				PORT0,16 		//Rx de la UART1

/* TECLADO 4 x 1 */
#define		KEY0			P2,10		   //SW1
#define		KEY1			P0,18		   //SW2
#define		KEY2			P0,11		   //SW3
#define		KEY3			P2,13		   //SW4 RC
#define		KEY4			P1,26 //EXTRA  //SW5 RC


//Leds de los Reles:
#define		LED_R0		PORT2,0 		//GPIO2
#define		LED_R1		PORT0,23		//GPIO0
#define		LED_R2		PORT0,21		//GPIO0
#define		LED_R3		PORT0,27		//GPIO0

//Led RGB:
#define		RGBB		PORT2,1			//GPIO2
#define		RGBG		PORT2,2			//GPIO2
#define		RGBR		PORT2,3			//GPIO2

//BUZZER:
#define		BUZZ		PORT0,28		//GPIO0

//Entradas digitales:
#define		IN0			PORT1,26		//GPIO1
#define		IN1			PORT4,29		//GPIO4
#define		IN2			PORT2,11		//GPIO2

//GPIOS LCD:
#define		LCD_D4		PORT0,5			//GPIO0
#define		LCD_D5		PORT0,10		//GPIO0
#define		LCD_D6		PORT2,4			//GPIO2
#define		LCD_D7		PORT2,5			//GPIO2
#define		LCD_RS		PORT2,6			//GPIO2
#define		LCD_BF		PORT0,28		//GPIO1
#define		LCD_E		PORT0,4			//GPIO0

//ADC:
#define 	ADC5		P1,31	//ADC5	//es el pote (OJO! el plano indica ADC0)
#define 	ADC1		P0,24	//ADC1	//termistor
#define 	ADC2		P0,25	//ADC2	//entrada libre


// PLACAS DE EXPANCION ------------------------------------------------------------------------
// Identificación de los puertos de expansion:
#define EXPANSION0		PORT2,7
    #define 	LED1        EXPANSION0 	// PLACA EXPANSION 1
    #define 	DIG1        EXPANSION0	// PLACA EXPANSION 2
    #define 	BCD_A       EXPANSION0	// PLACA EXPANSION 3
#define EXPANSION1		PORT1,29
    #define 	LED2        EXPANSION1	// PLACA EXPANSION 1
    #define 	DIG2        EXPANSION1	// PLACA EXPANSION 2
    #define		BCD_B       EXPANSION1	// PLACA EXPANSION 3
#define EXPANSION2		PORT4,28
    #define 	LED3        EXPANSION2	// PLACA EXPANSION 1
    #define 	DIG3        EXPANSION2	// PLACA EXPANSION 2
    #define 	BCD_C       EXPANSION2	// PLACA EXPANSION 3
#define EXPANSION3		PORT1,23
    #define 	LED4        EXPANSION3	// PLACA EXPANSION 1
    #define 	DIG4        EXPANSION3	// PLACA EXPANSION 2
    #define 	BCD_D       EXPANSION3	// PLACA EXPANSION 3
#define EXPANSION4		PORT1,20
    #define 	LED5        EXPANSION4	// PLACA EXPANSION 1
    #define 	DIG5        EXPANSION4	// PLACA EXPANSION 2
    #define 	seg_DP      EXPANSION4	// PLACA EXPANSION 3
#define EXPANSION5		PORT0,19
    #define 	LED6        EXPANSION5	// PLACA EXPANSION 1
    #define 	DIG6        EXPANSION5	// PLACA EXPANSION 2
    #define 	CLK         EXPANSION5	// PLACA EXPANSION 3
#define EXPANSION6		PORT3,26
    #define 	LED7        EXPANSION6	// PLACA EXPANSION 1
    #define 	seg_a       EXPANSION6	// PLACA EXPANSION 2
    #define 	RST         EXPANSION6	// PLACA EXPANSION 3
#define EXPANSION7		PORT1,25
    #define 	LED8        EXPANSION7	// PLACA EXPANSION 1
    #define 	FILA_0      EXPANSION7	// PLACA EXPANSION 3
#define EXPANSION8		PORT1,22
    #define 	DIP1_1      EXPANSION8	// PLACA EXPANSION 1
    #define 	FILA_1      EXPANSION8	// PLACA EXPANSION 3
#define EXPANSION9		PORT1,19
    #define 	DIP1_2      EXPANSION9	// PLACA EXPANSION 1
    #define 	seg_dp      EXPANSION9	// PLACA EXPANSION 2
    #define 	FILA_2      EXPANSION9	// PLACA EXPANSION 3

#define EXPANSION10		PORT0,20
   #define 		DIP1_3      EXPANSION10	// PLACA EXPANSION 1
   #define 		seg_g       EXPANSION10	// PLACA EXPANSION 2
   #define 		FILA_3      EXPANSION10	// PLACA EXPANSION 3
#define EXPANSION11		PORT3,25
   #define 		DIP1_4      EXPANSION11	// PLACA EXPANSION 1
   #define 		seg_f       EXPANSION11	// PLACA EXPANSION 2
   #define 		COL_0       EXPANSION11	// PLACA EXPANSION 3
#define EXPANSION12		PORT1,27
   #define 		DIP1_5      EXPANSION12	// PLACA EXPANSION 1
   #define 		seg_e       EXPANSION12	// PLACA EXPANSION 2
   #define 		COL_1       EXPANSION12	// PLACA EXPANSION 3
#define EXPANSION13		PORT1,24
   #define 		DIP1_6      EXPANSION13	// PLACA EXPANSION 1
   #define 		seg_d       EXPANSION13	// PLACA EXPANSION 2
#define EXPANSION14		PORT1,21
   #define 		DIP1_7      EXPANSION14	// PLACA EXPANSION 1
   #define 		seg_c       EXPANSION14	// PLACA EXPANSION 2
#define EXPANSION15		PORT1,18
   #define 		DIP1_8      EXPANSION15// PLACA EXPANSION 1
   #define 		seg_b       EXPANSION15// PLACA EXPANSION 2

#define EXPANSION16		PORT1,31
#define EXPANSION17		PORT0,24
#define EXPANSION18		PORT0,25
#define EXPANSION19		PORT0,17
#define EXPANSION20		PORT1,31
#define EXPANSION21		PORT0,22
#define EXPANSION22		PORT0,15

#define EXPANSION23		PORT0,16
   	#define 	DIP2_3      EXPANSION23// PLACA EXPANSION 1
#define EXPANSION24		EXPANSION23
	#define 	DIP2_1      EXPANSION23// PLACA EXPANSION 1
#define EXPANSION25		PORT2,12
    #define 	DIP2_2      EXPANSION25// PLACA EXPANSION 1
//-----------------------------------------------------------------------------------------------------

#endif /* DEFUTILES_H_ */
