# include "spellsettings.h"

int parseSettings(FILE *setfp, SettingsRC *settings)
{
	int success = 0;
	if (setfp != NULL)
	{
		success = parseSettingsFile(setfp, settings); /* If file valid, start reading */
	}
	else if (setfp == NULL)
	{
		success = 4;
		printf("settingsrc failed to read\n");
	}
	return success;
}

int parseSettingsFile(FILE *setfp, SettingsRC *settings)
{
	int success = 0;
	int maxCorrectionRead = 0;
	int dictionaryTextFNRead = 0;
	int autoCorrectRead = 0;
	char *buffer, *key, *value;
	char* foo = NULL;

	buffer = malloc(MAXLEN * sizeof(char));
	key = malloc(MAXLEN * sizeof(char));
	value = malloc(MAXLEN * sizeof(char));

	/* FIXME: rename foo */
	do
	{
		foo = fgets(buffer, MAXLEN, setfp);
		if ((*(buffer + 0) == '#')||(strlen(buffer) < 2)) /* Line is a comment, ignore */
		{
			/* printf("comment: %s\n", buffer);*/
		}
		else 
		{
			printf("Reading line: %s\n", buffer);
			parseLine(buffer, key, value);
			/* FIXME: dont compare to literals 		*/
			/* FIXME: add bounds checking 			*/
			printf("matching %p\n", key);
			if (strcmp("dictionary", key) == 0)
			{
				/*printf("dictionary found\n");*/
				/* If you just assign 'settings->dictionaryTextFN = value' you will 
				segfault when accessing the struct (because value has been freed) */
				settings->dictionaryTextFN = malloc(MAXLEN * sizeof(char));
				strcpy(settings->dictionaryTextFN, value);
				dictionaryTextFNRead++;
				/*printf("dictionary stored\n");*/
			}
			else if (strcmp("maxcorrection", key) == 0)
			{
				/*printf("maxcorrection found\n");*/
				settings-> maxCorrection = atoi(value);
				maxCorrectionRead++;
				/*printf("maxcorrection stored\n");*/
			}
			else if (strcmp("autocorrect", key) == 0)
			{
				/*printf("autocorrect found\n");*/
				settings->autoCorrect = atoi(value);
				autoCorrectRead++;
				/*printf("autocorrect stored\n");*/
			}
			else
			{
				success = 1;
				fprintf(stderr, "ERROR: Unknown Directive %s\n", key);
			}
		}
	} while (foo != NULL);

	free(buffer);
	free(key);
	free(value);
	if ((dictionaryTextFNRead == 0) || (autoCorrectRead == 0) || (maxCorrectionRead == 0))
	{
		/* FIXME: print what is missing */
		printf("Some settings missing from settingsrc\n");
		success = 2;
	}
	return success;
}


/*
parseLine - copies a configuration file entry into a key and value pair
returns 2 when a key-value pair found, -1 when error occured
Known Issues
	anything after the value will be concatenated, as all whitespace is removed
*/
int parseLine(char* inLine, char* key, char* value)
{
	char *line;

	line = malloc(MAXLEN * sizeof(char));
	strncpy(line, inLine, MAXLEN);
	sscanf(inLine, "%s = %s\n", key, value);
	free(line);

	return 0;
}







