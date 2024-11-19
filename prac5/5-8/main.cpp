#include <iostream>
#include <string>

using namespace std;

class MyIntStack {
	int* p; // 스택 메모리로 사용할 포인터
	int size; //스택의 최대 크기
	int tos; // 스택의 탑을 가리키는 인덱스
public:
	MyIntStack(int size);
	MyIntStack(const MyIntStack& s); // 복사생성자 
	~MyIntStack() { delete[] p; }
	bool push(int n); // 정수 n을 스택에푸시한다.
	// 스택이 꽉 차 있으면 false를, 아니면 true 리턴 
	bool pop(int& n); // 스택의 탑에 있는 값을 n에 팝한다.
	// 만일 스택이 비어 있으면 false를、아니면 true 리턴
};

MyIntStack::MyIntStack(int size)
{
	this->size = size;
	p = new int[size];
	tos = 0;
}

MyIntStack::MyIntStack(const MyIntStack& s)
{
	this->size = s.size;
	this->tos = s.tos;
	this->p = new int[s.size];

	if (s.tos >= 1)
	{
		for (int i = 0; i < this->tos; i++)
		{
			this->p[i] = s.p[i];
		}
	}
}

bool MyIntStack::push(int n)
{
	if (tos >= 10)return false;
	p[tos] = n;
	tos++;
	return true;
}

bool MyIntStack::pop(int& n)
{
	if (tos <= 0)return false;

	n = p[tos - 1];
	p[tos-1] = 0;
	tos--;
	return true;
}

int main() {
	MyIntStack a(10);
	a.push(10);
	a.push(20);
	MyIntStack b = a; // 복사생성
	b.push(30);
	int n;
	a.pop(n); // 스택 a 팝
	cout << "스택 a에서 팝한 값 " << n << endl;
	b.pop(n); // 스택 b 팝
	cout << "스택 b에서 팝한 값 " << n << endl; 
}

