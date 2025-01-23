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
	cout << "반지름 >> ";
	ins >> radius;


	string name;
	cout << "이름 >> ";
	ins >> name;

	c.radius = radius;
	c.name = name;

	return ins;
}

ostream& operator<<(ostream& stream, Circle& c)
{
	cout << "(반지름" << c.radius << "인 " << c.name << ")";


	return stream;
}


int main()
{
	Circle d, w;
	cin >> d >> w; // 키보드 입력을 받아 객체 d와 w를 완성
	cout << d << w << endl; // 객체 d, w 출력
}

