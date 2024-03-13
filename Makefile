main:
	avr-gcc -mmcu=atmega32a -o main.bin *.c
	avr-objcopy -j .text -j .data -O ihex main.bin main.hex
	avrdude -p m32 -c usbasp -P usb -U flash:w:main.hex:i

fuse: fuse8MHz_Internal

fuse8MHz_Internal:
	avrdude -c usbasp -p m32 -U lfuse:w:0xe4:m -U hfuse:w:0xd9:m

fuse4MHz_Internal:
	avrdude -c usbasp -p m32 -U lfuse:w:0xe3:m -U hfuse:w:0xd9:m

fuse2MHz_Internal:
	avrdude -c usbasp -p m32 -U lfuse:w:0xe2:m -U hfuse:w:0xd9:m

fuse1MHz_Internal:
	avrdude -c usbasp -p m32 -U lfuse:w:0xe1:m -U hfuse:w:0xd9:m
