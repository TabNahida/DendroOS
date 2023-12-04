GPPPARAMS = -m64 -fno-use-cxa-atexit -nostdlib -fno-builtin -fno-rtti -fno-exceptions -fno-leading-underscore -Wno-write-strings
ASPARAMS = --64
LDPARAMS = -melf_x86_64
objects = loader.o \
          kernel.o \
%.o: %.cpp
	g++ $(GPPPARAMS) -o $@ -c $<

%.o: %.asm
	as $(ASPARAMS) -o $@ $<

DendroKernel.bin: linker.ld $(objects)
	ld $(LDPARAMS) -T $< -o $@ $(objects)

DendroOS.iso: DendroKernel.bin
	rm -rf iso
	mkdir iso
	mkdir iso/boot
	mkdir iso/boot/grub
	cp $< iso/boot/
	echo 'set timeout=0' >> iso/boot/grub/grub.cfg
	echo 'set default=0' >> iso/boot/grub/grub.cfg
	echo ' ' >> iso/boot/grub/grub.cfg
	echo '	menuentry "DendroOS - Dendro Operating System" {' >> iso/boot/grub/grub.cfg
	echo '	multiboot /boot/DendroKernel.bin' >> iso/boot/grub/grub.cfg
	echo '	boot' >> iso/boot/grub/grub.cfg
	echo '}' >> iso/boot/grub/grub.cfg
	grub-mkrescue --output=$@ iso
	rm -rf iso

.PHONY: clean
clean:
	rm -rf $(objects) DendroKernel.bin DendroOS.iso