#include "manager.h"

Manager *newManager()
{
	Manager *m = (Manager *)malloc(sizeof(Manager));
	m->first = NULL;
	m->last = NULL;
	m->registered = 0;
	return m;
}
//printa as ações
int actionManager()
{
	int action;
	clear();
	printf("Put your action:\n");
	printf("1-List All Users\n");
	printf("2-Create new User\n");
	printf("3-Open Calendar\n");
	printf("Press another to exit\n");
	scanf("%d",&action);
	clear();
	return action;
}
//loop do manager
void start(Manager *m)
{
	bool runApp = true;
	do
	{		
		//!executa uma função de acordo com a acao informada
		switch(actionManager())
		{
			case 1:listUsers(m);break;
			case 2:addUser(m);break;
			case 3:openCalendar(m);break;
			default:runApp = false;
		}
	}while(runApp);
	free(m);
}
//!abre o calendario de acordo com id informado
void openCalendar(Manager *m)
{
	int id;
	printf("Id:\n");
	scanf("%d",&id);

	if(!startCalendar(searchCalendar(m,id)))
		pressToContinue();
}
//!procura um calendario de acordo com id
Calendar *searchCalendar(Manager *m,int id)
{
	if(m->first!=NULL)
	{
		Calendar *aux = m->first;
		while(aux!=NULL)
		{
			if(aux->id == id)
				return aux;
			aux = aux->next;
		}
	}
	return NULL;
}
//printa todos os calendarios
void listUsers(Manager *manager)
{
	Calendar *aux = manager->first;
	if(aux == NULL)
		printf("No calendar has been registered!\n");
	else
		while(aux!=NULL)
		{
			printf("\nId: %d\n",aux->id);
			printf("Name: ");
			fputs(aux->name,stdout);
			printf("Email: ");
			fputs(aux->email,stdout);
			aux = aux->next;
		}
	pressToContinue();
}
//!adiciona um novo calendario
void addUser(Manager *m)
{
	//pega valores de entrada
	char *name = getString("Put the name:");
	char *email = getString("Put the E-mail:");
	//cria novo calendario
	Calendar *new = newCalendar(name,email,m->registered++);
	//lista ele
	m->first!=NULL?m->last->next = new:(m->first = new);
	m->last = new;
	pressToContinue();
}