﻿#include <iostream>
#include <string>

using namespace std;

class Person {
	string name;
public:
	Person() {};
	Person(string name) { this->name = name; }
	string getName() { return name; }
	void setName(string name) { this->name = name; }
};

class Family {
	Person* p; // Person 배열 포인터
	string family_name;
	int size; // Person 배열의크기. 가족 구성원 수
public:
	Family(string name, int size); // size 개수만큼 Person 배열 동적 생성
	void show(); // 모든 가족 구성원 출력〜Family();
	void setName(int num,string name);
};

Family::Family(string name, int size)
{
	p = new Person[size];
	this->size = size;
	family_name = name;
}

void Family::show()
{
	cout << p->getName() << "가족은 다음과 같이 " << size << "명입니다.\n";

	for (int i = 0; i < size; i++)
	{
		cout << p[i].getName() << "    ";
	}
}

void Family::setName(int num, string name)
{
	p[num].setName(name);
}

int main()
{
	Family* simpson = new Family("Simpson",3); // 3명으로구성된 Simpson 가족

	simpson->setName(0, "Mr. Simpson");
	simpson->setName(1, "Mrs. Simpson");
	simpson->setName(2, "Bart Simpson");

	simpson->show();

	delete simpson;
}

