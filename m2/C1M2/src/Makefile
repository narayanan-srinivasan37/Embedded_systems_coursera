#******************************************************************************
# Copyright (C) 2017 by Alex Fosdick - University of Colorado
#
# Redistribution, modification or use of this software in source or binary
# forms is permitted as long as the files maintain this copyright. Users are 
# permitted to modify this and use it to learn about the field of embedded
# software. Alex Fosdick and the University of Colorado are not liable for any
# misuse of this material. 
#
#*****************************************************************************

#------------------------------------------------------------------------------
# Makefile for the native and cortex-m4 build system
#
# Use: make [TARGET] [PLATFORM-OVERRIDES]
#
# Build Targets:
#	<file.i> - Builds <file.i> preprocessor file
#	<file.asm> -  Builds <file.asm> assembly file
#	<file.o> -  Builds <file.o> object file
#	<file.dep> -  Builds <file.dep> dependent file
#	compile - Provides object file for all the source file without linking
#	build - Builds and links all source file
#	all - same as build
#	clean - removes all generated files
# Platform Overrides:
#	PLATFORM - Target platform (Native, MSP432)
#------------------------------------------------------------------------------
include sources.mk

# Platform Overrides
PLATFORM = 
TARGET = c1m2
ifeq ($(PLATFORM),MSP432)
# Architectures Specific Flags
	LINKER_FILE = ../msp432p401r.lds
	CPU = cortex-m4
	ARCH = armv7e-m
	SPECS = nosys.specs
# Compiler Flags and Defines
	CC = arm-none-eabi-gcc
	LD = arm-none-eabi-ld
	LDFLAGS = -Wl,-Map=$(TARGET).map -T $(LINKER_FILE)
	CMFLAGS = -Wall -Werror -g -O0 -std=c99 
	CFLAGS = $(CMFLAGS) $(INCLUDES) -mcpu=$(CPU) -march=$(ARCH) --specs=$(SPECS) -mthumb -mfloat-abi=hard -mfpu=fpv4-sp-d16
endif

ifeq ($(PLATFORM),HOST)
# Architectures Specific Flags
	LINKER_FILE = -L/usr/bin/ld

# Compiler Flags and Defines
	CC = gcc
	LD=ld
	LDFLAGS = -Wl,-Map=$(TARGET).map  $(LINKER_FILE)
	CFLAGS = $(INCLUDES) -Wall -Werror -g -std=c99
endif

PP = $(SOURCES:.c=.i)
AS = $(SOURCES:.c=.asm)
OBJS = $(SOURCES:.c=.o)
DF = $(SOURCES:.c=.dep)

%.i : %.c
	$(CC) -E $< $(CFLAGS) -o $@ -D$(PLATFORM)

%.asm : %.c
	$(CC) -S $< $(CFLAGS) -o $@ -D$(PLATFORM)

%.o : %.c
	$(CC) -c $< $(CFLAGS) -o $@ -D$(PLATFORM)

%.dep : %.c
	$(CC) -M $< $(CFLAGS) -o $@ -D$(PLATFORM)

.PHONY: compile
compile :	
	$(CC) -c $(SOURCES) $(CFLAGS) -D$(PLATFORM)

.PHONY: build
build: all

.PHONY: all
all : $(TARGET).out

$(TARGET).out : $(OBJS)
	$(CC) $(OBJS) $(CFLAGS) $(LDFLAGS) -o $@

.PHONY : clean
clean:
	rm -f *.o *.asm *.i *dep $(TARGET).out $(TARGET).map

