################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Generated_Code/AD1.c \
../Generated_Code/ASerialLdd1.c \
../Generated_Code/BitIoLdd3.c \
../Generated_Code/BitIoLdd4.c \
../Generated_Code/BitIoLdd5.c \
../Generated_Code/BitIoLdd6.c \
../Generated_Code/BitIoLdd7.c \
../Generated_Code/COLDPWM.c \
../Generated_Code/Clock.c \
../Generated_Code/Cpu.c \
../Generated_Code/Enable2.c \
../Generated_Code/HOTPWM.c \
../Generated_Code/Inhr1.c \
../Generated_Code/LEDBLUE.c \
../Generated_Code/LEDGREEN.c \
../Generated_Code/LEDRED.c \
../Generated_Code/LidPWM.c \
../Generated_Code/MCUC1.c \
../Generated_Code/PE_LDD.c \
../Generated_Code/Pins1.c \
../Generated_Code/PwmLdd1.c \
../Generated_Code/PwmLdd2.c \
../Generated_Code/PwmLdd3.c \
../Generated_Code/TU1.c \
../Generated_Code/TU2.c \
../Generated_Code/Term1.c \
../Generated_Code/UTIL1.c \
../Generated_Code/Ventilador.c 

OBJS += \
./Generated_Code/AD1.o \
./Generated_Code/ASerialLdd1.o \
./Generated_Code/BitIoLdd3.o \
./Generated_Code/BitIoLdd4.o \
./Generated_Code/BitIoLdd5.o \
./Generated_Code/BitIoLdd6.o \
./Generated_Code/BitIoLdd7.o \
./Generated_Code/COLDPWM.o \
./Generated_Code/Clock.o \
./Generated_Code/Cpu.o \
./Generated_Code/Enable2.o \
./Generated_Code/HOTPWM.o \
./Generated_Code/Inhr1.o \
./Generated_Code/LEDBLUE.o \
./Generated_Code/LEDGREEN.o \
./Generated_Code/LEDRED.o \
./Generated_Code/LidPWM.o \
./Generated_Code/MCUC1.o \
./Generated_Code/PE_LDD.o \
./Generated_Code/Pins1.o \
./Generated_Code/PwmLdd1.o \
./Generated_Code/PwmLdd2.o \
./Generated_Code/PwmLdd3.o \
./Generated_Code/TU1.o \
./Generated_Code/TU2.o \
./Generated_Code/Term1.o \
./Generated_Code/UTIL1.o \
./Generated_Code/Ventilador.o 

C_DEPS += \
./Generated_Code/AD1.d \
./Generated_Code/ASerialLdd1.d \
./Generated_Code/BitIoLdd3.d \
./Generated_Code/BitIoLdd4.d \
./Generated_Code/BitIoLdd5.d \
./Generated_Code/BitIoLdd6.d \
./Generated_Code/BitIoLdd7.d \
./Generated_Code/COLDPWM.d \
./Generated_Code/Clock.d \
./Generated_Code/Cpu.d \
./Generated_Code/Enable2.d \
./Generated_Code/HOTPWM.d \
./Generated_Code/Inhr1.d \
./Generated_Code/LEDBLUE.d \
./Generated_Code/LEDGREEN.d \
./Generated_Code/LEDRED.d \
./Generated_Code/LidPWM.d \
./Generated_Code/MCUC1.d \
./Generated_Code/PE_LDD.d \
./Generated_Code/Pins1.d \
./Generated_Code/PwmLdd1.d \
./Generated_Code/PwmLdd2.d \
./Generated_Code/PwmLdd3.d \
./Generated_Code/TU1.d \
./Generated_Code/TU2.d \
./Generated_Code/Term1.d \
./Generated_Code/UTIL1.d \
./Generated_Code/Ventilador.d 


# Each subdirectory must supply rules for building sources it contributes
Generated_Code/%.o: ../Generated_Code/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: Cross ARM C Compiler'
	arm-none-eabi-gcc -mcpu=cortex-m0plus -mthumb -O0 -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections  -g3 -I"C:/Users/Leonardo/Documents/Kinetis/PCR_Final/Static_Code/System" -I"C:/Users/Leonardo/Documents/Kinetis/PCR_Final/Static_Code/PDD" -I"C:/Users/Leonardo/Documents/Kinetis/PCR_Final/Static_Code/IO_Map" -I"C:\Freescale\KDS_v3\eclipse\ProcessorExpert/lib/Kinetis/pdd/inc" -I"C:/Users/Leonardo/Documents/Kinetis/PCR_Final/Sources" -I"C:/Users/Leonardo/Documents/Kinetis/PCR_Final/Generated_Code" -I"C:\Freescale\FSLESL\CM0_FSLESL_4.2_KDS\MLIB\include" -I"C:\Freescale\FSLESL\CM0_FSLESL_4.2_KDS\PCLIB\include" -I"C:/Users/Leonardo/Documents/Kinetis/PCR_Final/Static_Code/Peripherals" -std=c99 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


