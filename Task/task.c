#include "task.h"
//cria uma bnova task com os parametros
Task *newTask(char *ab, short int b, short int end, short int eff, short int p)
{
	Task *n = (Task*)malloc(sizeof(Task));
	n->about = ab;
	n->begin = b;
	n->end = end;
	n->effort = eff;
	n->priority = p;
	n->next = NULL;

	return n;
}
//imprime uma task especifica
void printTask(Task *t)
{
	printf("About: %s",t->about);
	printf("Begin: %d",t->begin);
	printf("\nEnd: %d",t->end);
	printf("\nEffort: %d",t->effort);
	printf("\nPriority: %d\n",t->priority);
	printf("***************************\n");
}
//printa toda a lista de task
void printTasks(Task* t)
{
	if(t!=NULL)
	{
		printf("##########TASKS##########\n");
		while(t!=NULL)
		{
			printTask(t);
			t = t->next;
		}
	}
	else
		printf("You don't have any task!\n");
}
//verifica se o horario coincide com alguma tarefa
bool isCoincidentTask(Task *t, int b)
{
	if(t!=NULL)
	{
		if(t->begin == b)
		{
			printf("You have a task in the same hour!\n");
			printTask(t);
			return true;
		}
		t = t->next;
	}
	return false;
}