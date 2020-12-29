/*
===============================================================================
RegsLPC1769
===============================================================================
*/
#ifndef REGS_H_
#define REGS_H_

/*Prototipo de Variables*/
#define		__RW				volatile
#define		__R					volatile const
typedef 	unsigned int 		uint32_t;
typedef 	unsigned short 		uint16_t;
typedef 	unsigned char 		uint8_t;
typedef 	__RW uint32_t 		registro_t;  //!< defino un tipo 'registro'.
//---------------------------------------------------------------------------------------------------------------

/* Definicion de los Puertos */
#define		P0				0
#define		P1				1
#define		P2				2
#define		P3				3
#define		P4				4
/* Otra Definicion para Puertos */
#define		PORT0			0
#define		PORT1			1
#define		PORT2			2
#define		PORT3			3
#define		PORT4			4


// REGISTROS PINSEL ------------------------------------------------------------------------------------------------------------------------
#define		PINSEL			( (registro_t *) 0x4002C000UL )		//!< Direccion de inicio de los registros PINSEL
#define		PINSEL0         PINSEL[0]
#define		PINSEL1         PINSEL[1]
#define		PINSEL2         PINSEL[2]
#define		PINSEL3         PINSEL[3]
#define		PINSEL4         PINSEL[4]
#define		PINSEL5         PINSEL[5]
#define		PINSEL6         PINSEL[6]
#define		PINSEL7         PINSEL[7]
#define		PINSEL8         PINSEL[8]
#define		PINSEL9         PINSEL[9]
//---------------------------------------------------------------------------------------------------------------

// REGISTROS PINMODE ------------------------------------------------------------------------------------------------------------------------
#define		PINMODE			( (registro_t *) 0x4002C040UL )		//!< Direccion de inicio de los registros de modo de los pines del GPIO
#define		PINMODE0         PINMODE[0]
#define		PINMODE1         PINMODE[1]
#define		PINMODE2         PINMODE[2]
#define		PINMODE3         PINMODE[3]
#define		PINMODE4         PINMODE[4]
#define		PINMODE5         PINMODE[5]
#define		PINMODE6         PINMODE[6]
#define		PINMODE7         PINMODE[7]
#define		PINMODE8         PINMODE[8]
#define		PINMODE9         PINMODE[9]
//---------------------------------------------------------------------------------------------------------------

// REGISTROS PINMODE_OD ------------------------------------------------------------------------------------------------------------------------
#define		PINMODE_OD		 ( (registro_t *) 0x4002C068UL )		//!< Direccion de inicio de los registros de modo de los pines del GPIO
#define		PINMODE_OD0      PINMODE_OD[0]
#define		PINMODE_OD1      PINMODE_OD[1]
#define		PINMODE_OD2      PINMODE_OD[2]
#define		PINMODE_OD3      PINMODE_OD[3]
#define		PINMODE_OD4      PINMODE_OD[4]
//---------------------------------------------------------------------------------------------------------------

// REGISTROS GPIO ------------------------------------------------------------------------------------------------------------------------
#define		GPIO			( (registro_t *) 0x2009C000UL )		//!< Direccion de inicio de los registros de GPIOs

/*Puerto 0*/
#define		FIO0DIR			GPIO[0]
#define		FIO0MASK		GPIO[4]
#define		FIO0PIN			GPIO[5]
#define		FIO0SET			GPIO[6]
#define		FIO0CLR			GPIO[7]

/*Puerto 1*/
#define		FIO1DIR			GPIO[8]
#define		FIO1MASK		GPIO[12]
#define		FIO1PIN			GPIO[13]
#define		FIO1SET			GPIO[14]
#define		FIO1CLR			GPIO[15]

/*Puerto 2*/
#define		FIO2DIR			GPIO[16]
#define		FIO2MASK		GPIO[20]
#define		FIO2PIN			GPIO[21]
#define		FIO2SET			GPIO[22]
#define		FIO2CLR			GPIO[23]

/*Puerto 3*/
#define		FIO3DIR			GPIO[24]
#define		FIO3MASK		GPIO[28]
#define		FIO3PIN			GPIO[29]
#define		FIO3SET			GPIO[30]
#define		FIO3CLR			GPIO[31]

