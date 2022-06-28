CC=gcc
CFLAGS=-I.

hellomake: main.o keylogger.o 
	$(CC) -o main main.o keylogger.o
