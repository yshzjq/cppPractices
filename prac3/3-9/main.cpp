#include <iostream>
using namespace std;

class Oval
{
	int width;
	int height;
public:
	Oval();
	Oval(int _width, int _height);

	~Oval();

	int getWidth();
	int getHeight();

	void set(int _width, int _height);
	void show();

};

Oval::Oval()
{
	width = 1;
	height = 1;
}

Oval::Oval(int _width, int _height)
{
	width = _width;
	height = _height;
}

Oval::~Oval()
{
	cout << "Oval ¼Ò¸ê : width = " << width << ", height = " << height << endl;
}

int Oval::getWidth()
{
	return width;
}

int Oval::getHeight()
{
	return height;
}

void Oval::set(int _width, int _height)
{
	width = _width;
	height = _height;
}

void Oval::show()
{
	cout << width << ", " << height << endl;
}

int main() {
	Oval a,b(3, 4);
	a.set(10, 20);
	a.show();
	cout << b.getWidth() << "," << b.getHeight() << endl;
}


