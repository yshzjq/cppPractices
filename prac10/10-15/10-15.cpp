#include <iostream>
#include <string>
#include <vector>
#include <iterator>

using namespace std;


class Circle {
	string name; // 이름
	int radius; // 반지름
public:
	Circle(int radius, string name) {
		this->radius = radius; this->name = name;
	}
	double getArea() { return 3.14 * radius * radius; }
	string getName() { return name; }
};

int main()
{
	vector<Circle*> cm;

	cout << "원을 삽입하고 삭제하는 프로그램입니다.\n";

	while (true)
	{
		int n;
		cout << "삽입:1, 삭제:2, 모두보기:3. 종료:4 >> ";
		cin >> n;

		string name;
		int radius;

		if (n == 4)
		{
			break;
		}
		else if (n == 1)
		{
			cout << "생성하고자 하는 원의 반지름과 이름은 >> ";
			cin >> radius >> name;
			cm.push_back(new Circle(radius, name));
		}
		else if (n == 3)
		{
			for (int i = 0; i < cm.size(); i++)
			{
				cout << cm[i]->getName() << ' ' << cm[i]->getArea() << '\n';
			}
			cout << '\n';
		}
		else if (n == 2)
		{
			cout << "삭제하고자 하는 원의 이름은 >> ";
			cin >> name;

			vector<Circle*>::iterator it;

			for (it = cm.begin(); it < cm.end();)
			{
				if ((*it)->getName() == name)
				{
					it = cm.erase(it);
				}
				else it++;
			}
		}

	}
}