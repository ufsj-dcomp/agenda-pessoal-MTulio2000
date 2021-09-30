#include "../Task/task.h"
#include "../Meet/meet.h"
#include "../Birthday/birthday.h"

typedef struct Calendar
{
	char *name;
	char *email;
	int id;
	Task *tasks,*lastTask;
	Meet *meets,*lastMeet;
	Birthday *birthdays,*lastBirthday;
	struct Calendar *next;
}Calendar;

Calendar *newCalendar(char *name,char *email,int id);
bool startCalendar(Calendar *c);
void printCalendar(Calendar*c);
void clear();
void pressToContinue();

char *getString(char s[10000]);

bool isCoincident(Calendar *c,int begin);

void addBirthday(Calendar *c);
void addMeet(Calendar *c);
void addTask(Calendar *c);