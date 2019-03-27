################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../uWebSockets/src/Extensions.cpp \
../uWebSockets/src/Group.cpp \
../uWebSockets/src/HTTPSocket.cpp \
../uWebSockets/src/Hub.cpp \
../uWebSockets/src/Networking.cpp \
../uWebSockets/src/Node.cpp \
../uWebSockets/src/Socket.cpp \
../uWebSockets/src/WebSocket.cpp \
../uWebSockets/src/WebSocketImpl.cpp \
../uWebSockets/src/uUV.cpp 

OBJS += \
./uWebSockets/src/Extensions.o \
./uWebSockets/src/Group.o \
./uWebSockets/src/HTTPSocket.o \
./uWebSockets/src/Hub.o \
./uWebSockets/src/Networking.o \
./uWebSockets/src/Node.o \
./uWebSockets/src/Socket.o \
./uWebSockets/src/WebSocket.o \
./uWebSockets/src/WebSocketImpl.o \
./uWebSockets/src/uUV.o 

CPP_DEPS += \
./uWebSockets/src/Extensions.d \
./uWebSockets/src/Group.d \
./uWebSockets/src/HTTPSocket.d \
./uWebSockets/src/Hub.d \
./uWebSockets/src/Networking.d \
./uWebSockets/src/Node.d \
./uWebSockets/src/Socket.d \
./uWebSockets/src/WebSocket.d \
./uWebSockets/src/WebSocketImpl.d \
./uWebSockets/src/uUV.d 


# Each subdirectory must supply rules for building sources it contributes
uWebSockets/src/%.o: ../uWebSockets/src/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: Cross G++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


