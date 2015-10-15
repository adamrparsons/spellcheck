# include "settings.h"

void parseSettings(FILE *setfp, SettingsRC *settings)
{
	if (setfp != NULL)
	{
		parseSettingsFile(setfp, settings); // If file valid, start reading;
	}
	else if (setfp == NULL)
	{
		printf("settingsrc failed to read\n");
	}
}

void parseSettingsFile(FILE *setfp, SettingsRC *settings)
{
	char* buffer, word, key, value;
	while (ferror() = 0)
	{
		fgets(setfp, buffer, MAXLEN);
		if (*(buffer + 0) == '#') //Line is a comment, ignore
		{
		}
		else 
		{
			parseLine(buffer, key, value);
			if (key == dictionary)
			{
				
			}
			else if (key == maxcorrection)
			{

			}
			else if (key == autocorrect)
			{

			}
			else
			{
				fprintf(stderr, "ERROR: Incorrect Directive %s\n", key);
			}
		}
	}
}


/*
parseLine - copies a configuration file entry into a key and value pair
returns 2 when a key-value pair found, -1 when error occured
Known Issues
	anything after the value will be concatenated, as all whitespace is removed
*/
int parseLine(char* inLine, char* key, char* value)
{
	int counter = 0;
	char* line, outKey, outValue;

	line = malloc(MAXLEN * sizeof(char));
	strncpy(inLine, line, MAXLEN);
	line = removeSpacesFromString(line); /* Algorithm will only deal with line correctly if no whitespace */
	while (line != null)
	{
		counter++;
		if (counter == 1)
		{	
			outKey = strtok(line, '=');
		}
		else if (counter == 2)
		{		
			outValue = strtok(line, '=');
		}
		else 
		{
			fprintf(stderr, "ERROR: Incorrectly formatted line: %s\n", inLine);
			counter = -1;
		}
	}
	if (counter == 2)
	{
		key = outKey;
		value = outValue;
	}
	return counter;
}

/* Removes only whitespace from a string, string will be reallocated to the new size */
char* removeSpacesFromString (char* inString)
{
	int i;
	int j = 0;
	int k = 0;
	char *outString;
	int length = strlen(inString);

	for (i = 0; i < length; i++)
	{
		if (inString[i] != ' ')
		{
			j++
		}
	}
	outString = malloc((j + 1) * sizeof(char));
	for (i = 0; i < length; i++)
	{
		if (inString[i] != ' ')
		{
			k++;
			outString[k-1] = inString[i];
		}
	}
	return outString;
}









