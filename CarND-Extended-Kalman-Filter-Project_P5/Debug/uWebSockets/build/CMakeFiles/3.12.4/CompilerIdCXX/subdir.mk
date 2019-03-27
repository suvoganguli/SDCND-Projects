################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../uWebSockets/build/CMakeFiles/3.12.4/CompilerIdCXX/CMakeCXXCompilerId.cpp 

OBJS += \
./uWebSockets/build/CMakeFiles/3.12.4/CompilerIdCXX/CMakeCXXCompilerId.o 

CPP_DEPS += \
./uWebSockets/build/CMakeFiles/3.12.4/CompilerIdCXX/CMakeCXXCompilerId.d 


# Each subdirectory must supply rules for building sources it contributes
uWebSockets/build/CMakeFiles/3.12.4/CompilerIdCXX/%.o: ../uWebSockets/build/CMakeFiles/3.12.4/CompilerIdCXX/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: Cross G++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


