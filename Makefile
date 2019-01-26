CC = gcc
CFLAGS = -O2 -g -Wall

linked-list-test: linked-list-test.o linked-list.o
clean:
	-/bin/rm -rf *.o linked-list-test
tidy: clean
	-/bin/rm -rf *~ .*~

linked-list.o: linked-list.c linked-list.h
linked-list-test.o: linked-list-test.c linked-list.h
