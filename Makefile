.PHONY: clean compile

NASM=$(shell which nasm 2>/dev/null || echo "echo 'Cannot find nasm on your system' && exit 1;)
NASM_FLAGS= -f elf64

TARGET= hw
TARGET_DEP= hw.o

ifdef V
 # Ask make to keep intermediate file
 .PRECIOUS= %.o
 Q=
else
 Q=@
endif
	
%.o: %.S
	$(NASM) $(NASM_FLAGS) $<

$(TARGET): $(TARGET_DEP)
	$(LD) -o $@ $<

.PHONY: clean
clean:
	rm -f $(TARGET) $(TARGET_DEP)
