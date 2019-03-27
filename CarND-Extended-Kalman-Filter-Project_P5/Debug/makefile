################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include subdir.mk
-include uWebSockets/tests/subdir.mk
-include uWebSockets/src/subdir.mk
-include uWebSockets/nodejs/subdir.mk
-include uWebSockets/examples/subdir.mk
-include uWebSockets/build/CMakeFiles/subdir.mk
-include uWebSockets/build/CMakeFiles/3.12.4/CompilerIdCXX/subdir.mk
-include uWebSockets/build/CMakeFiles/3.12.4/CompilerIdC/subdir.mk
-include uWebSockets/benchmarks/subdir.mk
-include src/subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(C++_DEPS)),)
-include $(C++_DEPS)
endif
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
ifneq ($(strip $(CC_DEPS)),)
-include $(CC_DEPS)
endif
ifneq ($(strip $(CPP_DEPS)),)
-include $(CPP_DEPS)
endif
ifneq ($(strip $(CXX_DEPS)),)
-include $(CXX_DEPS)
endif
ifneq ($(strip $(C_UPPER_DEPS)),)
-include $(C_UPPER_DEPS)
endif
endif

-include ../makefile.defs

# Add inputs and outputs from these tool invocations to the build variables 

# All Target
all: Udacity-EKF

# Tool invocations
Udacity-EKF: $(OBJS) $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: Cross G++ Linker'
	g++  -o "Udacity-EKF" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(C++_DEPS)$(OBJS)$(C_DEPS)$(CC_DEPS)$(CPP_DEPS)$(EXECUTABLES)$(CXX_DEPS)$(C_UPPER_DEPS) Udacity-EKF
	-@echo ' '

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets
