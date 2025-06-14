BIN=bin
CFLAGS=-Werror -Wextra -ansi -pedantic -Wuninitialized
CFLAGS_tables = -Wno-unused-parameter
CFLAGS_main = -Wall
ODIR =obj
_OBJ = main.o
OBJ = $(patsubst %,$(ODIR)/%,$(_OBJ))
SRC = src
_OUTPUT = euclid
OUTPUT = $(BIN)/$(_OUTPUT)
ICX := $(shell command -v icx 2>/dev/null)
ifeq ($(ICX),)
    CC := gcc
else
    CC := icx
endif

$(shell mkdir -p $(ODIR))

$(ODIR)/%.o: $(SRC)/%.c
	$(CC) -c -o $@ $< $(CFLAGS) $(CFLAGS_$*)

$(shell mkdir -p $(BIN))

$(OUTPUT): $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS) -Wall

.PHONY: clean

clean:
	rm -r $(ODIR)
