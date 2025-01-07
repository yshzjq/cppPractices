#include <iostream>

using namespace std;

class Circle {
	int radius;
public:
	Circle(int radius = 1) { this->radius = radius; }
	int getRadius() { return radius; }
	
};

template <class T> T bigger(T a, T b) { // 두 개의 매개 변수를 비교하여 큰 값을 리턴
	if (a > b) return a;
	else return b;
};

int bigger(Circle a, Circle b)
{
	if (a.getRadius() > b.getRadius()) return a.getRadius();
	else return b.getRadius();

}

int main()
{
	int a = 20, b = 50, c;
	c = bigger(a, b);
	cout << "20과 50중 큰값은 " << c << endl;
	Circle waffle(10), pizza(20), y;
	y = bigger(waffle, pizza);
	cout << "waffle과 pizza 중큰 것의 반지름은 " << y.getRadius() << endl;
}