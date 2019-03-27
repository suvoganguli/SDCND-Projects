################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../uWebSockets/build/CMakeFiles/feature_tests.c 

CXX_SRCS += \
../uWebSockets/build/CMakeFiles/feature_tests.cxx 

OBJS += \
./uWebSockets/build/CMakeFiles/feature_tests.o 

C_DEPS += \
./uWebSockets/build/CMakeFiles/feature_tests.d 

CXX_DEPS += \
./uWebSockets/build/CMakeFiles/feature_tests.d 


# Each subdirectory must supply rules for building sources it contributes
uWebSockets/build/CMakeFiles/%.o: ../uWebSockets/build/CMakeFiles/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: Cross GCC Compiler'
	gcc -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

uWebSockets/build/CMakeFiles/%.o: ../uWebSockets/build/CMakeFiles/%.cxx
	@echo 'Building file: $<'
	@echo 'Invoking: Cross G++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


