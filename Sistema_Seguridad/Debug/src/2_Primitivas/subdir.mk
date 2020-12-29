################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/2_Primitivas/Funciones.c \
../src/2_Primitivas/Funciones_de_Estados.c \
../src/2_Primitivas/Maquina_Estado.c \
../src/2_Primitivas/Primitivas_UART.c 

OBJS += \
./src/2_Primitivas/Funciones.o \
./src/2_Primitivas/Funciones_de_Estados.o \
./src/2_Primitivas/Maquina_Estado.o \
./src/2_Primitivas/Primitivas_UART.o 

C_DEPS += \
./src/2_Primitivas/Funciones.d \
./src/2_Primitivas/Funciones_de_Estados.d \
./src/2_Primitivas/Maquina_Estado.d \
./src/2_Primitivas/Primitivas_UART.d 


# Each subdirectory must supply rules for building sources it contributes
src/2_Primitivas/%.o: ../src/2_Primitivas/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: MCU C Compiler'
	arm-none-eabi-gcc -D__REDLIB__ -DDEBUG -D__CODE_RED -DCORE_M3 -D__LPC17XX__ -I"C:\Users\Julian\Desktop\UTN\Informatica 2\LPCXpresso\Workspace\Sistema_Seguridad_v14\src\5_Headers" -O0 -g3 -Wall -c -fmessage-length=0 -fno-builtin -ffunction-sections -fdata-sections -mcpu=cortex-m3 -mthumb -specs=redlib.specs -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


