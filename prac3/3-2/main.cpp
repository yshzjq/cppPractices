#include <iostream>
#include <string>
using namespace std;

class Date
{
	int year;
	int month;
	int day;
public:
	Date(int _year, int _month, int _day);
	Date(string date);

	void show();
	int getYear();
	int getMonth();
	int getDay();
};

Date::Date(int _year, int _month, int _day)
{
	year = _year;
	month = _month;
	day = _day;
}

Date::Date(string date)
{
	year = stoi(date);
	month = stoi(date.substr(date.find('/')+1));
	day = stoi(date.substr(date.find('/', date.find('/') + 1) + 1));
}

void Date::show()
{
	cout << year << "년" << month << "월" << day << "일\n";
}

int Date::getYear()
{
	return year;
}

int Date::getMonth()
{
	return month;
}

int Date::getDay()
{
	return day;
}


int main()
{
	Date birth(2014, 3, 20); //2014년 3월 20일
	Date independenceDay("1945/8/15");
	independenceDay.show();
	cout << birth.getYear() << ',' << birth.getMonth() << ',' << birth.getDay() << endl;
}
