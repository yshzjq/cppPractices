#include <iostream>
using namespace std;

class Tower
{
	int meter;
public:
	Tower();
	Tower(int _meter);

	int getHeight();
};

Tower::Tower()
{
	meter = 1;
}

Tower::Tower(int _meter)
{
	meter = _meter;
}

int Tower::getHeight()
{
	return meter;
}

int main()
{
	Tower myTower; // 1미터
	Tower seoulTower(100);
	cout << "높이는 " << myTower.getHeight() << "미터" << endl;
	cout << "높이는 " << seoulTower.getHeight() << "미터" << endl;
}