/*Puerto 4*/
#define		FIO4DIR			GPIO[32]
#define		FIO4MASK		GPIO[36]
#define		FIO4PIN			GPIO[37]
#define		FIO4SET			GPIO[38]
#define		FIO4CLR			GPIO[39]
//---------------------------------------------------------------------------------------------------------------


// REGISTROS NVIC -----------------------------------------------------------------------------------------------
/*Nested Vectored Interrupt Controller (NVIC)*/

/* REGISTROS ISER */
#define		ISER		( (registro_t *) 0xE000E100UL ) //Direccion de inicio de los registros de habilitación (set) de interrupciones:
#define		ISER0		ISER[0]
#define		ISER1		ISER[1]

/* REGISTROS ICER */
#define		ICER		( (registro_t *) 0xE000E180UL )//Direccion de inicio de los registros de deshabilitacion (clear) de interrupciones:
#define		ICER0		ICER[0]
#define		ICER1		ICER[1]

/* REGISTROS ISPR */
#define		ISPR		( (registro_t *) 0xE000E200UL ) //Direccion de inicio de los registros de set-pending de interrupciones:
#define		ISPR0		ISPR[0]
#define		ISPR1		ISPR[1]

/* REGISTROS ICPR */
#define		ICPR		( (registro_t *) 0xE000E280UL )//Direccion de inicio de los registros de clear-pending de interrupciones:
#define		ICPR0		ICPR[0]
#define		ICPR1		ICPR[1]

/* REGISTROS IABR */
#define		IABR		( (registro_t *) 0xE000E300UL )//Direccion de inicio de los registros de actividad de interrupciones:
#define		IABR0		IABR[0]
#define		IABR1		IABR[1]

/* REGISTROS IPR */
#define		IPR			( (registro_t *) 0xE000E400UL )//Direccion de inicio de los registros de prioridad de interrupciones:
#define		IPR0		IPR[0]
#define		IPR1		IPR[1]
#define		IPR2		IPR[2]
#define		IPR3		IPR[3]
#define		IPR4		IPR[4]
#define		IPR5		IPR[5]
#define		IPR6		IPR[6]
#define		IPR7		IPR[7]
#define		IPR8		IPR[8]

/* REGISTRO STIR */
#define		STIR		( (registro_t  *) 0xE000EF00UL ) //Direccion de inicio de los registros de interrupciones por software:

/* Power Control for Peripherals register [pag. 62 user manual LPC1769] */
#define 	PCONP	(* ( (registro_t  *) 0x400FC0C4UL )) //Direccion de inicio del registro de habilitación de dispositivos

/* Clock Output Configuration register [pag. 66 user manual LPC1769] */
#define 	CLKOUTCFG	(* ( (registro_t *) 0x400FC1C8UL )) //Configuracion de Clock de Salida
	#define		CLKOUTSET		0
	#define		CLKOUTDIV		4
	#define		CLKOUT_EN		8
	#define		CLKOUT_ACT		9

/* Peripheral Clock Selection registers 0 and 1  [pag. 56 user manual] */
#define		PCLKSEL		( (registro_t *) 0x400FC1A8UL )//Direccion de inicio de los registros de seleccion de los CLKs de los dispositivos:
#define		PCLKSEL0	PCLKSEL[0]
#define		PCLKSEL1	PCLKSEL[1]
//---------------------------------------------------------------------------------------------------------------------------------


// REGITROS EINT ------------------------------------------------------------------------------------------------------------------

/* Registros de Configuracion y Control de Interrupciones Externas*/
//#define		EINT		( (registro_t *) 0x400FC140UL)
#define		EXTINT		(* (registro_t *) 0x400FC140UL ) //Registro de interrupciones activas
#define		EXTMODE		(* (registro_t *) 0x400FC148UL ) //Registro de configuracion de modo
#define		EXTPOLAR	(* (registro_t *) 0x400FC14CUL ) //Registro de configuracion de signo

//---------------------------------------------------------------------------------------------------------------------------


