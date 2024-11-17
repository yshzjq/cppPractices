#include <iostream>
#include <string>

using namespace std;

class Circle {
	int radius; // 원의 반지름 값 
public:
	void setRadius(int radius); // 반지름을설정한다.
	double getArea(); // 면적을 리턴한다
};

void Circle::setRadius(int radius)
{
	this->radius = radius;
}

double Circle::getArea()
{
	return radius * radius * 3.14f;
}

int main()
{
	int circnt;

	cout << "원의 개수 >> ";

	cin >> circnt;

	Circle* circle = new Circle[circnt];

	int result = 0;

	for (int i = 0; i < circnt; i++)
	{
		int radius;

		cout << "원 " << i + 1 << "의 반지름 >> ";

		cin >> radius;

		circle[i].setRadius(radius);

		if (circle[i].getArea() > 100.f) result++;
	}

	cout << "면적이 100보다 큰 원은 " << result << "개 입니다.";

	delete[] circle;

	return 0;
}
