################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../uWebSockets/build/CMakeFiles/3.12.4/CompilerIdC/CMakeCCompilerId.c 

OBJS += \
./uWebSockets/build/CMakeFiles/3.12.4/CompilerIdC/CMakeCCompilerId.o 

C_DEPS += \
./uWebSockets/build/CMakeFiles/3.12.4/CompilerIdC/CMakeCCompilerId.d 


# Each subdirectory must supply rules for building sources it contributes
uWebSockets/build/CMakeFiles/3.12.4/CompilerIdC/%.o: ../uWebSockets/build/CMakeFiles/3.12.4/CompilerIdC/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: Cross GCC Compiler'
	gcc -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


