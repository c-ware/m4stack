# A collection of m4 macros to make writing Makefiles easier.
# Recommended for a two-pass m4 system.











# Define the implicit rules






# A collection of m4 macros to make writing Makefiles easier.
# Recommended for a two-pass m4 system.











# Define the implicit rules






# Makefile for gemeral UNIX operating systems

M4=m4

CC=cc
CFLAGS=
PREFIX=/usr/local
TESTS=tests/length tests/free tests/addremov tests/pop tests/is_empty tests/peek tests/init tests/push 
DOCS=doc/m4stack.cware doc/M4STACK_PUSH.cware doc/M4STACK_INIT.cware doc/m4stack-intro.cware doc/M4STACK_LENGTH.cware doc/M4STACK_POP.cware doc/M4STACK_IS_EMPTY.cware doc/M4STACK_PEEK.cware doc/M4STACK_DECLARE.cware doc/M4STACK_FREE.cware doc/m4stack-example-tree.cware 

all: $(TESTS)

install: maninstall

maninstall:
	mkdir -p $(PREFIX)/share/man/mancware
	cp $(DOCS) $(PREFIX)/share/man/mancware

clean:
	rm -f $(TESTS)
	rm -f $(EXAMPLES)

.SUFFIXES:

tests/addremov: tests/addremov.c 
	$(CC) tests/addremov.c $(CFLAGS) -o tests/addremov
tests/push: tests/push.c 
	$(CC) tests/push.c $(CFLAGS) -o tests/push
tests/init: tests/init.c 
	$(CC) tests/init.c $(CFLAGS) -o tests/init
tests/peek: tests/peek.c 
	$(CC) tests/peek.c $(CFLAGS) -o tests/peek
tests/is_empty: tests/is_empty.c 
	$(CC) tests/is_empty.c $(CFLAGS) -o tests/is_empty
tests/free: tests/free.c 
	$(CC) tests/free.c $(CFLAGS) -o tests/free
tests/pop: tests/pop.c 
	$(CC) tests/pop.c $(CFLAGS) -o tests/pop
tests/length: tests/length.c 
	$(CC) tests/length.c $(CFLAGS) -o tests/length


.PHONY: all clean install maninstall
