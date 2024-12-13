#ifndef Schedule_H
#define Schedule_H

#include "Seat.h"

using namespace std;

class Schedule
{
	string time;
	Seat* seats;
public:
	Schedule(string time) { this->time = time; seats = new Seat[8]; }
	void showSchedules();
	void addSeat(int seatNum, string name) { seats[seatNum].setSeat(name); }
	void cancelSeat(int seatNum, string name) { seats[seatNum].cancelSeat(name); }
};

#endif
