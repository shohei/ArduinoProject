COMPILE = avr-g++ -g -Wall -O2 -DF_CPU=16000000 -mmcu=atmega328p
OBJECTS = main.o pwm.o
AVRDUDE = avrdude -c arduino -p atmega328p -P /dev/tty.usb* -U flash:w:main.hex:i

all: main.hex

main.hex: main.elf
	rm -f main.hex
	avr-objcopy -O ihex main.elf main.hex

main.elf: $(OBJECTS)
	$(COMPILE) -o main.elf $(OBJECTS)

.cpp.o:
	$(COMPILE) -c $< -o $@

flash:
	$(AVRDUDE)

clean:
	rm main.hex main.elf $(OBJECTS)

