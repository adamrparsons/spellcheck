/*	dictionary.c
*/

# include "dictionary.h"

void readStructuredDictionaryToList(SettingsRC *settings, LinkedList *dlist, int *success)
{
	FILE *f;
	char *buffer;
	int nRead = 1;
	int inserted = 0;
	f = fopen(settings->dictionaryTextFN, "r");
	if (f != NULL)
	{
		buffer = malloc(100 * sizeof(char));
		while (nRead > 0)
		{
			nRead = fscanf(f, "%s\n", buffer);
			if (nRead == 1)
				insertWord(dlist, buffer);
				inserted++;
			}
		}
		*success = 0;
		free(buffer);
		fclose(f);
	}
	else
	{
		perror("perror: ");
		*success = BADDICTIONARYFILE;
	}
	printf("Total of %d words read from dict file\n", inserted);
}
