################################################################################
# Automatically-generated file. Do not edit!
################################################################################

EMPTY := 
SPACE := $(EMPTY) $(EMPTY)

ORDERED_OBJS += \
$(GEN_CMDS_QUOTED) \
"./6747/C6747_init.obj" \
"./6747/C6747.obj" \
"./elf/elf_loader.obj" \
"./nand/nand_test.obj" \
"./nand/nand.obj" \
"./sci/uart.obj" \
"./sci/C6747_uart.obj" \
"./source/main.obj" \
"./source/data.obj" \
"../CMD/linker.cmd" \

-include ../makefile.init

RM := DEL /F

# All of the sources participating in the build are defined here
-include sources.mk
-include subdir.mk
-include source/subdir.mk
-include sci/subdir.mk
-include nand/subdir.mk
-include elf/subdir.mk
-include CMD/subdir.mk
-include 6747/subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(S62_DEPS)),)
-include $(S62_DEPS)
endif
ifneq ($(strip $(ASM_DEPS)),)
-include $(ASM_DEPS)
endif
ifneq ($(strip $(C55_DEPS)),)
-include $(C55_DEPS)
endif
ifneq ($(strip $(S_UPPER_DEPS)),)
-include $(S_UPPER_DEPS)
endif
ifneq ($(strip $(C++_DEPS)),)
-include $(C++_DEPS)
endif
ifneq ($(strip $(S_DEPS)),)
-include $(S_DEPS)
endif
ifneq ($(strip $(CC_DEPS)),)
-include $(CC_DEPS)
endif
ifneq ($(strip $(C64_DEPS)),)
-include $(C64_DEPS)
endif
ifneq ($(strip $(CPP_DEPS)),)
-include $(CPP_DEPS)
endif
ifneq ($(strip $(S64_DEPS)),)
-include $(S64_DEPS)
endif
ifneq ($(strip $(CXX_DEPS)),)
-include $(CXX_DEPS)
endif
ifneq ($(strip $(C67_DEPS)),)
-include $(C67_DEPS)
endif
ifneq ($(strip $(S67_DEPS)),)
-include $(S67_DEPS)
endif
ifneq ($(strip $(S43_DEPS)),)
-include $(S43_DEPS)
endif
ifneq ($(strip $(C62_DEPS)),)
-include $(C62_DEPS)
endif
ifneq ($(strip $(C43_DEPS)),)
-include $(C43_DEPS)
endif
ifneq ($(strip $(C??_DEPS)),)
-include $(C??_DEPS)
endif
ifneq ($(strip $(ASM_UPPER_DEPS)),)
-include $(ASM_UPPER_DEPS)
endif
ifneq ($(strip $(OPT_DEPS)),)
-include $(OPT_DEPS)
endif
ifneq ($(strip $(S??_DEPS)),)
-include $(S??_DEPS)
endif
ifneq ($(strip $(S55_DEPS)),)
-include $(S55_DEPS)
endif
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
ifneq ($(strip $(SA_DEPS)),)
-include $(SA_DEPS)
endif
ifneq ($(strip $(C_UPPER_DEPS)),)
-include $(C_UPPER_DEPS)
endif
endif

-include ../makefile.defs

# Add inputs and outputs from these tool invocations to the build variables 

# All Target
all: bootload.out

# Tool invocations
bootload.out: $(GEN_CMDS) $(OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: Linker'
	"D:/Program Files/Texas Instruments/ccsv4/tools/compiler/c6000/bin/cl6x" -g --diag_warning=225 -z -m"bootload.map" --warn_sections -i"D:/Program Files/Texas Instruments/ccsv4/tools/compiler/c6000/lib" -i"D:/Program Files/Texas Instruments/ccsv4/tools/compiler/c6000/include" --reread_libs --rom_model -o "bootload.out" $(ORDERED_OBJS)
	@echo 'Finished building target: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(C6000_EXECUTABLE_OUTPUTS__QTD) "bootload.out"
	-$(RM) ".\source\data.obj" ".\source\main.obj" ".\sci\C6747_uart.obj" ".\sci\uart.obj" ".\nand\nand.obj" ".\nand\nand_test.obj" ".\elf\elf_loader.obj" ".\6747\C6747.obj" ".\6747\C6747_init.obj" 
	-$(RM) ".\source\data.pp" ".\source\main.pp" ".\sci\C6747_uart.pp" ".\sci\uart.pp" ".\nand\nand.pp" ".\nand\nand_test.pp" ".\elf\elf_loader.pp" ".\6747\C6747.pp" ".\6747\C6747_init.pp" 
	-@echo ' '

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets
