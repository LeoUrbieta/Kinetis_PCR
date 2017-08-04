################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
C:/Freescale/KDS_v3/eclipse/ProcessorExpert/Repositories/lib/FreeMASTER/FreeMASTER_1_9/src_common/freemaster_appcmd.c \
C:/Freescale/KDS_v3/eclipse/ProcessorExpert/Repositories/lib/FreeMASTER/FreeMASTER_1_9/src_common/freemaster_bdm.c \
C:/Freescale/KDS_v3/eclipse/ProcessorExpert/Repositories/lib/FreeMASTER/FreeMASTER_1_9/src_common/freemaster_can.c \
C:/Freescale/KDS_v3/eclipse/ProcessorExpert/Repositories/lib/FreeMASTER/FreeMASTER_1_9/src_common/freemaster_pipes.c \
C:/Freescale/KDS_v3/eclipse/ProcessorExpert/Repositories/lib/FreeMASTER/FreeMASTER_1_9/src_common/freemaster_protocol.c \
C:/Freescale/KDS_v3/eclipse/ProcessorExpert/Repositories/lib/FreeMASTER/FreeMASTER_1_9/src_common/freemaster_rec.c \
C:/Freescale/KDS_v3/eclipse/ProcessorExpert/Repositories/lib/FreeMASTER/FreeMASTER_1_9/src_common/freemaster_scope.c \
C:/Freescale/KDS_v3/eclipse/ProcessorExpert/Repositories/lib/FreeMASTER/FreeMASTER_1_9/src_common/freemaster_serial.c \
C:/Freescale/KDS_v3/eclipse/ProcessorExpert/Repositories/lib/FreeMASTER/FreeMASTER_1_9/src_common/freemaster_sfio.c \
C:/Freescale/KDS_v3/eclipse/ProcessorExpert/Repositories/lib/FreeMASTER/FreeMASTER_1_9/src_common/freemaster_tsa.c 

OBJS += \
./FreeMASTER/src_common/freemaster_appcmd.o \
./FreeMASTER/src_common/freemaster_bdm.o \
./FreeMASTER/src_common/freemaster_can.o \
./FreeMASTER/src_common/freemaster_pipes.o \
./FreeMASTER/src_common/freemaster_protocol.o \
./FreeMASTER/src_common/freemaster_rec.o \
./FreeMASTER/src_common/freemaster_scope.o \
./FreeMASTER/src_common/freemaster_serial.o \
./FreeMASTER/src_common/freemaster_sfio.o \
./FreeMASTER/src_common/freemaster_tsa.o 

C_DEPS += \
./FreeMASTER/src_common/freemaster_appcmd.d \
./FreeMASTER/src_common/freemaster_bdm.d \
./FreeMASTER/src_common/freemaster_can.d \
./FreeMASTER/src_common/freemaster_pipes.d \
./FreeMASTER/src_common/freemaster_protocol.d \
./FreeMASTER/src_common/freemaster_rec.d \
./FreeMASTER/src_common/freemaster_scope.d \
./FreeMASTER/src_common/freemaster_serial.d \
./FreeMASTER/src_common/freemaster_sfio.d \
./FreeMASTER/src_common/freemaster_tsa.d 


