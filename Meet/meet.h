#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct Meet
{
	char *about,*local;
	short int begin,end;
	bool required;
	struct Meet *next;
} Meet;

Meet *newMeet(char *ab,char *local, short int b, short int end,bool required);
void printMeets(Meet *m);

bool isCoincidentMeet(Meet *m, int b);