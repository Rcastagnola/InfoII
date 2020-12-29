/*
===============================================================================
Funciones a Nivel de Pines
===============================================================================
*/
#include "Header.h"


// FUNCIONES DE CONFIGURACION COMPLETA DE PINES --------------------------------------------------------------------------------------------------

/*********************Configuracion Completa de un PIN***********************/
void ConfigPIN ( uint8_t puerto, uint8_t pin, uint8_t estado, uint8_t modo )
{
  /*Declaracion de Variables*/
  uint8_t x;
  uint8_t n;

  /*Seleccion de PINSEL[x]*/
  if( pin < 16 )
  {
    x = (puerto*2);   //Valor de PINSEL, tal que se usara como PINSEL[x]
    n = pin;
  }
  else
  {
    x = (puerto*2) + 1;
    n = pin-16;
  }

  /*Configuracion de PINSEL[x]*/
  PINSEL[x] &= ~( 0x03 << (n*2) );   //Lleno la posicion con 0
  PINSEL[x] |= (estado << (n*2) );   //Coloco mi estado

  /*Configuracion de PINMODE[x]*/
  PINMODE[x] &= ~( 0x03 << (n*2) );  //Lleno la posicion con 0
  PINMODE[x] |=  ( modo << (n*2) );  //Coloco mi modo
}
/****************************************************************/

/************Configuracion Completa de un PIN de Salida**********/
void ConfigSALIDA ( uint8_t puerto, uint8_t pin, uint8_t modo )
{
  /*Declaracion de Variables*/
  uint8_t x;
  uint8_t n;

  /*Seleccion de PINSEL[x]*/
  if( pin < 16 )
  {
    x = (puerto*2);   //Valor de PINSEL, tal que se usara como PINSEL[x]
    n = pin;
  }
  else
  {
    x = (puerto*2) + 1;
    n = pin-16;
  }

  /*Configuracion de PINSEL[x] como GPIO*/
  PINSEL[x] &= ~( 0x03 << (n*2) );  //Cofiguracion como GPIO

  /*Configuracion de PINMODE_OD[x]*/
  PINMODE_OD[x] &= ~( 0x03 << pin );  //Lleno la posicion con 0
  PINMODE_OD[x] |=  ( modo << pin );  //Coloco mi modo
}
/****************************************************************/
//--------------------------------------------------------------------------------------------------------------------------------------------------


// FUNCIONES DE CONFIGURACION PARTICULAR -----------------------------------------------------------------------------------------------------------
/******************Hace uso del Registro PINSEL*******************/
void SetPINSEL( uint8_t puerto , uint8_t pin ,uint8_t funcion )
{
	puerto = puerto * 2 + pin / 16;
	pin = ( pin % 16 ) * 2;
	PINSEL[ puerto ] = PINSEL[ puerto ] & ( ~ ( 3 << pin ) );
	PINSEL[ puerto ] = PINSEL[ puerto ] | ( funcion << pin );
}
/****************************************************************/

/****************Hace uso del Registro PINMODE*******************/
void SetPINMODE( uint8_t puerto , uint8_t pin ,uint8_t modo)
{
	puerto = puerto * 2 + pin / 16;
	pin = ( pin % 16 ) * 2;
	PINMODE[ puerto ] = PINMODE[ puerto ] & ( ~ ( 3 << pin ) );
	PINMODE[ puerto ] = PINMODE[ puerto ] | ( modo << pin );
}
/****************************************************************/


/******************Hace uso del Registro FIOxDIR*****************/
void SetDIR ( uint8_t puerto, uint8_t pin, uint8_t comportamiento )  // 0=Entrada; 1=Salida
{
  /*Configuracion de FIOxDIR*/
  GPIO[8*puerto] &= ~(0x01 << pin);
  GPIO[8*puerto] |= (comportamiento << pin);
}
/****************************************************************/

/*************Hace uso del Registro FIOxPIN*********************/
void SetPIN ( uint8_t puerto, uint8_t pin, uint8_t valor )
{
  /*Escribo en FIOxPIN*/
  GPIO[(8*puerto)+5] &= ~(0x01 << pin);
  GPIO[(8*puerto)+5] |= (valor << pin);
}
/****************************************************************/

/******************Hace uso del Registro FIOxPIN*****************/
uint8_t GetPIN ( uint8_t puerto, uint8_t pin )
{
  /*Leo el valor de FIOxPIN*/
  return( (GPIO[(8*puerto)+5] >> pin) & (0x01) );
}
/****************************************************************/

//---------------------------------------------------------------------------------------------------------------------------------------------------
