#include <iostream>

using namespace std;

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
	char shape;
public:

	Human(int x,int y,int dis,char shape) : GameObject(x,y,dis) { // 초기위치와 이동거리 설정
		this->shape = shape;
	}

	virtual void move() 
	{
		char command;

		cout << "왼쪽(a), 아래(s), 위여), 오른쪽 (f) >> ";

		cin >> command;
	
		switch (command)
		{
			case 'a': 
			{ 
				x--; 
				break;
			}
			case 'd': 
			{
				x++;
				break;
			}
			case 'w': 
			{
				y++;
				break;
			}
			case 's':
			{
				y--;
				break;
			}
		}
	};
	virtual char getShape() { return shape; }
};

class Field {

	char** field;

	int xsize;
	int ysize;
public:
	Field(int x, int y) 
	{ 
		this->xsize = x;
		this->ysize = y; 

		field = new char*[x];

		for (int i = 0; i < x; i++)
		{
			field[i] = new char[y];
		}

		for (int i = 0; i < x; i++)
		{
			for (int j = 0; j < y; j++)
			{
				field[i][j] = '-';
			}
		}
	}

	void add(GameObject* gameObject)
	{
		field[gameObject->getX()][gameObject->getY()] = gameObject->getShape();
	}

	void move(GameObject* gameObject)
	{
		if(gameObject->getX() == -1)
	}

	void show()
	{
		for (int i = 0; i < x; i++)
		{
			for (int j = 0; j < y; j++)
			{
				cout << field[i][j];
			}
			cout << '\n';
		}
	}
};

int main()
{
	Field field(10, 20);

	GameObject* human = new Human(0, 0, 1, 'H');
	field.add(human);

	field.show();

	while (true)
	{
		human->move();

		field.show();
	}
}