// REGISTROS SYSTICK	 --------------------------------------------------------------------------------------------------------
typedef struct
{
	union{
		__RW uint32_t _STCTRL;
		struct{
			__RW uint32_t _ENABLE:1;
			__RW uint32_t _TICKINT:1;
			__RW uint32_t _CLKSOURCE:1;
			__RW uint32_t _RESERVED0:12;
			__RW uint32_t _COUNTFLAG:1;
			__RW uint32_t _RESERVED1:16;
		}bits;
	};
	__RW uint32_t _STRELOAD;
	__RW uint32_t _STCURR;
	__R uint32_t  _STCALIB;

}systick_t;

//!< 0xE000E010UL: Registro de control del SysTick:
#define 	DIR_SYSTICK		( (systick_t *) 0xE000E010UL )

#define		STCTRL		DIR_SYSTICK->_STCTRL
	#define	ENABLE			DIR_SYSTICK->bits._ENABLE
	#define	TICKINT			DIR_SYSTICK->bits._TICKINT
	#define	CLKSOURCE		DIR_SYSTICK->bits._CLKSOURCE
	#define	COUNTFLAG		DIR_SYSTICK->bits._COUNTFLAG
#define		STRELOAD	DIR_SYSTICK->_STRELOAD
#define		STCURR		DIR_SYSTICK->_STCURR
#define		STCALIB		DIR_SYSTICK->_STCALIB
//---------------------------------------------------------------------------------------------------------------------------


// REGISTROS UART0	 --------------------------------------------------------------------------------------------------------
//0x40010000UL : Registro de recepcion de la UART0:
#define		DIR_UART0		( ( __RW uint32_t  * ) 0x4000C000UL )

#define		U0RBR		DIR_UART0[0]
#define		U0THR		DIR_UART0[0]
#define		U0DLL		DIR_UART0[0]
#define		U0IER		DIR_UART0[1]
#define		U0DLM		DIR_UART0[1]
#define		U0IIR		DIR_UART0[2]
#define		U0LCR		DIR_UART0[3]
#define		U0LSR		DIR_UART0[5]
//---------------------------------------------------------------------------------------------------------------------------


// REGISTROS UART1	 --------------------------------------------------------------------------------------------------------
//0x40010000UL : Registro de recepcion de la UART1:
#define		DIR_UART1		( ( __RW uint32_t  * ) 0x40010000UL )

#define		U1RBR		DIR_UART1[0]
#define		U1THR		DIR_UART1[0]
#define		U1DLL		DIR_UART1[0]
#define		U1IER		DIR_UART1[1]
#define		U1DLM		DIR_UART1[1]
#define		U1IIR		DIR_UART1[2]
#define		U1LCR		DIR_UART1[3]
#define		U1LSR		DIR_UART1[5]
//---------------------------------------------------------------------------------------------------------------------------


// REGISTROS DEL LCD -------------------------------------------------------------------------------------------------------
#define		LCD_E_OFF				SetPIN (LCD_E , 0)
	#define		LCD_E_ON				SetPIN (LCD_E , 1)
	#define		LCD_RS_OFF				SetPIN (LCD_RS , 0)
	#define		LCD_RS_ON				SetPIN (LCD_RS , 1)
	#define		LCD_DATO(d4,d5,d6,d7)	SetPIN (LCD_D4 , d4);SetPIN(LCD_D5, d5);SetPIN(LCD_D6  ,d6);SetPIN(LCD_D7, d7)

	#define		LCD_CONTROL		1
	#define		LCD_DATA		0
//---------------------------------------------------------------------------------------------------------------------------


// REGISTROS ADC --------------------------------------------------------------------------------------------------------
/* Registros de Configuracion del ADC */
#define		AD0CR			( *(registro_t *) 0x40034000UL )
	#define		SEL			0
	#define		CLKDIV		8
	#define		BURST		16
	#define		PDN			21
	#define		START		24
	#define		EDGE		27

/* Registros de Datos Globales de ADC */
#define		AD0GDR			( *(registro_t *) 0x40034004UL )
	#define		RESULT		4
	#define		CHN			24
	#define		OVERRUN		30
	#define		DONE		31

