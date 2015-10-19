/* 	spellcheck.c 
*/

# include "spellcheck.h"

int main (int argC, char* argV[])
{
	SettingsRC *settings;
	LinkedList *dlist, *ulist;
	char **darr, **uarr;
	int darrLen = 0;
	int uarrLen = 0;
	int success = 0;
	int i;

	if (argC != 2)
	{
		printf("args given %d\n", argC);
		printUsage(argV);
		success = NOARGSGIVEN;
	}
	else if (success == 0)
	{
		/*  mallocs and sets */
		settings = malloc(sizeof(SettingsRC));
		setStruct(settings);
		dlist = malloc(sizeof(LinkedList));
		ulist = malloc(sizeof(LinkedList));
		setList(dlist);
		setList(ulist);

		/* 	initializations */
		darr = NULL;
		uarr = NULL;
	
		readSettings(settings, &success);
		if (success == 0)
		{
			readDictionaryIntoList(settings, dlist, &success);
			if (success == 0)
			{
				readDictionaryListIntoArray(dlist, &darr, &darrLen, &success);
				if (success == 0)
				{
					/* Do something, probably nothing */
				}
				else
				{
					printf("ERROR: readDictionaryListIntoArray() FAILED \n");
				}
			}
			else
			{
				printf("ERROR: readDictionaryIntoList() FAILED\n");
			}
		}
		else
		{
			printf("Error: bad settingsrc %d\n", success);
		}
		if (success == 0)
		{		
			readUserFileToList(ulist, argV, &success);
			if (success	== 0)
			{
				readUserListToArray(ulist, &success);
				if (success == 0)
				{
					/* Successful */
				}
				else
				{
					printf("ERROR: readUserListToArray FAILED\n");
				}
			}
			else 
			{
				printf("Error reading User File: %d\n", success);
			}
		}

	/*	Free the mallocs */
		if (settings != NULL)
		{
			if (settings->dictionaryTextFN != NULL)
			{
				free(settings->dictionaryTextFN);
			}
			free(settings);
		}
		if (ulist != NULL)
		{
			free(ulist);
		}
		if (dlist != NULL)
		{
			free(dlist);
		}
		if (success == 0)
		{
			if (darr != NULL)
			{
				for (i = 0; i < darrLen; i++)
				{
					free(*(darr+i));
				}
				free(darr);
			}
		}
	}
	return success;
}

void readSettings(SettingsRC *settings, int *success)
{
	printf("readSettings()\n");
	processSettingsFile(settings, success);
}

void readDictionaryIntoList(SettingsRC *settings, LinkedList *dlist, int *success)
{
	printf("readDictionaryIntoList()\n");
	readStructuredDictionaryToList(settings, dlist, success);
}

void readDictionaryListIntoArray(LinkedList *dlist, char ***darr, int *darrLen, int *success)
{
	printf("readDictionaryListIntoArray()\n");
	listToArray(dlist, darr, darrLen, success);
}

void readUserFileToList(LinkedList *ulist, char** argV, int *success)
{
	printf("readUserFileToList(............................)\n");
	readStructuredUserFileToList(ulist, argV, success);
}

void readUserListToArray(LinkedList *ulist, int *success)
{
	printf("readUserListToArray(............................)\n");

	*success = 0;
}

void printUsage(char** argV)
{
	printf("bad arguments, need one (1) file for checking");
}
