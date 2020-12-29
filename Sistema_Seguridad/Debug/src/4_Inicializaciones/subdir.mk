################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/4_Inicializaciones/Inicializaciones.c \
../src/4_Inicializaciones/Oscilador_Config.c \
../src/4_Inicializaciones/cr_startup_lpc175x_6x.c \
../src/4_Inicializaciones/crp.c 

OBJS += \
./src/4_Inicializaciones/Inicializaciones.o \
./src/4_Inicializaciones/Oscilador_Config.o \
./src/4_Inicializaciones/cr_startup_lpc175x_6x.o \
./src/4_Inicializaciones/crp.o 

C_DEPS += \
./src/4_Inicializaciones/Inicializaciones.d \
./src/4_Inicializaciones/Oscilador_Config.d \
./src/4_Inicializaciones/cr_startup_lpc175x_6x.d \
./src/4_Inicializaciones/crp.d 


# Each subdirectory must supply rules for building sources it contributes
src/4_Inicializaciones/%.o: ../src/4_Inicializaciones/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: MCU C Compiler'
	arm-none-eabi-gcc -D__REDLIB__ -DDEBUG -D__CODE_RED -DCORE_M3 -D__LPC17XX__ -I"C:\Users\Julian\Desktop\UTN\Informatica 2\LPCXpresso\Workspace\Sistema_Seguridad_v14\src\5_Headers" -O0 -g3 -Wall -c -fmessage-length=0 -fno-builtin -ffunction-sections -fdata-sections -mcpu=cortex-m3 -mthumb -specs=redlib.specs -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


