#include "meet.h"

//!cria uma nova reuniao de acordo com os parametros
Meet *newMeet(char *ab,char *local, short int b, short int end,bool required)
{
	Meet *n = (Meet*)malloc(sizeof(Meet));
	n->about = ab;
	n->begin = b;
	n->end = end;
	n->local = local;
	n->required = required;
	n->next = NULL;
	return n;
}
//printa os valores de uma reuniao
void printMeet(Meet *m)
{
	printf("About: %s",m->about);
	printf("Begin: %d",m->begin);
	printf("\nEnd: %d",m->end);
	printf("\nLocal: %s",m->local);
	printf("\nRequired: %s\n",m->required?"Yes":"No");
	printf("***************************\n");
}
//printa toda a lista de reunioes
void printMeets(Meet* m)
{
	if(m!=NULL)
	{
		printf("##########MEET##########\n");
		while(m!=NULL)
		{
			printMeet(m);
			m = m->next;
		}
	}
	else
		printf("You don't have any meets!\n");
}
//checa se nao tem horario com uma meet
//retorna true se colidir
bool isCoincidentMeet(Meet *m, int b)
{
	if(m!=NULL)
	{
		if(m->begin == b)
		{
			printf("You have a meet in the same hour!\n");
			printMeet(m);
			return true;
		}
		m = m->next;
	}
	return false;
}