################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../trustzone/tzm_config.c \
../trustzone/veneer_table.c 

OBJS += \
./trustzone/tzm_config.o \
./trustzone/veneer_table.o 

C_DEPS += \
./trustzone/tzm_config.d \
./trustzone/veneer_table.d 


# Each subdirectory must supply rules for building sources it contributes
trustzone/%.o: ../trustzone/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: MCU C Compiler'
	arm-none-eabi-gcc -std=gnu99 -D__MULTICORE_NONE -DCPU_LPC55S69JBD100_cm33_core0 -DARM_MATH_CM33 -DCPU_LPC55S69JBD100 -DCPU_LPC55S69JBD100_cm33 -DSDK_DEBUGCONSOLE=0 -DCR_INTEGER_PRINTF -D__MCUXPRESSO -D__USE_CMSIS -DDEBUG -D__MULTICORE_MASTER -DFSL_RTOS_BM -DSDK_OS_BAREMETAL -D__NEWLIB__ -I../drivers -I../component/uart -I../component/serial_manager -I../device -I../CMSIS -I../utilities -I../component/lists -I"/home/zhuaiballl/code/iot_trusted/iot_trusted_s/app_include" -I../board -I../source -I../ -I../startup -I../trustzone -O0 -fno-common -g3 -Wall -c  -ffunction-sections  -fdata-sections  -ffreestanding  -fno-builtin  -mcpu=cortex-m33 -fmerge-constants -fmacro-prefix-map="../$(@D)/"=. -mcpu=cortex-m33 -mfpu=fpv5-sp-d16 -mfloat-abi=hard -mthumb -mcmse -D__NEWLIB__ -fstack-usage -specs=nano.specs -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.o)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


