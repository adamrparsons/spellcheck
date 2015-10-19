/*Testing.c*/

# include <stdio.h>
# include <stdlib.h>
# include <String.h>

int main (int argC, char*argV[])
{
	FILE *f = fopen(argV[1], "r");
	int noRead = -2;
	char* buffer = malloc(200 * sizeof(char));

	while ((noRead != 0)&&(noRead != -1))
	{
		noRead = fscanf(f, "%s", buffer);
		if (noRead == 1)
		printf("%s\n", buffer);
	}


	return 0;
}