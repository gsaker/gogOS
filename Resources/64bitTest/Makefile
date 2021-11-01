
bootloader:
	cd ./bootloader/gnu-efi
	make bootloader
copy:
	#rm /run/media/george/EFI/EFI/BOOT/bootx64.efi
	cp ./kernel/bin/kernel.elf /run/media/george/EFI/
	cp ./bootloader/gnu-efi/x86_64/bootloader/main.efi /run/media/george/EFI/EFI/BOOT/bootx64.efi

run :
	umount /run/media/george/EFI/
	mount -U 6319-FC40 /run/media/george/EFI/
	qemu-system-x86_64 -machine q35 -hda /dev/sde -m 1G -cpu qemu64 -drive if=pflash,format=raw,unit=0,file="OVMF_CODE-pure-efi.fd",readonly=on -drive if=pflash,format=raw,unit=1,file="OVMF_VARS-pure-efi.fd" -net none


