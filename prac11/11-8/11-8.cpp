#include <iostream>

using namespace std;

class Circle
{
	string name;
	int radius;
public:
	Circle(int radius = 1, string name = "") {
		this->radius = radius; this->name = name;
	}

	friend istream& operator >> (istream& ins, Circle& c);
	friend ostream& operator << (ostream& stream,Circle& c);
};

istream& operator>>(istream& ins, Circle& c)
{
	int radius;
	cout << "������ >> ";
	ins >> radius;


	string name;
	cout << "�̸� >> ";
	ins >> name;

	c.radius = radius;
	c.name = name;

	return ins;
}

ostream& operator<<(ostream& stream, Circle& c)
{
	cout << "(������" << c.radius << "�� " << c.name << ")";


	return stream;
}


int main()
{
	Circle d, w;
	cin >> d >> w; // Ű���� �Է��� �޾� ��ü d�� w�� �ϼ�
	cout << d << w << endl; // ��ü d, w ���
}

