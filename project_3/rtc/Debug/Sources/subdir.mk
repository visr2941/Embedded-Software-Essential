################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Sources/binary_logger.c \
../Sources/cirbuf.c \
../Sources/data.c \
../Sources/logger.c \
../Sources/main.c \
../Sources/rtc.c \
../Sources/uart.c 

OBJS += \
./Sources/binary_logger.o \
./Sources/cirbuf.o \
./Sources/data.o \
./Sources/logger.o \
./Sources/main.o \
./Sources/rtc.o \
./Sources/uart.o 

C_DEPS += \
./Sources/binary_logger.d \
./Sources/cirbuf.d \
./Sources/data.d \
./Sources/logger.d \
./Sources/main.d \
./Sources/rtc.d \
./Sources/uart.d 


# Each subdirectory must supply rules for building sources it contributes
Sources/%.o: ../Sources/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: Cross ARM C Compiler'
	arm-none-eabi-gcc -mcpu=cortex-m0plus -mthumb -O0 -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections  -g3 -I"../Sources" -I"../Includes" -std=c99 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


