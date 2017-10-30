################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../board/board.c \
../board/clock_config.c \
../board/pin_mux.c 

OBJS += \
./board/board.o \
./board/clock_config.o \
./board/pin_mux.o 

C_DEPS += \
./board/board.d \
./board/clock_config.d \
./board/pin_mux.d 


# Each subdirectory must supply rules for building sources it contributes
board/%.o: ../board/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: MCU C Compiler'
	arm-none-eabi-gcc -std=gnu99 -DCR_INTEGER_PRINTF -DDEBUG -DFSL_RTOS_FREE_RTOS -DFRDM_KW41Z -DFREEDOM -DSDK_DEBUGCONSOLE=0 -D__MCUXPRESSO -D__USE_CMSIS -DSDK_OS_FREE_RTOS -DCPU_MKW41Z512VHT4 -DCPU_MKW41Z512VHT4_cm0plus -D__REDLIB__ -I"/Users/macos/Google Drive/COMP3215/xpressoTrial/frdmkw41z_rtos_examples_freertos_hello/source" -I"/Users/macos/Google Drive/COMP3215/xpressoTrial/frdmkw41z_rtos_examples_freertos_hello" -I"/Users/macos/Google Drive/COMP3215/xpressoTrial/frdmkw41z_rtos_examples_freertos_hello/drivers" -I"/Users/macos/Google Drive/COMP3215/xpressoTrial/frdmkw41z_rtos_examples_freertos_hello/startup" -I"/Users/macos/Google Drive/COMP3215/xpressoTrial/frdmkw41z_rtos_examples_freertos_hello/utilities" -I"/Users/macos/Google Drive/COMP3215/xpressoTrial/frdmkw41z_rtos_examples_freertos_hello/CMSIS" -I"/Users/macos/Google Drive/COMP3215/xpressoTrial/frdmkw41z_rtos_examples_freertos_hello/freertos" -I"/Users/macos/Google Drive/COMP3215/xpressoTrial/frdmkw41z_rtos_examples_freertos_hello/board" -O0 -fno-common -g -Wall -c -fmessage-length=0 -fno-builtin -ffunction-sections -fdata-sections -mcpu=cortex-m0plus -mthumb -D__REDLIB__ -specs=redlib.specs -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.o)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


