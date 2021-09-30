#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct Birthday
{
	char *about,*local,*name;
	short int begin,end;
	struct Birthday *next;
} Birthday;

Birthday *newBirthday(char *ab,char *local,char *name, short int b, short int end);
void printBirthdays(Birthday *b);

bool isCoincidentBirthday(Birthday *birthday, int b);