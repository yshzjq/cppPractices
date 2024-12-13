#include <iostream>
#include "AirlineBook.h"
#include "Console.h"

using namespace std;

void Console::start()
{
	cout << "***** 한성항공에 오신것을 환영합니다 ***** \n\n";

	while (true)
	{
		switch (showMenu())
		{
			case 1: 
			{
				int time = showTime();
				int seat = inputSeats(time);
				string name = showName();

				schedule[time].addSeat(seat, name);

				break;
			}
			case 2: // 취소
			{
				int time = showTime();
				int seat = inputSeats(time);
				string name = showName();

				schedule[time].cancelSeat(seat, name);
				break;
			}
			case 3:
			{
				showSeats();
				break;
			}
			case 4:
			{
				cout << "예약 시스템을 종료합니다.";
				return;
			}
			default: 
			{
				cout << "올바르지 않은 입력입니다.";
				break;
			}
		}
	}
}

int Console::showMenu()
{
	cout << "예약:1, 취소:2, 보기:3, 끝내기:4>> ";
	int n;
	cin >> n;
	return n;
}

int Console::showTime()
{
	cout << "07시:1, 12시:2, 17시:3>> ";
	int n;
	cin >> n;
	return n-1;
}

int Console::inputSeats(int time)
{

	schedule[time].showSchedules();

	cout << '\n' << "좌석번호>> ";
	int n;
	cin >> n;
	return n-1;
}

void Console::showSeats()
{
	for (int i = 0; i < 3; i++)
	{
		schedule[i].showSchedules();
	}
}


string Console::showName()
{
	cout << "이름 입력>> ";
	string str;
	cin >> str;
	return str;
}