# Each subdirectory must supply rules for building sources it contributes
FreeMASTER/src_common/freemaster_appcmd.o: C:/Freescale/KDS_v3/eclipse/ProcessorExpert/Repositories/lib/FreeMASTER/FreeMASTER_1_9/src_common/freemaster_appcmd.c
	@echo 'Building file: $<'
	@echo 'Invoking: Cross ARM C Compiler'
	arm-none-eabi-gcc -mcpu=cortex-m0plus -mthumb -O0 -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections  -g3 -I"C:/Users/Leonardo/Documents/Kinetis/PCR/Static_Code/System" -I"C:/Users/Leonardo/Documents/Kinetis/PCR/Static_Code/PDD" -I"C:/Users/Leonardo/Documents/Kinetis/PCR/Static_Code/IO_Map" -I"C:\Freescale\KDS_v3\eclipse\ProcessorExpert/lib/Kinetis/pdd/inc" -I"C:/Users/Leonardo/Documents/Kinetis/PCR/Sources" -I"C:/Users/Leonardo/Documents/Kinetis/PCR/Generated_Code" -I"C:\Freescale\FSLESL\CM0_FSLESL_4.2_KDS\MLIB\include" -I"C:\Freescale\FSLESL\CM0_FSLESL_4.2_KDS\PCLIB\include" -I"C:\Freescale\KDS_v3\eclipse\ProcessorExpert/Repositories/lib/FreeMASTER/FreeMASTER_1_9/src_common" -I"C:\Freescale\KDS_v3\eclipse\ProcessorExpert/Repositories/lib/FreeMASTER/FreeMASTER_1_9/src_platforms/Kxx" -I"C:/Users/Leonardo/Documents/Kinetis/PCR/Static_Code/Peripherals" -std=c99 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

FreeMASTER/src_common/freemaster_bdm.o: C:/Freescale/KDS_v3/eclipse/ProcessorExpert/Repositories/lib/FreeMASTER/FreeMASTER_1_9/src_common/freemaster_bdm.c
	@echo 'Building file: $<'
	@echo 'Invoking: Cross ARM C Compiler'
	arm-none-eabi-gcc -mcpu=cortex-m0plus -mthumb -O0 -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections  -g3 -I"C:/Users/Leonardo/Documents/Kinetis/PCR/Static_Code/System" -I"C:/Users/Leonardo/Documents/Kinetis/PCR/Static_Code/PDD" -I"C:/Users/Leonardo/Documents/Kinetis/PCR/Static_Code/IO_Map" -I"C:\Freescale\KDS_v3\eclipse\ProcessorExpert/lib/Kinetis/pdd/inc" -I"C:/Users/Leonardo/Documents/Kinetis/PCR/Sources" -I"C:/Users/Leonardo/Documents/Kinetis/PCR/Generated_Code" -I"C:\Freescale\FSLESL\CM0_FSLESL_4.2_KDS\MLIB\include" -I"C:\Freescale\FSLESL\CM0_FSLESL_4.2_KDS\PCLIB\include" -I"C:\Freescale\KDS_v3\eclipse\ProcessorExpert/Repositories/lib/FreeMASTER/FreeMASTER_1_9/src_common" -I"C:\Freescale\KDS_v3\eclipse\ProcessorExpert/Repositories/lib/FreeMASTER/FreeMASTER_1_9/src_platforms/Kxx" -I"C:/Users/Leonardo/Documents/Kinetis/PCR/Static_Code/Peripherals" -std=c99 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

FreeMASTER/src_common/freemaster_can.o: C:/Freescale/KDS_v3/eclipse/ProcessorExpert/Repositories/lib/FreeMASTER/FreeMASTER_1_9/src_common/freemaster_can.c
	@echo 'Building file: $<'
	@echo 'Invoking: Cross ARM C Compiler'
	arm-none-eabi-gcc -mcpu=cortex-m0plus -mthumb -O0 -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections  -g3 -I"C:/Users/Leonardo/Documents/Kinetis/PCR/Static_Code/System" -I"C:/Users/Leonardo/Documents/Kinetis/PCR/Static_Code/PDD" -I"C:/Users/Leonardo/Documents/Kinetis/PCR/Static_Code/IO_Map" -I"C:\Freescale\KDS_v3\eclipse\ProcessorExpert/lib/Kinetis/pdd/inc" -I"C:/Users/Leonardo/Documents/Kinetis/PCR/Sources" -I"C:/Users/Leonardo/Documents/Kinetis/PCR/Generated_Code" -I"C:\Freescale\FSLESL\CM0_FSLESL_4.2_KDS\MLIB\include" -I"C:\Freescale\FSLESL\CM0_FSLESL_4.2_KDS\PCLIB\include" -I"C:\Freescale\KDS_v3\eclipse\ProcessorExpert/Repositories/lib/FreeMASTER/FreeMASTER_1_9/src_common" -I"C:\Freescale\KDS_v3\eclipse\ProcessorExpert/Repositories/lib/FreeMASTER/FreeMASTER_1_9/src_platforms/Kxx" -I"C:/Users/Leonardo/Documents/Kinetis/PCR/Static_Code/Peripherals" -std=c99 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

