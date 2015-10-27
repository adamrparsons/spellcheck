## Spellcheck Makefile - COMP1000 Assignment 2015S2
## Adam Parsons, 17160356

CC = gcc
CFLAGS = -ansi -Wall -pedantic -g 
OBJ = 	spellcheck.o Settings.o LinkedList.o dictionary.o \
		check.o UserFile.o
EXEC = spellcheck

$(EXEC) : $(OBJ)
	$(CC) $(OBJ) -o $(EXEC)

spellcheck.o : spellcheck.c spellcheck.h LinkedList.h Settings.h UserFile.h \
				dictionary.h check.h
	$(CC) $(CFLAGS) -c spellcheck.c

Settings.o : Settings.c Settings.h
	$(CC) $(CFLAGS) -c Settings.c

LinkedList.o : LinkedList.c LinkedList.h
	$(CC) $(CFLAGS) -c LinkedList.c	

dictionary.o : dictionary.c dictionary.h LinkedList.h Settings.h
	$(CC) $(CFLAGS) -c dictionary.c

UserFile.o : UserFile.c UserFile.h LinkedList.h
	$(CC) $(CFLAGS) -c UserFile.c

check.o : check.c check.h
	$(CC) $(CFLAGS) -c check.c

clean : 
	rm -rf $(EXEC) $(OBJ)