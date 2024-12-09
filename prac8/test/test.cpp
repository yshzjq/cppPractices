#include <iostream>
#include <string>

using namespace std;

class Point { // 2차원 평면에서 한 점을 표현하는 클래스 Point 선언
	int x,y; //한점 (x,y) 좌표값
public:
	//Point(Point& p) { x = p.x, y = p.y; }
	void set(int x, int y) { this->x = x; this->y = y; }
	void showPoint() {
		cout << "(" << x << "," << y << ")" << endl;
	}
};

class ColorPoint : private Point { // 2차원 평면에서 컬러 점을 표현하는 클래스
	string color;// 점의 색 표현
public:
	void setColor(string color) { this->color = color; }
	void showColorPoint();
};

void ColorPoint::showColorPoint()
{
	cout << color << ":";
	showPoint();
}


int main()
{
	Point p;
	ColorPoint* pp;

	p.set(3, 5);

	pp = (ColorPoint*)&p;

	pp->setColor("what");
	pp->showColorPoint();
}