FreeMASTER/src_common/freemaster_pipes.o: C:/Freescale/KDS_v3/eclipse/ProcessorExpert/Repositories/lib/FreeMASTER/FreeMASTER_1_9/src_common/freemaster_pipes.c
	@echo 'Building file: $<'
	@echo 'Invoking: Cross ARM C Compiler'
	arm-none-eabi-gcc -mcpu=cortex-m0plus -mthumb -O0 -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections  -g3 -I"C:/Users/Leonardo/Documents/Kinetis/PCR/Static_Code/System" -I"C:/Users/Leonardo/Documents/Kinetis/PCR/Static_Code/PDD" -I"C:/Users/Leonardo/Documents/Kinetis/PCR/Static_Code/IO_Map" -I"C:\Freescale\KDS_v3\eclipse\ProcessorExpert/lib/Kinetis/pdd/inc" -I"C:/Users/Leonardo/Documents/Kinetis/PCR/Sources" -I"C:/Users/Leonardo/Documents/Kinetis/PCR/Generated_Code" -I"C:\Freescale\FSLESL\CM0_FSLESL_4.2_KDS\MLIB\include" -I"C:\Freescale\FSLESL\CM0_FSLESL_4.2_KDS\PCLIB\include" -I"C:\Freescale\KDS_v3\eclipse\ProcessorExpert/Repositories/lib/FreeMASTER/FreeMASTER_1_9/src_common" -I"C:\Freescale\KDS_v3\eclipse\ProcessorExpert/Repositories/lib/FreeMASTER/FreeMASTER_1_9/src_platforms/Kxx" -I"C:/Users/Leonardo/Documents/Kinetis/PCR/Static_Code/Peripherals" -std=c99 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

FreeMASTER/src_common/freemaster_protocol.o: C:/Freescale/KDS_v3/eclipse/ProcessorExpert/Repositories/lib/FreeMASTER/FreeMASTER_1_9/src_common/freemaster_protocol.c
	@echo 'Building file: $<'
	@echo 'Invoking: Cross ARM C Compiler'
	arm-none-eabi-gcc -mcpu=cortex-m0plus -mthumb -O0 -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections  -g3 -I"C:/Users/Leonardo/Documents/Kinetis/PCR/Static_Code/System" -I"C:/Users/Leonardo/Documents/Kinetis/PCR/Static_Code/PDD" -I"C:/Users/Leonardo/Documents/Kinetis/PCR/Static_Code/IO_Map" -I"C:\Freescale\KDS_v3\eclipse\ProcessorExpert/lib/Kinetis/pdd/inc" -I"C:/Users/Leonardo/Documents/Kinetis/PCR/Sources" -I"C:/Users/Leonardo/Documents/Kinetis/PCR/Generated_Code" -I"C:\Freescale\FSLESL\CM0_FSLESL_4.2_KDS\MLIB\include" -I"C:\Freescale\FSLESL\CM0_FSLESL_4.2_KDS\PCLIB\include" -I"C:\Freescale\KDS_v3\eclipse\ProcessorExpert/Repositories/lib/FreeMASTER/FreeMASTER_1_9/src_common" -I"C:\Freescale\KDS_v3\eclipse\ProcessorExpert/Repositories/lib/FreeMASTER/FreeMASTER_1_9/src_platforms/Kxx" -I"C:/Users/Leonardo/Documents/Kinetis/PCR/Static_Code/Peripherals" -std=c99 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

