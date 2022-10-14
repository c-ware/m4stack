# Makefile for VAX ULTRIX.

M4=m4

CC=cc
PREFIX=/usr/local
CFLAGS=-D__ULTRIX__
TESTS=CONVERT_FILES(tests, .m4c)
DOCS=CONVERT_FILES(doc, .cware, .cware)


all: $(TESTS)

install: maninstall

maninstall:
	mkdir -p $(PREFIX)/share/man/mancware
	cp $(DOCS) $(PREFIX)/share/man/mancware

clean:
	rm -f $(TESTS)
	rm -f $(EXAMPLES)

.SUFFIXES:

GENERATE_RULES(tests, .c,)

.PHONY: all clean install maninstall
