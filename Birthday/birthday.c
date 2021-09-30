#include "birthday.h"
//!cria um novo aniversario de acordo com os parametros
Birthday *newBirthday(char *ab,char *local,char *name, short int b, short int end)
{
	Birthday *n = (Birthday*)malloc(sizeof(Birthday));
	n->about = ab;
	n->begin = b;
	n->end = end;
	n->local = local;
	n->name = name;
	n->next = NULL;
	return n;
}
//!printa o aniversario inserido
void printBirthday(Birthday *b)
{
	printf("Name: ");
	fputs(b->name,stdout);

	printf("About: ");
	fputs(b->about,stdout);

	printf("Begin: %d",b->begin);

	printf("\nEnd: %d",b->end);

	printf("\nLocal: ");
	fputs(b->local,stdout);

	printf("*****************************\n");
}

//!printa a lista de aniversarios
void printBirthdays(Birthday* b)
{
	if(b!=NULL)
	{
		printf("##########BIRTHDAY##########\n");
		while(b!=NULL)
		{
			printBirthday(b);
			b = b->next;
		}
	}
	else
		printf("You don't have any birthdays!\n");
}

//!verifica se o horario inserido bate com algum aniversario ja existente
bool isCoincidentBirthday(Birthday *birthday, int b)
{
	if(birthday!=NULL)
	{
		if(birthday->begin == b)
		{
			printf("You have a birthday in the same hour!\n");
			printBirthday(birthday);
			return true;
		}
		birthday = birthday->next;
	}
	return false;
}