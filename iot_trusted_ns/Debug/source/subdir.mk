################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../source/app_4G.c \
../source/app_nbiot.c \
../source/app_uart.c \
../source/main_ns.c \
../source/secure_varibale.c \
../source/semihost_hardfault.c 

OBJS += \
./source/app_4G.o \
./source/app_nbiot.o \
./source/app_uart.o \
./source/main_ns.o \
./source/secure_varibale.o \
./source/semihost_hardfault.o 

C_DEPS += \
./source/app_4G.d \
./source/app_nbiot.d \
./source/app_uart.d \
./source/main_ns.d \
./source/secure_varibale.d \
./source/semihost_hardfault.d 


# Each subdirectory must supply rules for building sources it contributes
source/%.o: ../source/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: MCU C Compiler'
	arm-none-eabi-gcc -std=gnu99 -DCPU_LPC55S69JBD100_cm33_core0 -DARM_MATH_CM33 -DCPU_LPC55S69JBD100 -DCPU_LPC55S69JBD100_cm33 -DSDK_DEBUGCONSOLE=0 -DCR_INTEGER_PRINTF -D__MCUXPRESSO -D__USE_CMSIS -DDEBUG -D__NEWLIB__ -D__MULTICORE_MASTER -I../board -I"/home/zhuaiballl/code/iot_trusted/iot_trusted_ns/app_include" -I../source -I../ -I../drivers -I../CMSIS -I../device -I../startup -I../component/lists -I../component/serial_manager -I../utilities -I../component/uart -I../trustzone -O0 -fno-common -g3 -Wall -D __SEMIHOST_HARDFAULT_DISABLE  -c  -ffunction-sections  -fdata-sections  -ffreestanding  -fno-builtin  -mcpu=cortex-m33 -fmerge-constants -fmacro-prefix-map="../$(@D)/"=. -mcpu=cortex-m33 -mfpu=fpv5-sp-d16 -mfloat-abi=hard -mthumb -D__NEWLIB__ -fstack-usage -specs=nano.specs -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.o)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


