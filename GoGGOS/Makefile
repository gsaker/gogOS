# $@ = target file
# $< = first dependency
# $^ = all dependencies

# First rule is the one executed when no parameters are fed to the Makefile
all: run cleanpost

# Notice how dependencies are built as needed
kernel.bin: kernelEntry.o kernel.o
	i686-elf-ld -o $@ -Ttext 0x1000 $^ --oformat binary

kernelEntry.o: kernelEntry.asm
	nasm $< -f elf -o $@

kernel.o: kernel.c
	i686-elf-gcc -ffreestanding -c $< -o $@

# Rule to disassemble the kernel - may be useful to debug
kernel.dis: kernel.bin
	ndisasm -b 32 $< > $@

bootsect.bin: boot.asm
	nasm $< -f bin -o $@

os-image.bin: bootsect.bin kernel.bin
	cat $^ > $@

run: os-image.bin
	qemu-system-x86_64 -fda $<

cleanpost:
	rm *.o *.dis
clean:
	rm *.bin *.o *.dis