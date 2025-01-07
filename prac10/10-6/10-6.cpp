#include <iostream>

using namespace std;

template<class T> T* remove(T src[], int sizeSrc, T minus[], int sizeMinus, int& retSize)
{
	T* tmp = new T[sizeSrc];

	int size = 0;

	for (int i = 0; i < sizeSrc; ++i)
	{
		int j;

		for (j = 0; j < sizeMinus; ++j)
		{
			if (src[i] == minus[j])
			{
				break;
			}
		}

		if (sizeMinus == j) {
			tmp[size] = src[i];
			size++;
		}


	}

	T* result = new T[size];

	for (int i = 0; i < size; i++)
	{
		result[i] = tmp[i];
	}

	retSize = size;

	delete[] tmp;

	return result;
}

int main()
{
	/*int a[] = { 1,100,5,20,40 };
	int b[] = { 6,800,10,20,40 };*/
	char a[] = { '1','a','b','2','4' };
	char b[] = { '6','b','1','2','4' };

	int size;

	auto* c = remove(a, 5, b, 5, size);

	for (int i = 0; i < size; i++)
	{
		cout << c[i] << ' ';
	}

}