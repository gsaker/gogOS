C_SOURCES = $(wildcard kernel/*.c drivers/*.c cpu/*.c libc/*.c)
HEADERS = $(wildcard kernel/*.h drivers/*.h cpu/*.h libc/*.h)
# Nice syntax for file extension replacement
OBJ = ${C_SOURCES:.c=.o cpu/interrupt.o} 

# Change this if your cross-compiler is somewhere else
CC = ../Bin/i386-elf-7.5.0-Linux-x86_64/bin/i386-elf-gcc
CCARM = i686-elf-gcc
# -g: Use debugging symbols in gcc
CFLAGS = -g 
arm: runemuarm clean
run: runemu clean #clean
# First rule is run by default
os-image.iso: boot/boot.bin kernel.bin
	cat $^ > os-image.iso
os-image.isoarm: boot/boot.bin kernel.binarm
	cat $^ > os-image.isoarm
# '--oformat binary' deletes all symbols as a collateral, so we don't need
# to 'strip' them manually on this case
kernel.bin: boot/kernelEntry.o ${OBJ}
	../Bin/i386-elf-7.5.0-Linux-x86_64/bin/i386-elf-ld -o $@ -Ttext 0x1000 $^ --oformat binary
kernel.binarm: boot/kernelEntry.o ${OBJ}
	i686-elf-ld -o $@ -Ttext 0x1000 $^ --oformat binary
# Used for debugging purposes
kernel.elf: boot/kernelEntry.o ${OBJ}
	../Bin/i386-elf-7.5.0-Linux-x86_64/bin/i386-elf-ld -o $@ -Ttext 0x1000 $^ 

runemu: os-image.iso
	qemu-system-x86_64 -fda os-image.iso
runemuarm: os-image.isoarm
	qemu-system-x86_64 -fda os-image.iso --no-reboot
# Open the connection to qemu and load our kernel-object file with symbols
debug: os-image.bin kernel.elf
	qemu-system-i386 -s -fda os-image.bin -d guest_errors,int &
	${GDB} -ex "target remote localhost:1234" -ex "symbol-file kernel.elf"

# Generic rules for wildcards
# To make an object, always compile from its .c
%.o: %.c ${HEADERS}
	${CCARM} ${CFLAGS} -ffreestanding -c $< -o $@

%.o: %.asm
	nasm $<  -f elf -o $@

%.bin: %.asm
	nasm $< -f bin -o $@

clean:
	rm -rf *.bin *.dis *.o os-image.bin *.elf
	rm -rf kernel/*.o boot/*.bin drivers/*.o boot/*.o cpu/*.o


qemu:
	qemu-system-x86_64 -hda OS.iso -machine q35 -hdb os-image.iso