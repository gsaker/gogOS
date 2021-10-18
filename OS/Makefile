# $@ = target file
# $< = first dependency
# $^ = all dependencies
GDB = /usr/local/i386elfgcc/bin/i386-elf-gdb
all: run clean

kernel.bin: kernelEntry.o kernel.o
	i686-elf-ld -o $@ -Ttext 0x1000 $^ --oformat binary
kernel.elf: kernelEntry.o kernel.o
	i686-elf-ld -o $@ -Ttext 0x1000 $^

kernelEntry.o: kernelEntry.asm
	nasm $< -f elf -o $@

kernel.o: kernel.c
	i686-elf-gcc -ffreestanding -c $< -o $@

# Rule to disassemble the kernel - may be useful to debug
debug: os-image.bin kernel.elf
	qemu-system-x86_64 -s -fda os-image.bin &
	${GDB} -ex "target remote localhost:1234" -ex "symbol-file kernel.elf"

bootsect.bin: boot.asm
	nasm $< -f bin -o $@

os-image.bin: bootsect.bin kernel.bin
	cat $^ > $@

run: os-image.bin
	qemu-system-x86_64 -fda $<

clean:
	rm *.bin *.o *.dis