FreeMASTER/src_common/freemaster_rec.o: C:/Freescale/KDS_v3/eclipse/ProcessorExpert/Repositories/lib/FreeMASTER/FreeMASTER_1_9/src_common/freemaster_rec.c
	@echo 'Building file: $<'
	@echo 'Invoking: Cross ARM C Compiler'
	arm-none-eabi-gcc -mcpu=cortex-m0plus -mthumb -O0 -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections  -g3 -I"C:/Users/Leonardo/Documents/Kinetis/PCR/Static_Code/System" -I"C:/Users/Leonardo/Documents/Kinetis/PCR/Static_Code/PDD" -I"C:/Users/Leonardo/Documents/Kinetis/PCR/Static_Code/IO_Map" -I"C:\Freescale\KDS_v3\eclipse\ProcessorExpert/lib/Kinetis/pdd/inc" -I"C:/Users/Leonardo/Documents/Kinetis/PCR/Sources" -I"C:/Users/Leonardo/Documents/Kinetis/PCR/Generated_Code" -I"C:\Freescale\FSLESL\CM0_FSLESL_4.2_KDS\MLIB\include" -I"C:\Freescale\FSLESL\CM0_FSLESL_4.2_KDS\PCLIB\include" -I"C:\Freescale\KDS_v3\eclipse\ProcessorExpert/Repositories/lib/FreeMASTER/FreeMASTER_1_9/src_common" -I"C:\Freescale\KDS_v3\eclipse\ProcessorExpert/Repositories/lib/FreeMASTER/FreeMASTER_1_9/src_platforms/Kxx" -I"C:/Users/Leonardo/Documents/Kinetis/PCR/Static_Code/Peripherals" -std=c99 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

FreeMASTER/src_common/freemaster_scope.o: C:/Freescale/KDS_v3/eclipse/ProcessorExpert/Repositories/lib/FreeMASTER/FreeMASTER_1_9/src_common/freemaster_scope.c
	@echo 'Building file: $<'
	@echo 'Invoking: Cross ARM C Compiler'
	arm-none-eabi-gcc -mcpu=cortex-m0plus -mthumb -O0 -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections  -g3 -I"C:/Users/Leonardo/Documents/Kinetis/PCR/Static_Code/System" -I"C:/Users/Leonardo/Documents/Kinetis/PCR/Static_Code/PDD" -I"C:/Users/Leonardo/Documents/Kinetis/PCR/Static_Code/IO_Map" -I"C:\Freescale\KDS_v3\eclipse\ProcessorExpert/lib/Kinetis/pdd/inc" -I"C:/Users/Leonardo/Documents/Kinetis/PCR/Sources" -I"C:/Users/Leonardo/Documents/Kinetis/PCR/Generated_Code" -I"C:\Freescale\FSLESL\CM0_FSLESL_4.2_KDS\MLIB\include" -I"C:\Freescale\FSLESL\CM0_FSLESL_4.2_KDS\PCLIB\include" -I"C:\Freescale\KDS_v3\eclipse\ProcessorExpert/Repositories/lib/FreeMASTER/FreeMASTER_1_9/src_common" -I"C:\Freescale\KDS_v3\eclipse\ProcessorExpert/Repositories/lib/FreeMASTER/FreeMASTER_1_9/src_platforms/Kxx" -I"C:/Users/Leonardo/Documents/Kinetis/PCR/Static_Code/Peripherals" -std=c99 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

FreeMASTER/src_common/freemaster_serial.o: C:/Freescale/KDS_v3/eclipse/ProcessorExpert/Repositories/lib/FreeMASTER/FreeMASTER_1_9/src_common/freemaster_serial.c
	@echo 'Building file: $<'
	@echo 'Invoking: Cross ARM C Compiler'
	arm-none-eabi-gcc -mcpu=cortex-m0plus -mthumb -O0 -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections  -g3 -I"C:/Users/Leonardo/Documents/Kinetis/PCR/Static_Code/System" -I"C:/Users/Leonardo/Documents/Kinetis/PCR/Static_Code/PDD" -I"C:/Users/Leonardo/Documents/Kinetis/PCR/Static_Code/IO_Map" -I"C:\Freescale\KDS_v3\eclipse\ProcessorExpert/lib/Kinetis/pdd/inc" -I"C:/Users/Leonardo/Documents/Kinetis/PCR/Sources" -I"C:/Users/Leonardo/Documents/Kinetis/PCR/Generated_Code" -I"C:\Freescale\FSLESL\CM0_FSLESL_4.2_KDS\MLIB\include" -I"C:\Freescale\FSLESL\CM0_FSLESL_4.2_KDS\PCLIB\include" -I"C:\Freescale\KDS_v3\eclipse\ProcessorExpert/Repositories/lib/FreeMASTER/FreeMASTER_1_9/src_common" -I"C:\Freescale\KDS_v3\eclipse\ProcessorExpert/Repositories/lib/FreeMASTER/FreeMASTER_1_9/src_platforms/Kxx" -I"C:/Users/Leonardo/Documents/Kinetis/PCR/Static_Code/Peripherals" -std=c99 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

