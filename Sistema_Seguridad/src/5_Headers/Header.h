/*
===============================================================================
Header.h
===============================================================================
*/
#ifndef HEADER_H
#define HEADER_H

#include "Oscilador.h"
#include "RegsLPC1769.h"
#include "Definiciones_Utiles.h"


/* Prototipo de Funcion, Maquina de Estado del Sistema de Seguridad */
void Maquina_Sistema_Seguridad( void ); //falta lo de display alfa-num


/* Prototipo de Funciones Principales del Sistema */
void Estado_Sistema( void );
void EnvioSMS(void);
void InicioGSM(void);


/*Modificadores desde PC*/
void Sistema_OnOff( void );
void Alarma_OnOff( void );
uint8_t ValidarPassPC( void );
void CambirPass( void );
void CambirObjeto( void );


/* Prototipo de Funciones Principales del Sistema */
uint8_t Password( void );		//TESTEADA, FUNCIONA 100%
uint8_t Check_Pass( void ); //
uint8_t Check_Sensores( void ); //
void Activar_Sistema( void ); //
void Desactivar_Sistema( void ); //
void Activar_Alerta( void ); //
void Desactivar_Alerta( void ); //
void Activar_Alarma( void ); //
void Desactivar_Alarma( void ); //


/* Driver del Esto de los Sensores */
uint8_t Estado_Balanza( void );
uint8_t Estado_Infrarrojo( void );

/* Funciones de Control de Timer0 */
void ActivarTimer( void );
void DesactivarTimer( void );

/* Prototipo de Funciones Primitivas */
uint8_t Teclado( void );
void Display_7Seg( uint32_t );


/* Prototipo de Funciones LCD*/
void Dato_LCD ( unsigned char, unsigned char  );
void Display_lcd( char*, char, char  );


/* Prototipos de Funciones Basicas */
uint8_t Barrido_Teclado( void );
void Validacion_Teclado( void );
void Barrido_Display( void );

/* Funcioes ADC */
void ActivarADC( void );
void DesactivarADC( void );
uint16_t Medicion_Peso( void );
void Integrador_ADC( uint32_t );
uint8_t Deteccion_Variacion_Peso( void );

/*Prototipos de Funciones de Utilizacion de UART*/
void RecibirDatos( void );
void Transmitir1( char* );
char itoa( int );
int atoi ( char );

/* Prototipos de Funciones UART0 */
void PushRx0( uint8_t );
uint8_t PopTx0( void );
void PushTx0( uint8_t );
uint8_t PopRx0( void );
/* Prototipos de Funciones UART0 */
void PushRx1( uint8_t );
uint8_t PopTx1( void );
void PushTx1( uint8_t );
uint8_t PopRx1( void );


/* Funciones de Inicializaciones */
void Inicializar( void );
void InitPLL( void );
void InitUART0( void );
void InitUART1( void );
void InitADC( void );
void InitGPIOs( void );
void InitTeclado( void );
void InitDisplay( void );
void InitTimer0( void );
void InitSysTick( void );
void InitAlerta( void );
void InitAntiPanico( void );
void InitPassword( void );
void InitObjeto( void );
void Init_LCD( void );


/* Prototipos de Funciones a nivel PIN */
void ConfigPIN( uint8_t, uint8_t, uint8_t, uint8_t );
void ConfigSALIDA( uint8_t, uint8_t, uint8_t );
void SetPINSEL( uint8_t, uint8_t, uint8_t );
void SetPINMODE( uint8_t, uint8_t, uint8_t );
void SetDIR( uint8_t, uint8_t, uint8_t );
void SetPIN( uint8_t, uint8_t, uint8_t );
uint8_t GetPIN( uint8_t, uint8_t );

#endif