/* Registros de Configuracion de Interrupciones del ADC */
#define		AD0INTEN			( *(registro_t *) 0x4003400CUL )
	#define		ADINTEN0		0
	#define		ADINTEN1		1
	#define		ADINTEN2		2
	#define		ADINTEN3		3
	#define		ADINTEN4		4
	#define		ADINTEN5		5
	#define		ADINTEN6		6
	#define		ADINTEN7		7
	#define		ADGINTEN		8   // ADGINTEN=0 => Interrupcion por canal, ADGINTEN=1 => interrupcion por DONE GLOBAL

/* Registros de Datos del Canal 0 al 7 */
#define		AD0DR0			( *(registro_t *) 0x40034010UL )
#define		AD0DR1			( *(registro_t *) 0x40034014UL )
#define		AD0DR2			( *(registro_t *) 0x40034018UL )
#define		AD0DR3			( *(registro_t *) 0x4003401CUL )
#define		AD0DR4			( *(registro_t *) 0x40034020UL )
#define		AD0DR5			( *(registro_t *) 0x40034024UL )
#define		AD0DR6			( *(registro_t *) 0x40034028UL )
#define		AD0DR7			( *(registro_t *) 0x4003402CUL )
	#define		RESULT		4
	#define		OVERRUN		30
	#define		DONE		31

/* Registros de Estados de lo resultados de cada Canal */
#define		ADSTAT			( *(registro_t *) 0x40034030UL )
// del bit 0 al 7 DONE
// del bit 8 al 5 OVERRUN
// bit 16 ADINT, indica si hay alguna interrupcion activa

/* Registros de valores de ajuste */
#define		ADTRIM			( *(registro_t *) 0x40034034UL )

//---------------------------------------------------------------------------------------------------------------------------


// REGISTROS TIMER0 ----------------------------------------------------------------------------------------------------------
/* Registros de Configuracion del TIMER0 */
#define		TIMER0			( (registro_t *) 0x40004000UL )

/*Registro de Interrupciones*/
#define		T0IR			TIMER0[ 0 ]			/** IR - INTERRUPT REGISTER */
	#define		IRMR0		0
	#define		IRMR1		1
	#define		IRMR2		2
	#define		IRMR3		3
	#define		IRCR0		4
	#define		IRCR1		5

/*Registros de Configuracion de Timer*/
#define		T0TCR			TIMER0[ 1 ]			/** TCR - TIMER CONTROL REGISTER */
	#define		CE			0  //Bit de Enable
	#define		CR			1  //Bit de Reinicio
#define		T0TC			TIMER0[ 2 ]			/** TC - TIMER COUNTER REGISTER */
#define		T0PR			TIMER0[ 3 ]			/** PR - PRESCALE REGISTER */
#define		T0PC			TIMER0[ 4 ]			/** PC - PRESCALE COUNTER REGISTER */

/*Registro de Configuracion de Match*/
#define		T0MCR			TIMER0[ 5 ]			/** MCR - MATCH CONTROL REGISTER */
	#define		MR0I			0
	#define		MR0R			1
	#define		MR0S			2

	#define		MR1I			3
	#define		MR1R			4
	#define		MR1S			5

	#define		MR2I			6
	#define		MR2R			7
	#define		MR2S			8

	#define		MR3I			9
	#define		MR3R			10
	#define		MR3S			11

/*Registros que Almacenan el Valor de Match */
#define		T0MR0			TIMER0[ 6 ]			/** MR - MATCH REGISTER */
#define		T0MR1			TIMER0[ 7 ]
#define		T0MR2			TIMER0[ 8 ]
#define		T0MR3			TIMER0[ 9 ]

/*Registro Control de Modo Captura*/
#define		T0CCR			TIMER0[ 10 ]
#define		T0CR0			TIMER0[ 11 ]  //Almacena el valor guardado el Capture0
#define		T0CR1			TIMER0[ 12 ]  //Almacena el valor guardado el Capture1

