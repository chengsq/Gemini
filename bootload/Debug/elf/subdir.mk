################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../elf/elf_loader.c 

OBJS += \
./elf/elf_loader.obj 

C_DEPS += \
./elf/elf_loader.pp 

OBJS__QTD += \
".\elf\elf_loader.obj" 

C_DEPS__QTD += \
".\elf\elf_loader.pp" 

C_SRCS_QUOTED += \
"../elf/elf_loader.c" 


# Each subdirectory must supply rules for building sources it contributes
elf/elf_loader.obj: ../elf/elf_loader.c $(GEN_OPTS)
	@echo 'Building file: $<'
	@echo 'Invoking: Compiler'
	"D:/Program Files/Texas Instruments/ccsv4/tools/compiler/c6000/bin/cl6x" -g --include_path="D:/Program Files/Texas Instruments/ccsv4/tools/compiler/c6000/include" --include_path="F:/TI-6474/workspace/bootload/elf" --include_path="F:/TI-6474/workspace/bootload/elf" --include_path="F:/TI-6474/workspace/bootload/nand" --include_path="F:/TI-6474/workspace/bootload/sci" --include_path="F:/TI-6474/workspace/bootload/include" --diag_warning=225 --preproc_with_compile --preproc_dependency="elf/elf_loader.pp" --obj_directory="elf" $(GEN_OPTS_QUOTED) $(subst #,$(wildcard $(subst $(SPACE),\$(SPACE),$<)),"#")
	@echo 'Finished building: $<'
	@echo ' '


