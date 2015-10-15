# include "spellcheck.h"

int main (int argC, char* argV[])
{
	/* Declarations */
	int ret = 1;
	FILE *setfp;
	SettingsRC *settings;
	/* ------------ */

	/* Sanity checking */
	/* --------------- */

	/* Read spellrc */
	setfp = fopen("spellrc", "r");
	if (setfp != NULL)
	{
		settings = malloc(sizeof(SettingsRC));
		parseSettings(setfp);
		ret = 0;
	}
	/* --------------- */


	return ret;
}