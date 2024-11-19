#include <iostream>
#include <string>

using namespace std;

class Circle
{
	int radius;
public:
	Circle(int radius) { this->radius = radius; }
	void swap(Circle& a, Circle& b);
	void getRadius() { cout << radius << ' '; }
};

void Circle::swap(Circle& a, Circle& b)
{
	Circle tmp = a;
	a = b;
	b = tmp;
}

int main()
{
	Circle a(10), b(20);

	cout << "바꾸기 전\n";

	a.getRadius();
	b.getRadius();

	swap(a, b);

	cout << "\n바꾸기 후\n";

	a.getRadius();
	b.getRadius();

}

