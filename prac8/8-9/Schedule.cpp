#include <iostream>
#include "Schedule.h"


void Schedule::showSchedules()
{
	cout << time << ':';
	for (int i = 0; i < 8; i++)
	{
		cout << "   " << seats[i].getName() << "   ";
	}
	cout << '\n';
}
