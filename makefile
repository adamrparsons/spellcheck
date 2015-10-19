CC = /usr/bin/clang
CFLAGS = -ansi -Wall -pedantic -g 
OBJ = spellcheck.o Settings.o LinkedList.o dictionary.o check.o
EXEC = spellcheck

$(EXEC) : $(OBJ)
	$(CC) $(OBJ) -o $(EXEC)

spellcheck.o : spellcheck.c spellcheck.h LinkedList.h Settings.h
	$(CC) $(CFLAGS) -c spellcheck.c

Settings.o : Settings.c Settings.h
	$(CC) $(CFLAGS) -c Settings.c

LinkedList.o : LinkedList.c LinkedList.h
	$(CC) $(CFLAGS) -c LinkedList.c	

dictionary.o : dictionary.c dictionary.h
	$(CC) $(CFLAGS) -c dictionary.c

check.o : check.c check.h
	$(CC) $(CFLAGS) -c check.c

clean : 
	rm -rf $(EXEC) $(OBJ)