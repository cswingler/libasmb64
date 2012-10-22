ARCH := $(shell getconf LONG_BIT)
SRC := src
BIN := bin

all: clean

all:
	mkdir -p $(BIN)
	nasm -f elf$(ARCH) -o $(BIN)/libasmb64.o $(SRC)/libasmb64_$(ARCH).s
	gcc -m$(ARCH) -o $(BIN)/b64_$(ARCH) $(SRC)/b64.c $(BIN)/libasmb64.o

clean:
	rm -f $(BIN)/* 2>/dev/null
