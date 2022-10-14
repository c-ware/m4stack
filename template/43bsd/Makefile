# Makefile for 4.3 BSD

M4=m4

CC=cc
CFLAGS=-D__QuasiBSD__
TESTS=CONVERT_FILES(tests, .m4c)

all: $(TESTS)

clean:
	rm -f $(TESTS)

.SUFFIXES:

GENERATE_RULES(tests, .c,)

.PHONY: all clean
