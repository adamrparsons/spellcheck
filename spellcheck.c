# include "spellcheck.h"

int main (int argC, char* argV[])
{
/* Declarations */
	int ret = 1;
	char** dictionaryArray;
	FILE *setfp;
	SettingsRC *settings;
	LinkedList *dictList/*, *userFile*/;
/* ------------ */

/* Sanity checking */
/* --------------- */

/* Read spellrc */
	setfp = fopen("spellrc", "r");
	if (setfp != NULL)
	{
		settings = malloc(sizeof(SettingsRC));
		parseSettings(setfp, settings);
		ret = 0;
		fclose(setfp);
	}
/* --------------- */

/* Read Dictionary */

	dictList = malloc(sizeof(LinkedList));
	readDictIntoList(dictList, settings);
	dictionaryArray = putListIntoArray(dictList);
	free(dictList);	
/* --------------- */

/* Read User file */

/* --------------- */



	/*
		Not freed yet:
			*settings
	*/
	free(settings->dictionaryTextFN);
	free(settings);
	free(dictionaryArray);

	return ret;
}

void readDictIntoList(LinkedList *dictList, SettingsRC *settings)
{
	FILE *dictionary_fp;
	dictionary_fp = fopen(settings->dictionaryTextFN, "r");
	if (dictionary_fp == NULL)
	{
		perror("File Error: ");
	}
	else if (dictionary_fp != NULL)
	{
		readFileToList(dictionary_fp, dictList);	
	}
}


char** putListIntoArray(LinkedList *dictList)
{
	return (char**)NULL;
}