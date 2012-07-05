################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../source/data.c \
../source/main.c 

OBJS += \
./source/data.obj \
./source/main.obj 

C_DEPS += \
./source/data.pp \
./source/main.pp 

OBJS__QTD += \
".\source\data.obj" \
".\source\main.obj" 

C_DEPS__QTD += \
".\source\data.pp" \
".\source\main.pp" 

C_SRCS_QUOTED += \
"../source/data.c" \
"../source/main.c" 


# Each subdirectory must supply rules for building sources it contributes
source/data.obj: ../source/data.c $(GEN_OPTS)
	@echo 'Building file: $<'
	@echo 'Invoking: Compiler'
	"D:/Program Files/Texas Instruments/ccsv4/tools/compiler/c6000/bin/cl6x" -g --include_path="D:/Program Files/Texas Instruments/ccsv4/tools/compiler/c6000/include" --include_path="F:/TI-6474/workspace/bootload/elf" --include_path="F:/TI-6474/workspace/bootload/elf" --include_path="F:/TI-6474/workspace/bootload/nand" --include_path="F:/TI-6474/workspace/bootload/sci" --include_path="F:/TI-6474/workspace/bootload/include" --diag_warning=225 --preproc_with_compile --preproc_dependency="source/data.pp" --obj_directory="source" $(GEN_OPTS_QUOTED) $(subst #,$(wildcard $(subst $(SPACE),\$(SPACE),$<)),"#")
	@echo 'Finished building: $<'
	@echo ' '

source/main.obj: ../source/main.c $(GEN_OPTS)
	@echo 'Building file: $<'
	@echo 'Invoking: Compiler'
	"D:/Program Files/Texas Instruments/ccsv4/tools/compiler/c6000/bin/cl6x" -g --include_path="D:/Program Files/Texas Instruments/ccsv4/tools/compiler/c6000/include" --include_path="F:/TI-6474/workspace/bootload/elf" --include_path="F:/TI-6474/workspace/bootload/elf" --include_path="F:/TI-6474/workspace/bootload/nand" --include_path="F:/TI-6474/workspace/bootload/sci" --include_path="F:/TI-6474/workspace/bootload/include" --diag_warning=225 --preproc_with_compile --preproc_dependency="source/main.pp" --obj_directory="source" $(GEN_OPTS_QUOTED) $(subst #,$(wildcard $(subst $(SPACE),\$(SPACE),$<)),"#")
	@echo 'Finished building: $<'
	@echo ' '


