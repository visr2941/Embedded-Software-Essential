################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Sources/cirbuf.c \
../Sources/control_layer.c \
../Sources/data.c \
../Sources/main.c \
../Sources/memory.c \
../Sources/rtc.c \
../Sources/uart.c 

OBJS += \
./Sources/cirbuf.o \
./Sources/control_layer.o \
./Sources/data.o \
./Sources/main.o \
./Sources/memory.o \
./Sources/rtc.o \
./Sources/uart.o 

C_DEPS += \
./Sources/cirbuf.d \
./Sources/control_layer.d \
./Sources/data.d \
./Sources/main.d \
./Sources/memory.d \
./Sources/rtc.d \
./Sources/uart.d 


# Each subdirectory must supply rules for building sources it contributes
Sources/%.o: ../Sources/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: Cross ARM C Compiler'
	arm-none-eabi-gcc -mcpu=cortex-m0plus -mthumb -O0 -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections  -g3 -I"../Sources" -I"../Includes" -std=c99 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


