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
				readUserListToArray(ulist, &uarr, &uarrLen, &success);
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
		if (success == 0)
		{
			printf("Great! now onto the actual spellcheck!\n");
			checkUserSpelling(uarr, uarrLen, darr, darrLen, settings);
			writeFileToDisk(uarr, uarrLen, argV);
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
			freeList(ulist);
			free(ulist);
		}
		if (dlist != NULL)
		{
			freeList(dlist);
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
			if (uarr != NULL)
			{
				for (i = 0; i < uarrLen; i++)
				{
					free(*(uarr+i));
				}
				free(uarr);
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
	printf("readUserFileToList()\n");
	readStructuredUserFileToList(ulist, argV, success);
}

void readUserListToArray(LinkedList *ulist,  char ***uarr, int *uarrLen, int *success)
{
	printf("readUserListToArray()\n");
	listToArray(ulist, uarr, uarrLen, success);
}

void printUsage(char** argV)
{
	printf("bad arguments, need one (1) file for checking");
}

void checkUserSpelling (char** uarr, int uarrLen, char** darr, int darrLen, SettingsRC *settings)
{
	/* From check.h */
	ActionFunc action;
	if (settings->autoCorrect == TRUE)
	{
		action = &doNotPromptUser;
	}
	else if (settings->autoCorrect == FALSE)
	{
		action = &promptUser;
	}
	check(uarr, uarrLen, darr, darrLen, settings->maxCorrection, action);
}

int promptUser(char *word, char *suggestion)
{
	int decision;
	char prompt[5];
	printf("REPLACE: \"%s\" WITH \"%s\" ? (Y/n)", word, suggestion);
	/*scanf("%s", prompt);*/
	/* fgets was chosen as it will allow you to hit enter for the default,
		scanf will ignore the whitespace until you finally type a letter*/
	fgets(prompt, 5, stdin);

	if ((prompt[0] == 'N')||(prompt[0] == 'n'))
	{
		decision = FALSE;
		printf("NO\n");
	}
	else
	{
		decision = TRUE;
		printf("YES\n");
	}
	return decision;
}

int doNotPromptUser(char *word, char *suggestion)
{
	return TRUE;
}

int writeFileToDisk (char **uarr, int uarrLen, char **argV)
{
	FILE *f;
	int i, success;
	char *outName;
	outName = malloc((strlen(argV[1]) + strlen("-output") + 2) * sizeof(char));
	memset(outName, '\0', 2);
	strcat(outName, argV[1]);
	strcat(outName, "-output");
	printf("OUTPUT FN: %s\n", outName);
	success = 1;
	f = fopen(outName, "w");
	if (f != NULL)
	{
		for (i = (uarrLen-1); i >= 0; i--)
		{
			fprintf(f, "%s\n", uarr[i]);
			printf("fuckosss\n");
		}
		success = 0;
		
	}
	else 
	{
		printf("FILE OUTPUT FAILURE\n");
	}
	return success;
}
