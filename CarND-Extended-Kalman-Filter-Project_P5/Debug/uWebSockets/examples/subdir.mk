################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../uWebSockets/examples/echo.cpp \
../uWebSockets/examples/multithreaded_echo.cpp 

OBJS += \
./uWebSockets/examples/echo.o \
./uWebSockets/examples/multithreaded_echo.o 

CPP_DEPS += \
./uWebSockets/examples/echo.d \
./uWebSockets/examples/multithreaded_echo.d 


# Each subdirectory must supply rules for building sources it contributes
uWebSockets/examples/%.o: ../uWebSockets/examples/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: Cross G++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


