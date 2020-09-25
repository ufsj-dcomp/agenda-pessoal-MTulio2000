#include "calendar.h"

//!função que limpa o console
void clear()
{
#ifdef __unix__
	system("clear");//*nix
#elif WIN32
	system("cls"); //windows
#endif
}
//!função para fazer o codigo espera um pouco ate o usuario continuar
void pressToContinue()
{
	fflush(stdin);
	printf("\nPress any button to continue!\n");
	getchar();
}
//!cria um novo calendario e retorna ele
Calendar *newCalendar(char *name,char *email, int id)
{
	//!aloca a quantidade necessaria
	Calendar *c = (Calendar*)malloc(sizeof(Calendar));
	//!inicializa todos os valores
	c->name = name;
	c->email = email;
	c->id = id;
	c->tasks = NULL;
	c->meets = NULL;
	c->birthdays = NULL;
	c->lastTask = NULL;
	c->lastMeet = NULL;
	c->lastBirthday = NULL;
	c->next = NULL;
	return c;
}
//printa as acoes do calendario e retorna a açao inserida
int actionCalendar(char *name)
{
	clear();
	//!printa o nome do calendario
	printf("Operating the Calendar of ");
	fputs(name,stdout);
	int action;
	printf("Put your action:\n");
	printf("1-Add new Birthday\n");
	printf("2-Add new Meet\n");
	printf("3-Add new Task\n");
	printf("4-Print Calendar\n");
	printf("Press another to exit\n");
	scanf("%d",&action);
	clear();
	getchar();
	return action;
}
//!loop do calendario
bool startCalendar(Calendar *c)
{
	if(c!=NULL)
	{
		bool runApp = true;
		while(runApp)
		{
			//!executa uma função de acordo com a acao informada
			switch(actionCalendar(c->name))
			{
				case 1:addBirthday(c);break;
				case 2:addMeet(c);break;
				case 3:addTask(c);break;
				case 4:printCalendar(c);break;
				default:runApp = false;
			}
			if(runApp)pressToContinue();
		}
		return true;
	}
	//!se calendario NULL entao ele printa mensagem de aviso e retorna false
	printf("This calendar is not defined!");
	return false;
}

//!imprime todo o calendario
void printCalendar(Calendar*c)
{
	fflush(stdin);
	printBirthdays(c->birthdays);
	printMeets(c->meets);
	printTasks(c->tasks);
}
//!verifica se tem algum horario coincidente
bool isCoincident(Calendar *c,int begin)
{
	bool colidTask = isCoincidentTask(c->tasks,begin);
	bool colidMeet = isCoincidentMeet(c->meets,begin);
	bool colidBirthday = isCoincidentBirthday(c->birthdays,begin);

	return colidBirthday||colidMeet||colidTask;
}

//!Imprime string s, e retorna uma string digitada pelo usuario
char *getString(char s[10000])
{
	fflush(stdin);
	char *c = (char *)malloc(sizeof(char)*100); 
	printf("%s\n",s);
	fgets(c,100,stdin);
}
//!Imprime string s, e retorna um int digitada pelo usuario
short int getShortInt(char s[10000])
{
	fflush(stdin);
	int integer;
	printf("%s\n",s);
	scanf("%d",&integer);
	getchar();
	return integer;
}
//!verifica se horario esta no range permitido
bool checkHour(int v1,int v2)
{
	bool v = (v1<0||v1>23||v2<0||v2>23);
	if(v)printf("Invalid time!\n");
	return v;
}
//!verifica se esforco e prioridade estao no range permitido
bool checkRange(int v1,int v2)
{
	bool v = (v1<1||v1>5||v2<1||v2>5);
	if(v)printf("Invalid range!\n");
	return v;
}
//!adiciona um evento de aniversario
void addBirthday(Calendar *c)
{
	//!pega os valores digitados pelo usuario
	char *name = getString("Put the name:");
	char *local = getString("Put the local:");
	char *about = getString("Put information about:");
	int begin = getShortInt("Put the begin:");
	int end = getShortInt("Put the end:");

	//!checa se os valores de entrada sao validos
	if(checkHour(begin,end))return;
	if(isCoincident(c,begin))return;

	//cria uma variavel nova de acordo com o que foi informado anteriormente
	Birthday *new = newBirthday(about,local,name,begin,end);
	//!lista o novo aniversario à lista de aniversarios
	c->birthdays!=NULL?c->lastBirthday->next = new:(c->birthdays = new);
	c->lastBirthday = new;
}
//adiciona um evento Meet
void addMeet(Calendar *c)
{
	//!printa na tela e recebe as entradas do usuario
	char *local = getString("Put the local:");
	char *about = getString("Put information about:");
	int begin = getShortInt("Put the begin:");
	int end = getShortInt("Put the end:");
	bool required = getShortInt("Put required(1 = true,0=false):");

	//!verifica os horarios e se coincide com outro evento
	if(checkHour(begin,end))return;
	if(isCoincident(c,begin))return;

	//!cria uma nova Meet
	Meet *new = newMeet(about,local,begin,end,required);
	//!coloca na lista
	c->meets!=NULL?c->lastMeet->next = new:(c->meets = new);
	c->lastMeet = new;
}
//adiciona um evento Task
void addTask(Calendar *c)
{
	//!printa na tela e recebe as entradas do usuario	
	char *local = getString("Put the local:");
	char *about = getString("Put information about:");
	int begin = getShortInt("Put the begin:");
	int end = getShortInt("Put the end:");
	int effort = getShortInt("Put the effort:");
	int priority = getShortInt("Put the priority:");

	
	//!verifica os horarios sao validos
	if(checkHour(begin,end))return;
	//!verifica os o esforço e prioridade se sao validas
	if(checkRange(effort,priority))return;
	//!verifica o horario se coincide com outro evento
	if(isCoincident(c,begin))return;

	//!cria uma nova Task
	Task *new = newTask(about,begin,end,effort,priority);
	//!coloca na lista
	c->tasks!=NULL?c->lastTask->next = new:(c->tasks = new);
	c->lastTask = new;
}