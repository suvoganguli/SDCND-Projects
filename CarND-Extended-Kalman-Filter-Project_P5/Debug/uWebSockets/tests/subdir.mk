################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../uWebSockets/tests/main.cpp 

OBJS += \
./uWebSockets/tests/main.o 

CPP_DEPS += \
./uWebSockets/tests/main.d 


# Each subdirectory must supply rules for building sources it contributes
uWebSockets/tests/%.o: ../uWebSockets/tests/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: Cross G++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


