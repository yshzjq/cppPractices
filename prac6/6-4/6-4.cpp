#include <iostream>

using namespace std;

class MyVector {
	int* mem;
	int size;
public:
	MyVector();
	MyVector(int n, int val);
	~MyVector() { delete[] mem; }

	void view(int index);
};

MyVector::MyVector() {
	mem = new int[100];
	size = 100;
	for (int i = 0; i < size; i++) mem[i] = 0;
}

MyVector::MyVector(int n = 100, int val = 0) {
	mem = new int[n];
	size = n;
	for (int i = 0; i < size; i++) mem[i] = val;
}

void MyVector::view(int index)
{
	cout << mem[index] << '\n';
}

int main()
{
	MyVector vector(100,5);

	vector.view(5);
}