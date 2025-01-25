#include <iostream>
#include <string>

using namespace std;

class Phone { // 전화 번호를표현하는 클래스
	string name;
	string telnum;
	string address;
public:
	Phone(string name = "", string telnum = "", string address="") {
		this->name = name;
		this->telnum = telnum;
		this->address = address;
	}

	friend istream& operator >> (istream& ism, Phone& phone);
	friend ostream& operator << (ostream& osm, Phone& phone);

};

istream& operator>>(istream& ism, Phone& phone)
{
	cout << "이름:";
	getline(cin, phone.name);
	cout << "전화번호:";
	getline(cin, phone.telnum);
	cout << "주소:";
	getline(cin, phone.address);

	return ism;
}

ostream& operator<<(ostream& osm, Phone& phone)
{
	cout << "(" << phone.name << ',' << phone.telnum << ',' << phone.address << ")";

	return osm;
}


int main()
{
	Phone girl, boy;
	cin >> girl >> boy; // 전화 번호를 키보드로부터 읽는다.
	cout << girl << endl << boy << endl; // 전화번호를출력한다
}

