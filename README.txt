README.txt
COMP1000 (Unix and C Programming) Assignment - Semester 2, 2015
Submitted by Adam Parsons (17160357)

An easier to read, markdown version can be found in this folder (README.md)

List of Files and their purposes: 

	'check.c'		- Provided by David Cooper, performs the actual word comparison
	'check.h'		- Header file for "check.c", also provided by David Cooper

	'dictionary.c' 	- Reads a correctly formatted dictionary.txt into a Linkedlist
	'dictionary.h'	- Imports "LinkedList.h", "Settings.h"
	
	'LinkedList.c' 	- Performs generic LinkedList functions, including converting a LL to an Array
	'LinkedList.h'	- Defines a LinkedList type and its assosciated Node type for holding data

	'makefile'		- C89 conforming makefile

	'README.txt' 	- This README

	'Settings.c'	- Convoluted logic to read & parse the spellrc file into a struct
	'Settings.h'	- Defines a type for the spellrc struct, also contains a couple of helpful 
					  defines for understanding errors returned by 'int success' that may occur

	'spellrc'		- To be edited by the user, defines settings for the program, namely the 
					  dictionary filename, word difference, and if autocorrect should be used

	'spellcheck.c'	- Contains the main method, and control structures determining if the program should
					  continue, and report errors to the user. Very little functionality occurs in this file, instead calling functions in other c files
	'spellcheck.h'	- Imports all the needed header files for external functions
						'Linkedlist.h' 'Settings.h' 'dictionary.h' 'UserFile.h' 'check.h'

	'UserFile.c'	- Reads a formatted, punctuated user text file into a LinkedList after sanitising
	'UserFile.h'	- Imports 'LinkedList.h'


Assignment Completion 

	To the best of my knowledge, everything asked for in the Assignment Specification has been adhered to and implemented in a working state. 
	There are some memory allocation issues reported by valgrind, mentioning that in printing char*'s returned by Dave's check.c, the read size is of invalid size.

Known bugs
	As of writing, I appear to find very few incorrect words are suggested alternatives, and I've used multiple large dictionaries. I believe this one is my fault, however I do not understand the check function well enough to debug this one.

Test machines
	This assignment was tested on serveral different *NIX systems, 4GWZF2S (314.221), SAESHELL01p, a Mac , and on a Debian 8 (GNU/Linux) desktop. Not that I was expecting much variation in how the code itself works, but I found valgrind to report different errors , or be inconsistent with regard to reporting issues on different computers during initial testing, hence why I thought I would it would be appropriate to mention non-curtin owned machines.

