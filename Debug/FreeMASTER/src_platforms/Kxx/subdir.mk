################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
C:/Freescale/KDS_v3/eclipse/ProcessorExpert/Repositories/lib/FreeMASTER/FreeMASTER_1_9/src_platforms/Kxx/freemaster_Kxx.c 

OBJS += \
./FreeMASTER/src_platforms/Kxx/freemaster_Kxx.o 

C_DEPS += \
./FreeMASTER/src_platforms/Kxx/freemaster_Kxx.d 


# Each subdirectory must supply rules for building sources it contributes
FreeMASTER/src_platforms/Kxx/freemaster_Kxx.o: C:/Freescale/KDS_v3/eclipse/ProcessorExpert/Repositories/lib/FreeMASTER/FreeMASTER_1_9/src_platforms/Kxx/freemaster_Kxx.c
	@echo 'Building file: $<'
	@echo 'Invoking: Cross ARM C Compiler'
	arm-none-eabi-gcc -mcpu=cortex-m0plus -mthumb -O0 -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections  -g3 -I"C:/Users/Leonardo/Documents/Kinetis/PCR/Static_Code/System" -I"C:/Users/Leonardo/Documents/Kinetis/PCR/Static_Code/PDD" -I"C:/Users/Leonardo/Documents/Kinetis/PCR/Static_Code/IO_Map" -I"C:\Freescale\KDS_v3\eclipse\ProcessorExpert/lib/Kinetis/pdd/inc" -I"C:/Users/Leonardo/Documents/Kinetis/PCR/Sources" -I"C:/Users/Leonardo/Documents/Kinetis/PCR/Generated_Code" -I"C:\Freescale\FSLESL\CM0_FSLESL_4.2_KDS\MLIB\include" -I"C:\Freescale\FSLESL\CM0_FSLESL_4.2_KDS\PCLIB\include" -I"C:\Freescale\KDS_v3\eclipse\ProcessorExpert/Repositories/lib/FreeMASTER/FreeMASTER_1_9/src_common" -I"C:\Freescale\KDS_v3\eclipse\ProcessorExpert/Repositories/lib/FreeMASTER/FreeMASTER_1_9/src_platforms/Kxx" -I"C:/Users/Leonardo/Documents/Kinetis/PCR/Static_Code/Peripherals" -std=c99 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


