################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include MCAL/DIO/subdir.mk
-include HAL/LCD/subdir.mk
-include HAL/Keypad/subdir.mk
-include APP/subdir.mk
-include subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(ASM_DEPS)),)
-include $(ASM_DEPS)
endif
ifneq ($(strip $(S_DEPS)),)
-include $(S_DEPS)
endif
ifneq ($(strip $(S_UPPER_DEPS)),)
-include $(S_UPPER_DEPS)
endif
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
endif

-include ../makefile.defs

# Add inputs and outputs from these tool invocations to the build variables 
LSS += \
Calc_Done.lss \

FLASH_IMAGE += \
Calc_Done.hex \

SIZEDUMMY += \
sizedummy \


# All Target
all: Calc_Done.elf secondary-outputs

# Tool invocations
Calc_Done.elf: $(OBJS) $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: AVR C Linker'
	avr-gcc -Wl,-Map,Calc_Done.map -mmcu=atmega32 -o "Calc_Done.elf" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '

Calc_Done.lss: Calc_Done.elf
	@echo 'Invoking: AVR Create Extended Listing'
	-avr-objdump -h -S Calc_Done.elf  >"Calc_Done.lss"
	@echo 'Finished building: $@'
	@echo ' '

Calc_Done.hex: Calc_Done.elf
	@echo 'Create Flash image (ihex format)'
	-avr-objcopy -R .eeprom -R .fuse -R .lock -R .signature -O ihex Calc_Done.elf  "Calc_Done.hex"
	@echo 'Finished building: $@'
	@echo ' '

sizedummy: Calc_Done.elf
	@echo 'Invoking: Print Size'
	-avr-size --format=avr --mcu=atmega32 Calc_Done.elf
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(FLASH_IMAGE)$(ELFS)$(OBJS)$(ASM_DEPS)$(S_DEPS)$(SIZEDUMMY)$(S_UPPER_DEPS)$(LSS)$(C_DEPS) Calc_Done.elf
	-@echo ' '

secondary-outputs: $(LSS) $(FLASH_IMAGE) $(SIZEDUMMY)

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets
