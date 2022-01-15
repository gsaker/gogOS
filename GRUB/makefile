C_SOURCES = $(wildcard Kernel/src/*.c )
HEADERS = $(wildcard Kernel/inc/*.h )
# Nice syntax for file extension replacement
OBJ = ${C_SOURCES:.c=.o} 

# Change this if your cross-compiler is somewhere else
CC = i686-elf-gcc

run: qemu clean#clean
# First rule is run by default

# '--oformat binary' deletes all symbols as a collateral, so we don't need
# to 'strip' them manually on this case
gogos.bin: Kernel/boot/boot.o ${OBJ}
#	../Bin/i386-elf-7.5.0-Linux-x86_64/bin/i386-elf-ld -o $@ -Ttext 0x1000 $^ --oformat binary
	i686-elf-gcc -T Kernel/linker.ld -o gogos.bin -ffreestanding -O2 -nostdlib $^ -lgcc
# Generic rules for wildcards
# To make an object, always compile from its .c
%.o: %.c ${HEADERS}
	${CC} -c $< -o $@ -std=gnu99 -ffreestanding -O2 -Wall -Wextra
%.o: %.asm
	nasm $<  -f elf -o $@
clean:
	rm -rf *.bin *.dis *.o os-image.bin *.elf
	rm -rf Kernel/src/*.o 
qemu: grub
	qemu-system-x86_64 -cdrom gogos.iso
Kernel/boot/boot.o: Kernel/boot/boot.s
	i686-elf-as Kernel/boot/boot.s -o Kernel/boot/boot.o
grub: gogos.bin
	echo 'timeout=0' > grub.cfg
	echo 'menuentry "gogOS" {' >> grub.cfg
	echo 'multiboot /boot/gogos.bin' >> grub.cfg
	echo '}' >> grub.cfg
	mkdir -p isodir/boot/grub
	cp gogos.bin isodir/boot/gogos.bin
	cp grub.cfg isodir/boot/grub/grub.cfg
	grub-mkrescue -o gogos.iso isodir
#	mkdir -p Kernel/isodir/boot/grub
#	cp gogos.bin Kernel/isodir/boot/gogos.bin
#	grub-mkrescue -o gogos.iso Kernel/isodir