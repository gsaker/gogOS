
CC_KERNEL = ../Bin/i386-elf-7.5.0-Linux-x86_64/bin/i386-elf-gcc
ASM_KERNEL = nasm
ASMINT_KERNEL = nasm
AS_KERNEL = as

CFLAGS_KERNEL= -m32 -ffreestanding -fshort-wchar -mno-red-zone -nostdlib -fno-use-cxa-atexit -fno-builtin -fno-rtti -fno-exceptions -fno-leading-underscore -Wno-write-strings -I./Kernel/inc -fpermissive
ASMFLAGS_KERNEL = -f elf32
ASMINTFLAGS_KERNEL = -f elf32

ASFLAGS_KERNEL = --32

LD_KERNEL=ld
LDFLAGS_KERNEL= -static -nostdlib -melf_i386

SRCDIR_KERNEL := Kernel/src
OBJDIR_KERNEL := Kernel/obj
BUILDDIR_KERNEL := bin

rwildcard=$(foreach d,$(wildcard $(1:=/*)),$(call rwildcard,$d,$2) $(filter $(subst *,%,$2),$d))

SRC_KERNEL = $(call rwildcard,$(SRCDIR_KERNEL),*.cpp)
ASMSRC_KERNEL = $(call rwildcard,$(SRCDIR_KERNEL),*.asm)
ASMSRCINT_KERNEL = $(call rwildcard,$(SRCDIR_KERNEL),*.asmint)
ASSRC_KERNEL = $(call rwildcard,$(SRCDIR_KERNEL),*.s)
OBJS_KERNEL = $(patsubst $(SRCDIR_KERNEL)/%.cpp, $(OBJDIR_KERNEL)/%.o, $(SRC_KERNEL))
OBJS_KERNEL += $(patsubst $(SRCDIR_KERNEL)/%.asm, $(OBJDIR_KERNEL)/%_asm.o, $(ASMSRC_KERNEL))
OBJS_KERNEL += $(patsubst $(SRCDIR_KERNEL)/%.s, $(OBJDIR_KERNEL)/%_as.o, $(ASSRC_KERNEL))
OBJS_KERNEL += $(patsubst $(SRCDIR_KERNEL)/%.asmint, $(OBJDIR_KERNEL)/%_asmint.o, $(ASMSRCINT_KERNEL))

DIRS_KERNEL = $(wildcard $(SRCDIR_KERNEL)/*)

LINKER_KERNEL=./Kernel/linker-x86.ld
KERNEL=kernel.elf

build_kernel: $(OBJS_KERNEL) link_kernel # $(SMP_KERNEL)

$(OBJDIR_KERNEL)/%.o: $(SRCDIR_KERNEL)/%.cpp
	@ echo !==== COMPILING $^
	@ mkdir -p $(@D)
	$(CC_KERNEL) $(CFLAGS_KERNEL) -c $^ -o $@

$(OBJDIR_KERNEL)/%_asm.o: $(SRCDIR_KERNEL)/%.asm
	@ echo !==== COMPILING $^
	@ mkdir -p $(@D)
	$(ASM_KERNEL) $(ASMFLAGS_KERNEL) $^ -o $@

$(OBJDIR_KERNEL)/%_asmint.o: $(SRCDIR_KERNEL)/%.asmint
	@ echo !==== COMPILING $^
	@ mkdir -p $(@D)
	$(ASMINT_KERNEL) $(ASMINTFLAGS_KERNEL) $^ -o $@

$(OBJDIR_KERNEL)/%_as.o: $(SRCDIR_KERNEL)/%.s
	@ echo !==== COMPILING $^
	@ mkdir -p $(@D)
	$(AS_KERNEL) $(ASFLAGS_KERNEL) $^ -o $@

link_kernel: $(LINKER_KERNEL)
	@ echo !==== Linking
	$(LD_KERNEL) $(LDFLAGS_KERNEL) -T $< -o $(BUILDDIR_KERNEL)/x86/$(KERNEL) $(OBJS_KERNEL)

clean_kernel:
	rm -rf $(OBJDIR_KERNEL)