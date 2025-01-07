#include <iostream>

using namespace std;

template <class T> T* concat(T a[], int sizea, T b[], int sizeb)
{
	T* result = new T[sizea + sizeb];
	for (int i = 0; i < sizea; i++) result[i] = a[i];

	for (int i = sizea; i < sizea + sizeb; i++) result[i] = b[i-sizea];

	return result;
}

int main()
{
	int a[] = { 1,100,5,20,40 };
	int b[] = { 6,800,10,20,40 };

	/*char a[] = { 'a', 'b', 'c', 'd' , 'e'};
	char b[] = {  'c', 'd' ,'a', 'b', 'e'};*/

	auto* c = concat(a, 5, b, 5);

	for (int i = 0; i < 10; i++)
	{
		cout << c[i] << " ";
	}

	delete[] c;
}