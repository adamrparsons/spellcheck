/*	Settings.c
	Minspec Edition!
*/

# include "Settings.h"

void processSettingsFile(SettingsRC *settings, int *success)
{
	char* settingsRCFileName = "spellrc";
	char *key, *value;
	int readInValues = 0;
	int errVal = 0;
	int a = 0;
	int b = 0;
	int c = 0;
	FILE *settingsFp;

	key = malloc(MAX * sizeof(char));
	value = malloc(MAX * sizeof(char));

	if (settings == NULL)
	{
		printf("SettingsRC pointer NULL\n");
		*success = SETTINGSNULL;
	}
	else
	{
		settingsFp = fopen(settingsRCFileName, "r");
		if (settingsFp != NULL)
		{
			/*printf("spellrc opened for reading\n");*/
			readInValues = fscanf(settingsFp, "%s = %s\n", key, value);
			do
			{
				if (strncmp(key, (char*)"maxcorrection", strlen("maxcorrection"))==0)
				{
					a++;
					settings->maxCorrection = atoi(value);
					if (settings->maxCorrection < 0)
					{
						fprintf(stderr,"ERROR: maxcorrection is negative\n");
						errVal = 1;
					}
				}
			 	else if (strncmp(key, "autocorrect", strlen("autocorrect"))==0)
				{
					b++;
					settings->autoCorrect = strncmp(value, "no", strlen(value));
					if(settings->autoCorrect == 0)
					{
						printf("autoCorrect is off, %i\n", settings->autoCorrect);
					}
					else if (strcmp(value, "yes") == 0)
					{
						printf("autoCorrect is on, %i\n", settings->autoCorrect);
					}
					else 
					{
						*success = INVALIDSETTINGSRC;
					}
				}
				else if (strncmp(key, "dictionary", strlen("dictionary"))==0)
				{
					c++;
					if (settings->dictionaryTextFN != NULL)
					{
						free(settings->dictionaryTextFN);
					}
					settings->dictionaryTextFN = malloc((strlen(key)+1) * sizeof(char));
					strncpy(settings->dictionaryTextFN, value, strlen(value)+1);
				}
				else 
				{
					printf("invalid settingsrc directive, %s\n", key);
					*success = INVALIDSETTINGSRC;
					errVal = 1;
				}
				readInValues = fscanf(settingsFp, "%s = %s\n", key, value);
			} while (readInValues == 2);
			fclose(settingsFp);
			/*printf("spellrc file closed with %i,%i,%i, directives\n", a,b,c);*/

			if ((a>0)&&(b>0)&&(c>0)&&(errVal==0))
			{
				*success = 0;
			}
			else
			{
				*success = INCOMPLETESETTINGSRC;
				fprintf(stderr,"INCOMPLETESETTINGSRC\n");
			}
		}
		else 
		{
			fprintf(stderr,"settingsFp is NULL\n");
			*success = VOIDFILEFP;
		}
	}
	free(key);
	free(value);
}

void setStruct(SettingsRC *settings)
{
	settings->maxCorrection = 0;
	settings->dictionaryTextFN = NULL;
	settings->autoCorrect = 0;
}

