################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../source/boot.c \
../source/data.c \
../source/main.c 

OBJS += \
./source/boot.obj \
./source/data.obj \
./source/main.obj 

C_DEPS += \
./source/boot.pp \
./source/data.pp \
./source/main.pp 

OBJS__QTD += \
".\source\boot.obj" \
".\source\data.obj" \
".\source\main.obj" 

C_DEPS__QTD += \
".\source\boot.pp" \
".\source\data.pp" \
".\source\main.pp" 

C_SRCS_QUOTED += \
"../source/boot.c" \
"../source/data.c" \
"../source/main.c" 


# Each subdirectory must supply rules for building sources it contributes
source/boot.obj: ../source/boot.c $(GEN_OPTS)
	@echo 'Building file: $<'
	@echo 'Invoking: Compiler'
	"D:/Program Files/Texas Instruments/ccsv4/tools/compiler/c6000/bin/cl6x" -g --include_path="D:/Program Files/Texas Instruments/ccsv4/tools/compiler/c6000/include" --include_path="F:/TI-6474/workspace/TI6747_BootLoader_V1.0_CSS4.0/bootload/elf" --include_path="F:/TI-6474/workspace/TI6747_BootLoader_V1.0_CSS4.0/bootload/elf" --include_path="F:/TI-6474/workspace/TI6747_BootLoader_V1.0_CSS4.0/bootload/nand" --include_path="F:/TI-6474/workspace/TI6747_BootLoader_V1.0_CSS4.0/bootload/sci" --include_path="F:/TI-6474/workspace/TI6747_BootLoader_V1.0_CSS4.0/bootload/include" --diag_warning=225 --preproc_with_compile --preproc_dependency="source/boot.pp" --obj_directory="source" $(GEN_OPTS_QUOTED) $(subst #,$(wildcard $(subst $(SPACE),\$(SPACE),$<)),"#")
	@echo 'Finished building: $<'
	@echo ' '

source/data.obj: ../source/data.c $(GEN_OPTS)
	@echo 'Building file: $<'
	@echo 'Invoking: Compiler'
	"D:/Program Files/Texas Instruments/ccsv4/tools/compiler/c6000/bin/cl6x" -g --include_path="D:/Program Files/Texas Instruments/ccsv4/tools/compiler/c6000/include" --include_path="F:/TI-6474/workspace/TI6747_BootLoader_V1.0_CSS4.0/bootload/elf" --include_path="F:/TI-6474/workspace/TI6747_BootLoader_V1.0_CSS4.0/bootload/elf" --include_path="F:/TI-6474/workspace/TI6747_BootLoader_V1.0_CSS4.0/bootload/nand" --include_path="F:/TI-6474/workspace/TI6747_BootLoader_V1.0_CSS4.0/bootload/sci" --include_path="F:/TI-6474/workspace/TI6747_BootLoader_V1.0_CSS4.0/bootload/include" --diag_warning=225 --preproc_with_compile --preproc_dependency="source/data.pp" --obj_directory="source" $(GEN_OPTS_QUOTED) $(subst #,$(wildcard $(subst $(SPACE),\$(SPACE),$<)),"#")
	@echo 'Finished building: $<'
	@echo ' '

source/main.obj: ../source/main.c $(GEN_OPTS)
	@echo 'Building file: $<'
	@echo 'Invoking: Compiler'
	"D:/Program Files/Texas Instruments/ccsv4/tools/compiler/c6000/bin/cl6x" -g --include_path="D:/Program Files/Texas Instruments/ccsv4/tools/compiler/c6000/include" --include_path="F:/TI-6474/workspace/TI6747_BootLoader_V1.0_CSS4.0/bootload/elf" --include_path="F:/TI-6474/workspace/TI6747_BootLoader_V1.0_CSS4.0/bootload/elf" --include_path="F:/TI-6474/workspace/TI6747_BootLoader_V1.0_CSS4.0/bootload/nand" --include_path="F:/TI-6474/workspace/TI6747_BootLoader_V1.0_CSS4.0/bootload/sci" --include_path="F:/TI-6474/workspace/TI6747_BootLoader_V1.0_CSS4.0/bootload/include" --diag_warning=225 --preproc_with_compile --preproc_dependency="source/main.pp" --obj_directory="source" $(GEN_OPTS_QUOTED) $(subst #,$(wildcard $(subst $(SPACE),\$(SPACE),$<)),"#")
	@echo 'Finished building: $<'
	@echo ' '


