#include <iostream>

using namespace std;

class AbstractStack {
public:
	virtual bool push(int n) = 0; // 스택에 n을푸시한다. 스택이 full이면 false 리턴
	virtual bool pop(int& n) = 0; // 스택에서 팝한 정수를 n에 저장하고 스택이 emptyO]면 false 리턴

	virtual int size() = 0; // 현재 스택에 저장된 정수의 개수 리턴
};

class IntStack : public AbstractStack
{
	int idx = 0;

	int capacity;
	int* stack;
public:
	IntStack(int capacity) 
	{ 
		this->capacity = capacity; 
		stack = new int[capacity];
	}

	~IntStack() { delete[] stack; }

	bool push(int n) override
	{
		if (idx == capacity) return false;
		stack[idx++] = n;
		return true;
	}

	bool pop(int& n) override
	{
		if (idx == 0)
		{
			n = -1;
			return false;
		}
		n = stack[--idx];
		return true;
	}

	int size() { return idx; }


};


int main()
{
	IntStack stack(5);

	for (int i = 0; i < 6; i++)
	{
		cout << stack.push(i * 2);

		cout << "  " << stack.size() << '\n';
	}

	

	int n;

	for (int i = 0; i < 6; i++)
	{
		cout << stack.pop(n) << "  ";
		cout << n << '\n';
	}

	cout << stack.size();

	return 0;
}