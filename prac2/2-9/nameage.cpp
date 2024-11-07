#include <iostream>

using namespace std;

int main()
{
	char name[100];
	char place[100];
	int age;

	cout << "이름은?";
	cin.getline(name, 100);
	cout << "주소는?";
	cin.getline(place, 100);
	cout << "나이는?";
	cin >> age;

	cout << name << ", " << place << ", " << age << "세";
}