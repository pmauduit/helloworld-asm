.PHONY: clean compile

compile:
	nasm -f elf64 hw.S
	ld -o hw hw.o
	

clean:
	rm hw.o hw
