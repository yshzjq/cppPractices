#include <iostream>
#include <string>

using namespace std;

class Circle {
	int radius; // 원의 반지름 값
	string name; // 원의 이름
public:
	void setCircle(string name, int radius); // 이름과반지름설정
	double getArea();
	string getName();
};

void Circle::setCircle(string name, int radius)
{
	this->name = name;
	this->radius = radius;
}

double Circle::getArea()
{
	return radius * radius * 3.14f;
}

string Circle::getName()
{
	return name;
}

class CircleManager {
	Circle* p; // Circle 배열에 대한 포인터
	int size; // 배열의 크기
	int pidx = 0;
public:
	CircleManager(int size); // size 크기의 배열을 동적 생성. 사용자로부터 입력 완료 
	~CircleManager() { delete[] p; }
	void addCircle(string name, int radius);
	void searchByName(); // 사용자로부터 원의 이름을 입력받아 면적 출력
	void searchByArea(); // 사용자로부터 면적을 입력받아 면적보다 큰 원의 이름 출력 
};

CircleManager::CircleManager(int size)
{
	this->size = size;
	p = new Circle[size];
}

void CircleManager::addCircle(string name, int radius)
{
	p[pidx].setCircle(name, radius);
	pidx++;
}

void CircleManager::searchByName()
{
	string find_name;
	
	cout << "검색하고자 하는 원의 이름 >> ";

	cin >> find_name;

	for (int i = 0; i < size; i++)
	{
		if (find_name == p[i].getName())
		{
			cout << p[i].getName() << "의 면적은 " << p[i].getArea() << '\n';
		}
	}
}

void CircleManager::searchByArea()
{
	int min_area;

	cout << "최소 면적을 정수로 입력하세요 >> ";

	cin >> min_area;

	cout << min_area << "보다 큰 원을 검색합니다.\n";

	for (int i = 0; i < size; i++)
	{
		if (min_area <= p[i].getArea())
		{
			cout << p[i].getName() << "의 면적은 " << p[i].getArea() << ',';
		}
	}
}

int main()
{
	int t;

	cout << "원의 개수 >> ";

	cin >> t;

	CircleManager manager(t);

	for (int i = 0; i < t; i++)
	{
		string circle_name;
		int radius;

		cout << "원 " << i + 1 << "의 이름과 반지름 >> ";

		cin >> circle_name >> radius;

		manager.addCircle(circle_name, radius);
	}

	manager.searchByName();
	manager.searchByArea();


}

