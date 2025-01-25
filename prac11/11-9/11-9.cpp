#include <iostream>
#include <string>

using namespace std;

class Phone { // ��ȭ ��ȣ��ǥ���ϴ� Ŭ����
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
	cout << "�̸�:";
	getline(cin, phone.name);
	cout << "��ȭ��ȣ:";
	getline(cin, phone.telnum);
	cout << "�ּ�:";
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
	cin >> girl >> boy; // ��ȭ ��ȣ�� Ű����κ��� �д´�.
	cout << girl << endl << boy << endl; // ��ȭ��ȣ������Ѵ�
}

