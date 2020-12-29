################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/3_Drivers/Drivers_UART.c \
../src/3_Drivers/Funciones_Basicas.c \
../src/3_Drivers/Funciones_ISR.c \
../src/3_Drivers/Funciones_PINES.c 

OBJS += \
./src/3_Drivers/Drivers_UART.o \
./src/3_Drivers/Funciones_Basicas.o \
./src/3_Drivers/Funciones_ISR.o \
./src/3_Drivers/Funciones_PINES.o 

C_DEPS += \
./src/3_Drivers/Drivers_UART.d \
./src/3_Drivers/Funciones_Basicas.d \
./src/3_Drivers/Funciones_ISR.d \
./src/3_Drivers/Funciones_PINES.d 


# Each subdirectory must supply rules for building sources it contributes
src/3_Drivers/%.o: ../src/3_Drivers/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: MCU C Compiler'
	arm-none-eabi-gcc -D__REDLIB__ -DDEBUG -D__CODE_RED -DCORE_M3 -D__LPC17XX__ -I"C:\Users\Julian\Desktop\UTN\Informatica 2\LPCXpresso\Workspace\Sistema_Seguridad_v14\src\5_Headers" -O0 -g3 -Wall -c -fmessage-length=0 -fno-builtin -ffunction-sections -fdata-sections -mcpu=cortex-m3 -mthumb -specs=redlib.specs -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


