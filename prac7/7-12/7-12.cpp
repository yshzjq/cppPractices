#include <iostream>	
#include <string>

using namespace std;

class SortedArray {
	int size; // 현재 배열의 크기
	int* p; // 정수 배열에 대한 포인터
	void sort(); // 정수 배열을 오름차순으로 정렬
public:
	SortedArray(); // 다는 NULL로 size는 0으로초기화
	SortedArray(SortedArray& src); // 복사생성자
	SortedArray(int p[], int size); // 생성자. 정수 배열과크기를 전달받음
	~SortedArray() { delete[] p; } // 소멸자
	SortedArray operator + (SortedArray& op2); // 현재 배열에 op2 배열 추가
	SortedArray& operator = (const SortedArray& op2); // 현재 배열에 op2 배열 복사
	void show(); // 배열의 원소 출력
};

SortedArray::SortedArray()
{
	size = 0;
	p = new int[100];
}

SortedArray::SortedArray(SortedArray& src)
{
	size = src.size;
	p = new int[100];

	for (int i = 0; i < size; i++)
	{
		p[i] = src.p[i];
	}
}

SortedArray::SortedArray(int p[], int size)
{
	this->size = size;
	this->p = new int[100];

	for (int i = 0; i < size; i++)
	{
		this->p[i] = p[i];
	}

	for (int i = 0; i < this->size-1; i++)
	{
		for (int j = i + 1; j < this->size; j++)
		{
			if (this->p[i] > this->p[j])
			{
				int tmp = this->p[i];
				this->p[i] = this->p[j];
				this->p[j] = tmp;
			}
		}
	}
}

SortedArray SortedArray::operator+(SortedArray& op2)
{
	int n[100];
	for (int i = 0; i < size; i++)
	{
		n[i] = p[i];
	}

	for (int i = size; i < size + op2.size; i++)
	{
		n[i] = op2.p[i - size];
	}

	for (int i = 0; i < size + op2.size - 1; i++)
	{
		for (int j = i + 1; j < size + op2.size; j++)
		{
			if (n[i] < n[j])
			{
				int tmp = n[i];
				n[i] = n[j];
				n[j] = tmp;
			}
		}
	}

	SortedArray tmp(n, size + op2.size);
	return tmp;
	
}

SortedArray& SortedArray::operator=(const SortedArray& op2)
{
	size = op2.size;
	for (int i = 0; i < op2.size; i++)
	{
		p[i] = op2.p[i];
	}
	return *this;
}

void SortedArray::show()
{
	cout << "배열 출력 : ";
	for (int i = 0; i < size; i++)
	{
		cout << p[i] << ' ';
	}
	cout << '\n';
}



int main() {
	int n[] = { 2, 20, 6 };
	int m[] = { 10, 7, 8, 30 };
	SortedArray a(n, 3), b(m, 4), c;
	c = a + b; // +3 = 연산자 작성 필요
	// + 연산자가 SortedArray 객체를 리턴하므로 복사 생성자 필요
	a.show();
	b.show();
	c.show();
}

