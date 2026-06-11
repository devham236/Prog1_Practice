CC = gcc
CFLAGS = -std=gnu11 -Wall -Wpointer-arith -Wfatal-errors -g
MATH = -lm
PROG1LIBNAME = prog1
PROG1LIBDIR = ../prog1lib/lib

SOURCES = $(wildcard *.c)
BINARIES = $(SOURCES:.c=)

.SUFFIXES:

prog1lib:
	$(MAKE) -C $(PROG1LIBDIR)

all: $(BINARIES)

%: %.c prog1lib
	$(CC) $(CFLAGS) $< -I$(PROG1LIBDIR) -L$(PROG1LIBDIR) -l$(PROG1LIBNAME) -o $@ $(MATH)

.PHONY: clean
clean:
	rm -f $(BINARIES)
