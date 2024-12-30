#include <iostream>
#include <random>

using namespace std;

static int xSize = 10;
static int ySize = 20;

class GameObject { // 추상클래스
protected:
	int distance; // 한 번 이동 거리
	int x, y; // 현재 위치
public:
	GameObject(int startX, int startY, int distance) { // 초기위치와 이동거리 설정
		this->x = startX; this->y = startY;
		this->distance = distance;
	}
	virtual ~GameObject() {}; // 가상소열자
	virtual void move() = 0; // 이동한 후 새로운 위치로 x, 노 변경
	virtual char getShape() = 0; // 객체의 모양을 나타내는 문자 리턴
	int getX() { return x; }
	int getY() { return y; }
	bool collide(GameObject* p) { // 이 객체가 객체 p와 충돌했으면 true 리턴
		if (this->x == p->getX() && this->y == p->getY())
			return true;
		else
			return false;
	}
};

class Human : public GameObject
{
public:
	Human(int startX, int startY, int distance) : GameObject(startX, startY, distance) {};

	void move() override
	{
		char command;

		cout << "왼쪽(a), 아래(s), 위(d), 오른쪽(f) >> ";

		cin >> command;

		if (command == 'a') {
			if (y > 0) y -= distance;
		}
		if (command == 's') {
			if (xSize - 1 > x) x += distance;
		}
		if (command == 'd') {
			if (ySize - 1 > y) y += distance;
		}
		if (command == 'w') {
			if (x > 0) x -= distance;
		}

		cout << '\n';
	}

	char getShape() { return 'H'; }
};


class Monster : public GameObject
{
public:
	Monster(int startX, int startY, int distance) : GameObject(startX, startY, distance) {};

	void move() override
	{
		random_device rd;
		mt19937 gen(rd());
		uniform_int_distribution<> dis(0, 3);

		switch (dis(gen))
		{
			case 0: 
			{
				y -= distance;
				break;
			}
			case 1:
			{
				x += distance;
				break;
			}
			case 2: {
				y += distance;
				break;
			}
			case 3: {
				x -= distance;
				break;
			}
		}

		if (y < 0) y = 0;
		else if (y >= ySize) y = ySize - 1;

		if (x < 0) x = 0;
		else if (x >= xSize) x = xSize - 1;
	}

	char getShape() { return 'M'; }
};

class Food : public GameObject
{
public:
	Food(int startX, int startY, int distance) : GameObject(startX, startY, distance) {};

	void move() override { return; }
	char getShape() { return '@'; }
};

int main()
{
	char** field;

	Human* human = new Human(0, 0, 1);
	Monster* monster = new Monster(5, 5, 2);
	Food* food = new Food(9, 9, 0);

	field = new char* [ySize];

	for (int i = 0; i < xSize; i++)
	{
		field[i] = new char[xSize];
	}

	for (int i = 0; i < xSize; i++)
	{
		for (int j = 0; j < ySize; j++)
		{
			field[i][j] = '-';
		}
	}

	field[human->getX()][human->getY()] = human->getShape();
	field[monster->getX()][monster->getY()] = monster->getShape();
	field[food->getX()][food->getY()] = food->getShape();


	cout << "** Human의 Food 먹기 게임을 시작합니다. ** \n\n";

	while (true)
	{
		for (int i = 0; i < xSize; i++)
		{
			for (int j = 0; j < ySize; j++)
			{
				cout << field[i][j];
			}
			cout << '\n';
		}

		for (int i = 0; i < xSize; i++)
		{
			for (int j = 0; j < ySize; j++)
			{
				field[i][j] = '-';
			}
		}

		human->move();
		field[human->getX()][human->getY()] = human->getShape();

		monster->move();
		field[monster->getX()][monster->getY()] = monster->getShape();

		if (human->collide(food))
		{
			for (int i = 0; i < xSize; i++)
			{
				for (int j = 0; j < ySize; j++)
				{
					cout << field[i][j];
				}
				cout << '\n';
			}
			cout << "Human is Winner!!\n";
			break;
		}

		if (monster->collide(human) || monster->collide(food))
		{
			for (int i = 0; i < xSize; i++)
			{
				for (int j = 0; j < ySize; j++)
				{
					cout << field[i][j];
				}
				cout << '\n';
			}
			cout << "Monster is Winner!!\n";
			break;
		}

		

		field[food->getX()][food->getY()] = food->getShape();
		field[monster->getX()][monster->getY()] = monster->getShape();
		field[human->getX()][human->getY()] = human->getShape();

	}

	delete[] field;

	delete food;
	delete monster;
	delete human;
}