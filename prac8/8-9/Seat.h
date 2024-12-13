#ifndef Seat_H
#define Seat_H

#include "Schedule.h"
#include "string"

using namespace std;

class Seat
{
	string name;
public:
	Seat() { name = "---"; }

	string getName() { return name; }
	
	void setSeat(string name) { this->name = name; }
	void cancelSeat(string name) {
		if (this->name == name) this->name = "---";
		else
		{
			cout << "입력된 정보가 올바르지 않아 예약 취소에 실패하였습니다.	";
		}
	
	}
};

#endif