FreeMASTER/src_common/freemaster_sfio.o: C:/Freescale/KDS_v3/eclipse/ProcessorExpert/Repositories/lib/FreeMASTER/FreeMASTER_1_9/src_common/freemaster_sfio.c
	@echo 'Building file: $<'
	@echo 'Invoking: Cross ARM C Compiler'
	arm-none-eabi-gcc -mcpu=cortex-m0plus -mthumb -O0 -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections  -g3 -I"C:/Users/Leonardo/Documents/Kinetis/PCR/Static_Code/System" -I"C:/Users/Leonardo/Documents/Kinetis/PCR/Static_Code/PDD" -I"C:/Users/Leonardo/Documents/Kinetis/PCR/Static_Code/IO_Map" -I"C:\Freescale\KDS_v3\eclipse\ProcessorExpert/lib/Kinetis/pdd/inc" -I"C:/Users/Leonardo/Documents/Kinetis/PCR/Sources" -I"C:/Users/Leonardo/Documents/Kinetis/PCR/Generated_Code" -I"C:\Freescale\FSLESL\CM0_FSLESL_4.2_KDS\MLIB\include" -I"C:\Freescale\FSLESL\CM0_FSLESL_4.2_KDS\PCLIB\include" -I"C:\Freescale\KDS_v3\eclipse\ProcessorExpert/Repositories/lib/FreeMASTER/FreeMASTER_1_9/src_common" -I"C:\Freescale\KDS_v3\eclipse\ProcessorExpert/Repositories/lib/FreeMASTER/FreeMASTER_1_9/src_platforms/Kxx" -I"C:/Users/Leonardo/Documents/Kinetis/PCR/Static_Code/Peripherals" -std=c99 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

FreeMASTER/src_common/freemaster_tsa.o: C:/Freescale/KDS_v3/eclipse/ProcessorExpert/Repositories/lib/FreeMASTER/FreeMASTER_1_9/src_common/freemaster_tsa.c
	@echo 'Building file: $<'
	@echo 'Invoking: Cross ARM C Compiler'
	arm-none-eabi-gcc -mcpu=cortex-m0plus -mthumb -O0 -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections  -g3 -I"C:/Users/Leonardo/Documents/Kinetis/PCR/Static_Code/System" -I"C:/Users/Leonardo/Documents/Kinetis/PCR/Static_Code/PDD" -I"C:/Users/Leonardo/Documents/Kinetis/PCR/Static_Code/IO_Map" -I"C:\Freescale\KDS_v3\eclipse\ProcessorExpert/lib/Kinetis/pdd/inc" -I"C:/Users/Leonardo/Documents/Kinetis/PCR/Sources" -I"C:/Users/Leonardo/Documents/Kinetis/PCR/Generated_Code" -I"C:\Freescale\FSLESL\CM0_FSLESL_4.2_KDS\MLIB\include" -I"C:\Freescale\FSLESL\CM0_FSLESL_4.2_KDS\PCLIB\include" -I"C:\Freescale\KDS_v3\eclipse\ProcessorExpert/Repositories/lib/FreeMASTER/FreeMASTER_1_9/src_common" -I"C:\Freescale\KDS_v3\eclipse\ProcessorExpert/Repositories/lib/FreeMASTER/FreeMASTER_1_9/src_platforms/Kxx" -I"C:/Users/Leonardo/Documents/Kinetis/PCR/Static_Code/Peripherals" -std=c99 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


