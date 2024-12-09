#include <iostream>	
#include <string>

using namespace std;

class Color
{
	int R, G, B;
public:
	Color(int R, int G, int B) { this->R = R, this->G = G, this->B = B; }
	Color() : Color(0, 0, 0) {};

	Color operator+ (Color color2);
	friend bool operator==(Color color1, Color color2);

	void show() { cout << R << ' ' << G << ' ' << B << '\n'; }
};

Color Color::operator+(Color color2)
{
	Color color(this->R + color2.R, this->G + color2.G, this->B + color2.B);
	return color;
}

bool operator==(Color color1, Color color2)
{
	if (color1.R == color2.R && color1.G == color2.G && color1.B == color2.B) return true;
	return false;
}


int main() {
	Color red(255, 0, 0), blue(0, 0, 255), c;
	c.show();
	c = red + blue;
	c.show(); // 색 값출력

	Color fuchsia(255, 0, 255);
	if (c == fuchsia) 
		cout << "보라색 맞음";
	else
		cout << "보라색아님";
}

