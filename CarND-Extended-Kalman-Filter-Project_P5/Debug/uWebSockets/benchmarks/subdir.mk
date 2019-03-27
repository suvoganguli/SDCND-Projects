################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../uWebSockets/benchmarks/crow.cpp \
../uWebSockets/benchmarks/lws.cpp \
../uWebSockets/benchmarks/scalability.cpp \
../uWebSockets/benchmarks/scalability_socketio.cpp \
../uWebSockets/benchmarks/throughput.cpp \
../uWebSockets/benchmarks/throughput_socketio.cpp \
../uWebSockets/benchmarks/uWS.cpp \
../uWebSockets/benchmarks/wsPP.cpp 

OBJS += \
./uWebSockets/benchmarks/crow.o \
./uWebSockets/benchmarks/lws.o \
./uWebSockets/benchmarks/scalability.o \
./uWebSockets/benchmarks/scalability_socketio.o \
./uWebSockets/benchmarks/throughput.o \
./uWebSockets/benchmarks/throughput_socketio.o \
./uWebSockets/benchmarks/uWS.o \
./uWebSockets/benchmarks/wsPP.o 

CPP_DEPS += \
./uWebSockets/benchmarks/crow.d \
./uWebSockets/benchmarks/lws.d \
./uWebSockets/benchmarks/scalability.d \
./uWebSockets/benchmarks/scalability_socketio.d \
./uWebSockets/benchmarks/throughput.d \
./uWebSockets/benchmarks/throughput_socketio.d \
./uWebSockets/benchmarks/uWS.d \
./uWebSockets/benchmarks/wsPP.d 


# Each subdirectory must supply rules for building sources it contributes
uWebSockets/benchmarks/%.o: ../uWebSockets/benchmarks/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: Cross G++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


