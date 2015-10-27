/* LinkedList.c
*/

# include "LinkedList.h"

/* Set head of list to NULL */
void setList(LinkedList *ll)
{
	if (ll != NULL)
	{
		ll->head = NULL;
	}
	else
	{
		fprintf(stderr, "ERROR: LinkedList NOT NULL\n");
	}
}

/* Function takes a single word (char*) and pointer to the linked-list, and stores it at the top of the list (stack) */
int insertWord(LinkedList *ll, char *word)
{
	int ret = -1;
	Node *incoming;

	incoming = malloc(sizeof(Node));
	incoming->data = malloc(strlen(word)+1 * sizeof(char));
	incoming->next = ll->head;
	ll->head = incoming;
	/* FIXME: consider using strncpy*/
	strcpy(incoming->data, word);
	if (strcmp(incoming->data, word))
	{
		ret = 0;
	}
	return ret;
}

/* Takes a linked-list pointer and returns the size of the linkedlist as an int of nodes found */
int getLength (LinkedList *ll)
{
	int length;
	Node *currNode = ll->head;
	if (currNode == NULL)
	{
		length = 0;
	}
	else if (currNode->next == NULL)
	{
		length = 1;
	}
	else
	{
		length = 0;
		while (currNode != NULL)
		{
			length++;
			currNode = currNode->next;
		}
	}

	return length;
}

/* FIXME: Should be 'pop' not 'dequeue', as this operates in a stack fashion */
/* This function will take a linked-list pointer and return the 'word' sitting on the 
    stack, and reset the head to be the next 'word' */
char* dequeue(LinkedList *ll)
{
	Node *currNode;
	int wordLength;
	char* wordOut = NULL;

	if (ll->head != NULL)
	{	
		currNode = ll->head;
		wordLength = strlen(currNode->data);
		wordOut = malloc(wordLength+1 * sizeof(char));
		strncpy(wordOut, currNode->data, wordLength+1);
		ll->head = currNode->next;
		free(currNode->data);
		free(currNode);
	}
	else 
	{
		fprintf(stderr, "ERROR: Cannot dequeue NULL or empty LinkedList\n");
	}

	return wordOut;
}

/* This function will take a populated linked-list, an uninitialised 2D array
    (in the form of a char triple pointer, so that the double pointer may be accessed outside) */
void listToArray(LinkedList *list, char ***arr, int *arrLen, int *success)
{
	int listLength, i;

	listLength = getLength(list);
	*arrLen = listLength;
	/*printf("Processing %d nodes\n", listLength);*/
	*arr = malloc(listLength * sizeof(char*));
	for (i = 0; i < listLength; i++)
	{
		*(*arr + i) = dequeue(list);
	}
}

/* Takes a linked-list pointer, and will subsequently free all nodes and their members */ 
void freeList(LinkedList *ll)
{
	Node *currNode, *newNode;
	if (ll != NULL)
	{
		currNode = ll->head;
		while (currNode != NULL)
		{
			newNode = currNode->next;
			free(currNode->data);
			free(currNode);
			currNode = newNode;
		}
	}
}
