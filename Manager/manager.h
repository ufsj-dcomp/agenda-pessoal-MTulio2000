#include <stdio.h>
#include <stdlib.h>
#include "../Calendar/calendar.h"

typedef struct
{
	Calendar *first,*last;
	int registered;
} Manager;

Manager *newManager();
void start(Manager *manager);
void addUser(Manager *manager);
void listUsers(Manager *manager);
void openCalendar(Manager *manager);
Calendar *searchCalendar(Manager *m,int id);