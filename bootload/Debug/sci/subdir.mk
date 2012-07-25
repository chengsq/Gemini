################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../sci/C6747_uart.c \
../sci/uart.c 

OBJS += \
./sci/C6747_uart.obj \
./sci/uart.obj 

C_DEPS += \
./sci/C6747_uart.pp \
./sci/uart.pp 

OBJS__QTD += \
".\sci\C6747_uart.obj" \
".\sci\uart.obj" 

C_DEPS__QTD += \
".\sci\C6747_uart.pp" \
".\sci\uart.pp" 

C_SRCS_QUOTED += \
"../sci/C6747_uart.c" \
"../sci/uart.c" 


# Each subdirectory must supply rules for building sources it contributes
sci/C6747_uart.obj: ../sci/C6747_uart.c $(GEN_OPTS)
	@echo 'Building file: $<'
	@echo 'Invoking: Compiler'
	"D:/Program Files/Texas Instruments/ccsv4/tools/compiler/c6000/bin/cl6x" -g --include_path="D:/Program Files/Texas Instruments/ccsv4/tools/compiler/c6000/include" --include_path="F:/TI-6474/workspace/TI6747_BootLoader_V1.0_CSS4.0/bootload/elf" --include_path="F:/TI-6474/workspace/TI6747_BootLoader_V1.0_CSS4.0/bootload/elf" --include_path="F:/TI-6474/workspace/TI6747_BootLoader_V1.0_CSS4.0/bootload/nand" --include_path="F:/TI-6474/workspace/TI6747_BootLoader_V1.0_CSS4.0/bootload/sci" --include_path="F:/TI-6474/workspace/TI6747_BootLoader_V1.0_CSS4.0/bootload/include" --diag_warning=225 --preproc_with_compile --preproc_dependency="sci/C6747_uart.pp" --obj_directory="sci" $(GEN_OPTS_QUOTED) $(subst #,$(wildcard $(subst $(SPACE),\$(SPACE),$<)),"#")
	@echo 'Finished building: $<'
	@echo ' '

sci/uart.obj: ../sci/uart.c $(GEN_OPTS)
	@echo 'Building file: $<'
	@echo 'Invoking: Compiler'
	"D:/Program Files/Texas Instruments/ccsv4/tools/compiler/c6000/bin/cl6x" -g --include_path="D:/Program Files/Texas Instruments/ccsv4/tools/compiler/c6000/include" --include_path="F:/TI-6474/workspace/TI6747_BootLoader_V1.0_CSS4.0/bootload/elf" --include_path="F:/TI-6474/workspace/TI6747_BootLoader_V1.0_CSS4.0/bootload/elf" --include_path="F:/TI-6474/workspace/TI6747_BootLoader_V1.0_CSS4.0/bootload/nand" --include_path="F:/TI-6474/workspace/TI6747_BootLoader_V1.0_CSS4.0/bootload/sci" --include_path="F:/TI-6474/workspace/TI6747_BootLoader_V1.0_CSS4.0/bootload/include" --diag_warning=225 --preproc_with_compile --preproc_dependency="sci/uart.pp" --obj_directory="sci" $(GEN_OPTS_QUOTED) $(subst #,$(wildcard $(subst $(SPACE),\$(SPACE),$<)),"#")
	@echo 'Finished building: $<'
	@echo ' '


