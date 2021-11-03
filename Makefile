# Makefile for AVR projects

CC=avr-gcc
CP=avr-objcopy

MCU=atmega328p
CPU_FREQ=16000000UL
LIBS=

CC_OPT=-Os -DF_CPU=$(CPU_FREQ) -mmcu=$(MCU) -c

SRC=main.c blink.c
TARGET=main

%.o: %.c
	$(CC) $(CC_OPT) -o $@ $<

all: $(SRC:%.c=%.o)
	$(CC) -mmcu=$(MCU) $(LIBS) -o $(TARGET).elf $(SRC:%.c=%.o)
	$(CP) -O ihex -R .eeprom $(TARGET).elf $(TARGET).hex

flash: all
	avrdude -F -V -c arduino -p ATMEGA328P -P /dev/ttyACM0 -b 115200 -U flash:w:$(TARGET).hex

clean:
	rm -f $(SRC:%.c=%.o) $(TARGET).elf $(TARGET).hex

