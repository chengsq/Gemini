################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../nand/nand.c \
../nand/nand_test.c 

OBJS += \
./nand/nand.obj \
./nand/nand_test.obj 

C_DEPS += \
./nand/nand.pp \
./nand/nand_test.pp 

OBJS__QTD += \
".\nand\nand.obj" \
".\nand\nand_test.obj" 

C_DEPS__QTD += \
".\nand\nand.pp" \
".\nand\nand_test.pp" 

C_SRCS_QUOTED += \
"../nand/nand.c" \
"../nand/nand_test.c" 


# Each subdirectory must supply rules for building sources it contributes
nand/nand.obj: ../nand/nand.c $(GEN_OPTS)
	@echo 'Building file: $<'
	@echo 'Invoking: Compiler'
	"D:/Program Files/Texas Instruments/ccsv4/tools/compiler/c6000/bin/cl6x" -g --include_path="D:/Program Files/Texas Instruments/ccsv4/tools/compiler/c6000/include" --include_path="F:/TI-6474/workspace/bootload/elf" --include_path="F:/TI-6474/workspace/bootload/elf" --include_path="F:/TI-6474/workspace/bootload/nand" --include_path="F:/TI-6474/workspace/bootload/sci" --include_path="F:/TI-6474/workspace/bootload/include" --diag_warning=225 --preproc_with_compile --preproc_dependency="nand/nand.pp" --obj_directory="nand" $(GEN_OPTS_QUOTED) $(subst #,$(wildcard $(subst $(SPACE),\$(SPACE),$<)),"#")
	@echo 'Finished building: $<'
	@echo ' '

nand/nand_test.obj: ../nand/nand_test.c $(GEN_OPTS)
	@echo 'Building file: $<'
	@echo 'Invoking: Compiler'
	"D:/Program Files/Texas Instruments/ccsv4/tools/compiler/c6000/bin/cl6x" -g --include_path="D:/Program Files/Texas Instruments/ccsv4/tools/compiler/c6000/include" --include_path="F:/TI-6474/workspace/bootload/elf" --include_path="F:/TI-6474/workspace/bootload/elf" --include_path="F:/TI-6474/workspace/bootload/nand" --include_path="F:/TI-6474/workspace/bootload/sci" --include_path="F:/TI-6474/workspace/bootload/include" --diag_warning=225 --preproc_with_compile --preproc_dependency="nand/nand_test.pp" --obj_directory="nand" $(GEN_OPTS_QUOTED) $(subst #,$(wildcard $(subst $(SPACE),\$(SPACE),$<)),"#")
	@echo 'Finished building: $<'
	@echo ' '


