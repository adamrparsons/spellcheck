typedef struct SettingsRC{
	int maxCorrection;
	char* dictionaryTextFN;
	int autoCorrect;
}SettingsRC;

# DEFINE MAXLEN 100

char* removeSpacesFromString (char* inString);
int parseLine(char* inLine, char* key, char* value);
void parseSettingsFile(FILE *setfp, SettingsRC *settings);
void parseSettings(FILE *setfp, SettingsRC *settings);