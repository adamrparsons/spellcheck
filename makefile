CC = gcc
CFLAGS = -ansi -Wall -pedantic
OBJ = LinkedList.o spellsettings.o SpellCheck.o
EXEC = SpellCheck

$(EXEC) : $(OBJ)
	$(CC) $(OBJ) -o $(EXEC)

SpellCheck.o : SpellCheck.c SpellCheck.h
	$(CC) $(CFLAGS) -c SpellCheck.c

LinkedList.o : LinkedList.c LinkedList.h
	$(CC) $(CFLAGS) -c LinkedList.c

spellsettings.o : spellsettings.c spellsettings.h
	$(CC) $(CFLAGS) -c spellsettings.c

clean : 
	rm -rf $(EXEC) $(OBJ)

