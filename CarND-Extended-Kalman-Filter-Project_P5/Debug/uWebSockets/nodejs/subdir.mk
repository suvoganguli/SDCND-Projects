################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../uWebSockets/nodejs/addon.cpp \
../uWebSockets/nodejs/extension.cpp 

OBJS += \
./uWebSockets/nodejs/addon.o \
./uWebSockets/nodejs/extension.o 

CPP_DEPS += \
./uWebSockets/nodejs/addon.d \
./uWebSockets/nodejs/extension.d 


# Each subdirectory must supply rules for building sources it contributes
uWebSockets/nodejs/%.o: ../uWebSockets/nodejs/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: Cross G++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


