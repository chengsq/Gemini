################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../6747/C6747.c \
../6747/C6747_init.c 

OBJS += \
./6747/C6747.obj \
./6747/C6747_init.obj 

C_DEPS += \
./6747/C6747.pp \
./6747/C6747_init.pp 

OBJS__QTD += \
".\6747\C6747.obj" \
".\6747\C6747_init.obj" 

C_DEPS__QTD += \
".\6747\C6747.pp" \
".\6747\C6747_init.pp" 

C_SRCS_QUOTED += \
"../6747/C6747.c" \
"../6747/C6747_init.c" 


# Each subdirectory must supply rules for building sources it contributes
6747/C6747.obj: ../6747/C6747.c $(GEN_OPTS)
	@echo 'Building file: $<'
	@echo 'Invoking: Compiler'
	"D:/Program Files/Texas Instruments/ccsv4/tools/compiler/c6000/bin/cl6x" -g --include_path="D:/Program Files/Texas Instruments/ccsv4/tools/compiler/c6000/include" --include_path="F:/TI-6474/workspace/bootload/elf" --include_path="F:/TI-6474/workspace/bootload/elf" --include_path="F:/TI-6474/workspace/bootload/nand" --include_path="F:/TI-6474/workspace/bootload/sci" --include_path="F:/TI-6474/workspace/bootload/include" --diag_warning=225 --preproc_with_compile --preproc_dependency="6747/C6747.pp" --obj_directory="6747" $(GEN_OPTS_QUOTED) $(subst #,$(wildcard $(subst $(SPACE),\$(SPACE),$<)),"#")
	@echo 'Finished building: $<'
	@echo ' '

6747/C6747_init.obj: ../6747/C6747_init.c $(GEN_OPTS)
	@echo 'Building file: $<'
	@echo 'Invoking: Compiler'
	"D:/Program Files/Texas Instruments/ccsv4/tools/compiler/c6000/bin/cl6x" -g --include_path="D:/Program Files/Texas Instruments/ccsv4/tools/compiler/c6000/include" --include_path="F:/TI-6474/workspace/bootload/elf" --include_path="F:/TI-6474/workspace/bootload/elf" --include_path="F:/TI-6474/workspace/bootload/nand" --include_path="F:/TI-6474/workspace/bootload/sci" --include_path="F:/TI-6474/workspace/bootload/include" --diag_warning=225 --preproc_with_compile --preproc_dependency="6747/C6747_init.pp" --obj_directory="6747" $(GEN_OPTS_QUOTED) $(subst #,$(wildcard $(subst $(SPACE),\$(SPACE),$<)),"#")
	@echo 'Finished building: $<'
	@echo ' '


