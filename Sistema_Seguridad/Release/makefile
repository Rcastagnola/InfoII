################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include src/4_Inicializaciones/subdir.mk
-include src/3_Drivers/subdir.mk
-include src/2_Primitivas/subdir.mk
-include src/1_Aplicacion/subdir.mk
-include subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
endif

-include ../makefile.defs

# Add inputs and outputs from these tool invocations to the build variables 

# All Target
all: Sistema_Seguridad_v8.axf

# Tool invocations
Sistema_Seguridad_v8.axf: $(OBJS) $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: MCU Linker'
	arm-none-eabi-gcc -nostdlib -Xlinker -Map="Sistema_Seguridad_v8.map" -Xlinker --gc-sections -mcpu=cortex-m3 -mthumb -T "Sistema_Seguridad_v5_Release.ld" -o "Sistema_Seguridad_v8.axf" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '
	$(MAKE) --no-print-directory post-build

# Other Targets
clean:
	-$(RM) $(OBJS)$(C_DEPS)$(EXECUTABLES) Sistema_Seguridad_v8.axf
	-@echo ' '

post-build:
	-@echo 'Performing post-build steps'
	-arm-none-eabi-size "Sistema_Seguridad_v8.axf"; # arm-none-eabi-objcopy -v -O binary "Sistema_Seguridad_v8.axf" "Sistema_Seguridad_v8.bin" ; # checksum -p LPC1769 -d "Sistema_Seguridad_v8.bin";
	-@echo ' '

.PHONY: all clean dependents
.SECONDARY: post-build

-include ../makefile.targets
