################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/DataBaseQueryBuilder.cpp \
../src/TestSelect.cpp 

OBJS += \
./src/DataBaseQueryBuilder.o \
./src/TestSelect.o 

CPP_DEPS += \
./src/DataBaseQueryBuilder.d \
./src/TestSelect.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -I/home/carmelo/Downloads/googletest-release-1.7.0/include/gtest -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