//Los siguientes dos registros NO estan contigüos. Por ende no se continúa con el offset
/*Registro de Configuracion y Control de los Match Externos*/
#define		T0EMR			( * ( (registro_t *) 0x4000403CUL ) )

/*Registro de Configuracion Timer/Counter */
#define		T0CTCR			( * ( (registro_t *) 0x40004070UL ) )/** CTCR - COUNT CONTROL REGISTER */
	#define		TCM			0  //Bits de Configuracion entre Modo Timer o varios Modos Contador
	#define		CIS			2  //Si es Modo Contador, entonces seleccion entre CR0 o CR1
//---------------------------------------------------------------------------------------------------------------------------


// REGISTROS TIMER1 ----------------------------------------------------------------------------------------------------------
/* Registros de Configuracion del TIMER1 */
#define		TIMER1			( (registro_t *) 0x40008000UL )

/*Registro de Interrupciones*/
#define		T1IR			TIMER1[ 0 ]			/** IR - INTERRUPT REGISTER */
	#define		IRMR0		0
	#define		IRMR1		1
	#define		IRMR2		2
	#define		IRMR3		3
	#define		IRCR0		4
	#define		IRCR1		5

/*Registros de Configuracion de Timer*/
#define		T1TCR			TIMER1[ 1 ]			/** TCR - TIMER CONTROL REGISTER */
	#define		CE			0  //Bit de Enable
	#define		CR			1  //Bit de Reinicio
#define		T1TC			TIMER1[ 2 ]			/** TC - TIMER COUNTER REGISTER */
#define		T1PR			TIMER1[ 3 ]			/** PR - PRESCALE REGISTER */
#define		T1PC			TIMER1[ 4 ]			/** PC - PRESCALE COUNTER REGISTER */

/*Registro de Configuracion de Match*/
#define		T1MCR			TIMER1[ 5 ]			/** MCR - MATCH CONTROL REGISTER */
	#define		MR0I			0
	#define		MR0R			1
	#define		MR0S			2

	#define		MR1I			3
	#define		MR1R			4
	#define		MR1S			5

	#define		MR2I			6
	#define		MR2R			7
	#define		MR2S			8

	#define		MR3I			9
	#define		MR3R			10
	#define		MR3S			11

/*Registros que Almacenan el Valor de Match */
#define		T1MR0			TIMER1[ 6 ]			/** MR - MATCH REGISTER */
#define		T1MR1			TIMER1[ 7 ]
#define		T1MR2			TIMER1[ 8 ]
#define		T1MR3			TIMER1[ 9 ]

/*Registro Control de Modo Captura*/
#define		T1CCR			TIMER1[ 10 ]
#define		T1CR0			TIMER1[ 11 ]  //Almacena el valor guardado el Capture0
#define		T1CR1			TIMER1[ 12 ]  //Almacena el valor guardado el Capture1

//Los siguientes dos registros NO estan contigüos. Por ende no se continúa con el offset
/*Registro de Configuracion y Control de los Match Externos*/
#define		T1EMR			( * ( (registro_t *) 0x4000803CUL ) )

/*Registro de Configuracion Timer/Counter */
#define		T1CTCR			( * ( (registro_t *) 0x40008070UL ) )/** CTCR - COUNT CONTROL REGISTER */
	#define		TCM			0  //Bits de Configuracion entre Modo Timer o varios Modos Contador
	#define		CIS			2  //Si es Modo Contador, entonces seleccion entre CR0 o CR1
//-------------------------------------------------------------------------------------------------------------------------


// REGISTROS TIMER2 ------------------------------------------------------------------------------------------------------
/* Registros de Configuracion del TIMER2 */
#define		TIMER2			( (registro_t *) 0x40090000UL )

/*Registro de Interrupciones*/
#define		T2IR			TIMER2[ 0 ]			/** IR - INTERRUPT REGISTER */
	#define		IRMR0		0
	#define		IRMR1		1
	#define		IRMR2		2
	#define		IRMR3		3
	#define		IRCR0		4
	#define		IRCR1		5

/*Registros de Configuracion de Timer*/
#define		T2TCR			TIMER2[ 1 ]			/** TCR - TIMER CONTROL REGISTER */
	#define		CE			0  //Bit de Enable
	#define		CR			1  //Bit de Reinicio
#define		T2TC			TIMER2[ 2 ]			/** TC - TIMER COUNTER REGISTER */
#define		T2PR			TIMER2[ 3 ]			/** PR - PRESCALE REGISTER */
#define		T2PC			TIMER2[ 4 ]			/** PC - PRESCALE COUNTER REGISTER */

/*Registro de Configuracion de Match*/
#define		T2MCR			TIMER2[ 5 ]			/** MCR - MATCH CONTROL REGISTER */
	#define		MR0I			0
	#define		MR0R			1
	#define		MR0S			2

	#define		MR1I			3
	#define		MR1R			4
	#define		MR1S			5

	#define		MR2I			6
	#define		MR2R			7
	#define		MR2S			8

	#define		MR3I			9
	#define		MR3R			10
	#define		MR3S			11

/*Registros que Almacenan el Valor de Match */
#define		T2MR0			TIMER2[ 6 ]			/** MR - MATCH REGISTER */
#define		T2MR1			TIMER2[ 7 ]
#define		T2MR2			TIMER2[ 8 ]
#define		T2MR3			TIMER2[ 9 ]

/*Registro Control de Modo Captura*/
#define		T2CCR			TIMER2[ 10 ]
#define		T2CR0			TIMER2[ 11 ]  //Almacena el valor guardado el Capture0
#define		T2CR1			TIMER2[ 12 ]  //Almacena el valor guardado el Capture1

//Los siguientes dos registros NO estan contigüos. Por ende no se continúa con el offset
/*Registro de Configuracion y Control de los Match Externos*/
#define		T2EMR			( * ( (registro_t *) 0x4009003CUL ) )

/*Registro de Configuracion Timer/Counter */
#define		T2CTCR			( * ( (registro_t *) 0x40090070UL ) )/** CTCR - COUNT CONTROL REGISTER */
	#define		TCM			0  //Bits de Configuracion entre Modo Timer o varios Modos Contador
	#define		CIS			2  //Si es Modo Contador, entonces seleccion entre CR0 o CR1
//----------------------------------------------------------------------------------------------------------------


// REGISTROS TIMER3 -----------------------------------------------------------------------------------------------
/* Registros de Configuracion del TIMER0 */
#define		TIMER3			( (registro_t *) 0x40094000UL )

/*Registro de Interrupciones*/
#define		T3IR			TIMER3[ 0 ]			/** IR - INTERRUPT REGISTER */
	#define		IRMR0		0
	#define		IRMR1		1
	#define		IRMR2		2
	#define		IRMR3		3
	#define		IRCR0		4
	#define		IRCR1		5

/*Registros de Configuracion de Timer*/
#define		T3TCR			TIMER3[ 1 ]			/** TCR - TIMER CONTROL REGISTER */
	#define		CE			0  //Bit de Enable
	#define		CR			1  //Bit de Reinicio
#define		T3TC			TIMER3[ 2 ]			/** TC - TIMER COUNTER REGISTER */
#define		T3PR			TIMER3[ 3 ]			/** PR - PRESCALE REGISTER */
#define		T3PC			TIMER3[ 4 ]			/** PC - PRESCALE COUNTER REGISTER */

/*Registro de Configuracion de Match*/
#define		T3MCR			TIMER3[ 5 ]			/** MCR - MATCH CONTROL REGISTER */
	#define		MR0I			0
	#define		MR0R			1
	#define		MR0S			2

	#define		MR1I			3
	#define		MR1R			4
	#define		MR1S			5

	#define		MR2I			6
	#define		MR2R			7
	#define		MR2S			8

	#define		MR3I			9
	#define		MR3R			10
	#define		MR3S			11

/*Registros que Almacenan el Valor de Match */
#define		T3MR0			TIMER3[ 6 ]			/** MR - MATCH REGISTER */
#define		T3MR1			TIMER3[ 7 ]
#define		T3MR2			TIMER3[ 8 ]
#define		T3MR3			TIMER3[ 9 ]

