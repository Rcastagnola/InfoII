################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/1_Aplicacion/main.c 

OBJS += \
./src/1_Aplicacion/main.o 

C_DEPS += \
./src/1_Aplicacion/main.d 


# Each subdirectory must supply rules for building sources it contributes
src/1_Aplicacion/%.o: ../src/1_Aplicacion/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: MCU C Compiler'
	arm-none-eabi-gcc -D__REDLIB__ -DDEBUG -D__CODE_RED -DCORE_M3 -D__LPC17XX__ -I"C:\Users\Julian\Desktop\UTN\Informatica 2\LPCXpresso\Workspace\Sistema_Seguridad_v14\src\5_Headers" -O0 -g3 -Wall -c -fmessage-length=0 -fno-builtin -ffunction-sections -fdata-sections -mcpu=cortex-m3 -mthumb -specs=redlib.specs -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


