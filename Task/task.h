#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct Task
{
	char *about;
	short int begin,end;
	short int effort,priority; 
	struct Task *next;
} Task;

Task *newTask(char *ab, short int b, short int end, short int eff, short int p);
void printTasks(Task *t);
bool isCoincidentTask(Task *t, int b);