/*Registro Control de Modo Captura*/
#define		T3CCR			TIMER3[ 10 ]
#define		T3CR0			TIMER3[ 11 ]  //Almacena el valor guardado el Capture0
#define		T3CR1			TIMER3[ 12 ]  //Almacena el valor guardado el Capture1

//Los siguientes dos registros NO estan contigüos. Por ende no se continúa con el offset

/*Registro de Configuracion y Control de los Match Externos*/
#define		T3EMR			( * ( (registro_t *) 0x4009403CUL ) )

/*Registro de Configuracion Timer/Counter */
#define		T3CTCR			( * ( (registro_t *) 0x40094070UL ) )/** CTCR - COUNT CONTROL REGISTER */
	#define		TCM			0  //Bits de Configuracion entre Modo Timer o varios Modos Contador
	#define		CIS			2  //Si es Modo Contador, entonces seleccion entre CR0 o CR1
//-------------------------------------------------------------------------------------------------------------


// REGISTROS RTC -----------------------------------------------------------------------------------------------

/*Registro ILR*/
#define		ILR		( (registro_t *) 0x40024000UL ) //Registro de Interrupciones Activas
	#define		RTCCIF			0
	#define		RTCALF			1

/*Registro CCR*/
#define		CCR		( (registro_t *) 0x40024008UL ) //Registro de Configuracion y Control del RTC
	#define		CLKEN			0
	#define		CTCRST			1
	#define		CCALEN			4

/*Registro CIIR*/
#define		CIIR		( (registro_t *) 0x4002400CUL ) //Registro de Interrupciones por Incremento de Contador
	#define		IMSEC			0
	#define		IMMIN			1
	#define		IMHOUR			2
	#define		IMDOM			3
	#define		IMDOW			4
	#define		IMDOY			5
	#define		IMMON			6
	#define		IMYEAR			7

/*Registro AMR*/
#define		AMR		( (registro_t *) 0x40024010UL ) //Registro para Enmascarar Valores de Setteo de Alarma
	#define		AMRSEC			0
	#define		AMRMIN			1
	#define		AMRHOUR			2
	#define		AMRDOM			3
	#define		AMRDOW			4
	#define		AMRDOY			5
	#define		AMRMON			6
	#define		AMRYEAR			7

/*Registros CTMEx*/
#define		CTIME		( (registro_t *) 0x40024014UL ) //Registros de Tiempo Consolidado
#define		CTIME0		CTIME[0]
#define		CTIME1		CTIME[1]
#define		CTIME2		CTIME[2]

/*Registros de Tiempo Actual*/
#define		TIME		( (registro_t *) 0x40024020UL )
#define		SEC			TIME[0]
#define		MIN			TIME[1]
#define		HOUR		TIME[2]
#define		DOM			TIME[3]
#define		DOW			TIME[4]
#define		DOY			TIME[5]
#define		MON			TIME[6]
#define		YEAR		TIME[7]

/*Registro CALIBRATION*/
#define 	CALIBRATION		( (registro_t *) 0x40024040UL ) //Registro de Calibracion de RTC

/*Registros de Propocitos Generales*/
#define 	GPREG		( (registro_t *) 0x40024044UL )
#define 	GPREG0		GPREG[0]
#define 	GPREG1		GPREG[1]
#define 	GPREG2		GPREG[2]
#define 	GPREG3		GPREG[3]
#define 	GPREG4		GPREG[4]

/*Registro de Configuracion de Alarma*/
#define		ALTIME		( (registro_t *) 0x40024060UL )
#define		ALSEC		ALTIMA[0]
#define		ALMIN		ALTIMA[1]
#define		ALHOUR		ALTIMA[2]
#define		ALDOM		ALTIMA[3]
#define		ALDOW		ALTIMA[4]
#define		ALDOY		ALTIMA[5]
#define		ALMON		ALTIMA[6]
#define		ALYEAR		ALTIMA[7]

/*Registros Auxiliares*/
#define		RTC_AUX		( (registro_t *) 0x4002405CUL )
#define		RTC_AUXEN	( (registro_t *) 0x40024058UL )
//-------------------------------------------------------------------------------------------------------------

#endif
