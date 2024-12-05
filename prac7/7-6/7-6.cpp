#include <iostream>	
#include <string>

using namespace std;

class Matrix
{
	int x1, y1, x2, y2;
public:
	Matrix(int x1, int y1, int x2, int y2) { this->x1 = x1, this->y1 = y1, this->x2 = x2, this->y2 = y2; }
	Matrix() : Matrix(0, 0, 0, 0) {};

	friend Matrix operator+(Matrix m1, Matrix m2);
	friend Matrix operator+=(Matrix& m1, Matrix m2);
	friend bool operator==(Matrix m1, Matrix m2);

	/*Matrix operator+(Matrix m)
	{
		return Matrix(x1 + m.x1, y1 + m.y1, x2 + m.x2, y2 + m.y2);
	}

	Matrix operator+=(Matrix m)
	{
		x1 += m.x1;
		x2 += m.x2;
		y1 += m.y1;
		y2 += m.y2;
		return *this;
	}

	bool operator==(Matrix m)
	{
		if (x1 == m.x1 && x2 == m.x2 && y1 == m.y1 && y2 == m.y2) return true;
		return false;
	}*/

	void show()
	{
		cout << "Matrix = { " << x1 << ' ' << y1 << ' ' << x2 << ' ' << y2 << " }\n";
	}
};

Matrix operator+(Matrix m1, Matrix m2)
{
	return Matrix(m1.x1 + m2.x1, m1.y1 + m2.y1, m1.x2 + m2.x2, m1.y2 + m2.y2);
}

Matrix operator+=(Matrix& m1, Matrix m2)
{
	m1.x1 += m2.x1;
	m1.y1 += m2.y1;
	m1.x2 += m2.x2;
	m1.y2 += m2.y2;
	return m1;
}

bool operator==(Matrix m1, Matrix m2)
{
	if (m1.x1 == m2.x1 && m1.y1 == m2.y1 && m1.x2 == m2.x2 && m1.y2 == m2.y2) return true;
	return false;
}



int main() {
	Matrix a( 1, 2, 3, 4), b( 2, 3, 4, 5), c;
	c = a + b;
	a += b;
	a.show(); b.show(); c.show();
	if (a == c)
		cout << "a and c are the same" << endl;
}

