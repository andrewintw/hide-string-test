CC := gcc
CFLAGS := -Wall -Wextra
SRC := $(wildcard *.c)
EXECUTABLES := $(patsubst %.c,%,$(SRC))

all: clean $(EXECUTABLES)

%: %.c
	$(CC) $(CFLAGS) $< -o $@

.PHONY: clean

clean:
	rm -f $(EXECUTABLES)

