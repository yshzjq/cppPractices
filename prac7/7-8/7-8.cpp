#include <iostream>	
#include <string>

using namespace std;

class Circle {
	int radius;
public:
	Circle(int radius = 0) { this->radius = radius; }
	void show() { cout << "radius = " << radius << " 인 원" << endl; }

	/*Circle& operator++()
	{
		radius++;
		return *this;
	}

	Circle& operator++(int x)
	{
		Circle tmp = *this;
		radius++;
		return tmp;
	}*/

	friend Circle operator++(Circle& c);
	friend Circle& operator++(Circle& c,int x);
};

Circle operator++(Circle& c)
{
	c.radius++;
	return c;
}

Circle& operator++(Circle& c, int x)
{
	Circle tmp = c;
	c.radius++;
	return tmp;
}


int main()
{
	Circle a(5), b(4);
	++a; // 반지름을 1 증가시킨다.
	b = a++; // 반지름을 1 증가시킨다.
	a.show();
	b.show();
}


