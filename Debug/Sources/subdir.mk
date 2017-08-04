################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Sources/Events.c \
../Sources/main.c 

OBJS += \
./Sources/Events.o \
./Sources/main.o 

C_DEPS += \
./Sources/Events.d \
./Sources/main.d 


# Each subdirectory must supply rules for building sources it contributes
Sources/%.o: ../Sources/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: Cross ARM C Compiler'
	arm-none-eabi-gcc -mcpu=cortex-m0plus -mthumb -O0 -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections  -g3 -I"C:/Users/Leonardo/Documents/Kinetis/PCR_Final/Static_Code/System" -I"C:/Users/Leonardo/Documents/Kinetis/PCR_Final/Static_Code/PDD" -I"C:/Users/Leonardo/Documents/Kinetis/PCR_Final/Static_Code/IO_Map" -I"C:\Freescale\KDS_v3\eclipse\ProcessorExpert/lib/Kinetis/pdd/inc" -I"C:/Users/Leonardo/Documents/Kinetis/PCR_Final/Sources" -I"C:/Users/Leonardo/Documents/Kinetis/PCR_Final/Generated_Code" -I"C:\Freescale\FSLESL\CM0_FSLESL_4.2_KDS\MLIB\include" -I"C:\Freescale\FSLESL\CM0_FSLESL_4.2_KDS\PCLIB\include" -I"C:/Users/Leonardo/Documents/Kinetis/PCR_Final/Static_Code/Peripherals" -std=c99 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


