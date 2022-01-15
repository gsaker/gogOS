C_SOURCES = $(wildcard kernel/*.cpp drivers/*.cpp cpu/*.cpp libc/*.cpp)
HEADERS = $(wildcard kernel/*.hpp drivers/*.hpp cpu/*.hpp libc/*.hpp)
# Nice syntax for file extension replacement
OBJ = ${C_SOURCES:.cpp=.o cpu/interrupt.o} 

# Change this if your cross-compiler is somewhere else
CC = ../Bin/i386-elf-7.5.0-Linux-x86_64/bin/i386-elf-gcc
GDB = /usr/local/i386elfgcc/bin/i386-elf-gdb
# -g: Use debugging symbols in gcc
CFLAGS = -g 
run: runemu #clean
# First rule is run by default
os-image.iso: boot/boot.bin kernel.bin
	cat $^ > os-image.iso

# '--oformat binary' deletes all symbols as a collateral, so we don't need
# to 'strip' them manually on this case
kernel.bin: boot/kernelEntry.o ${OBJ}
	../Bin/i386-elf-7.5.0-Linux-x86_64/bin/i386-elf-ld -o $@ -Ttext 0x1000 $^ --oformat binary

# Used for debugging purposes
kernel.elf: boot/kernelEntry.o ${OBJ}
	../Bin/i386-elf-7.5.0-Linux-x86_64/bin/i386-elf-ld -o $@ -Ttext 0x1000 $^ 

runemu: os-image.iso
	qemu-system-x86_64 -fda os-image.iso -machine q35

# Open the connection to qemu and load our kernel-object file with symbols
debug: os-image.bin kernel.elf
	qemu-system-i386 -s -fda os-image.bin -d guest_errors,int &
	${GDB} -ex "target remote localhost:1234" -ex "symbol-file kernel.elf"

# Generic rules for wildcards
# To make an object, always compile from its .c
%.o: %.c ${HEADERS}
	${CC} ${CFLAGS} -ffreestanding -c $< -o $@

%.o: %.asmos-image.iso
	nasm $<  -f elf32 -o $@

%.bin: %.asm
	nasm $< -f bin -o $@

clean:
	rm -rf *.bin *.dis *.o os-image.bin *.elf
	rm -rf kernel/*.o boot/*.bin drivers/*.o boot/*.o cpu/*.o


include Kernel/makefile

kernel: build_kernel grub qemu

kernel_clean: clean_kernel build_kernel grub qemu
kernel_arm: arm clean_kernel build_kernel grub qemu

arm:
	env /usr/bin/arch -x86_64 /bin/zsh --login
	
grub:
	rm -rf ./iso
	mkdir iso
	mkdir iso/boot
	mkdir ./iso/boot/grub
	touch iso/boot/grub/grub.cfg

# CP kernel.bin to iso/boot
	cp bin/x86/kernel.elf iso/boot/kernel.bin

	echo 'set timeout=1' >  iso/boot/grub/grub.cfg
	echo 'set default=0' >> iso/boot/grub/grub.cfg
	echo ' ' >> iso/boot/grub/grub.cfg
	echo 'menuentry "GogOS" {' >> iso/boot/grub/grub.cfg
	echo '  multiboot /boot/kernel.bin' >> iso/boot/grub/grub.cfg
	echo '  boot' >> iso/boot/grub/grub.cfg
	echo '}' >> iso/boot/grub/grub.cfg
	grub-mkrescue --output=OS.iso iso

qemu:
	qemu-system-x86_64 OS.iso -machine q35

# Note for real USB / Hardware
# Needs to mkfs fat32 onto a drive and use grub-install