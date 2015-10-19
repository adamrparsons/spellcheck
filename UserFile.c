/*	UserFile.c
*/

# include "UserFile.h"

void readStructuredUserFileToList(LinkedList *ulist, char **argV, int *success)
{
	FILE *f;
	char *buffer;
	int nRead = 1;

	printf("%s\n", *(argV + 1));
	f = fopen(*(argV + 1), "r");
	if (f != NULL)
	{
		buffer = malloc(50 * sizeof(char));
		while (nRead > 0)
		{
			nRead = fscanf(f, "%s", buffer);
			if (nRead == 1)
			{
				stripPunctuation(buffer);

				/* from LinkedList.h */
				insertWord(ulist, buffer);
			}
		}
		*success = 0;
		free(buffer);
	}
} 

void stripPunctuation(char *buffer)
{
/*	Planned for later	*/
/*	char* newBuf = malloc(50 * sizeof(char));
	int len = strlen(buffer);
	int i;
	int counter = 0;
	for (i = 0)
	{
		if ((buffer[i] >'A'))
	}*/
}
