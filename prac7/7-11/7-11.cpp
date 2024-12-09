#include <iostream>	
#include <string>

using namespace std;

class Stack
{
	int* stack;
	int idx = 0;
public:
	Stack() { stack = new int[100]; }

	/*Stack& operator << (int n)
	{
		stack[idx] = n;
		idx++;
		return *this;
	}
	Stack& operator >> (int& n)
	{
		n = stack[idx - 1];
		idx--;
		return *this;
	}
	bool operator !()
	{
		if (idx == 0) return true;
		return false;
	}*/
	friend Stack& operator << (Stack& stack, int n);
	friend Stack& operator >> (Stack& stack, int& n);
	friend bool operator!(Stack& stack);

};

Stack& operator<<(Stack& stack, int n)
{
	stack.stack[stack.idx] = n;
	stack.idx++;
	return stack;
}

Stack& operator>>(Stack& stack, int& n)
{
	n = stack.stack[stack.idx-1];
	stack.idx--;
	return stack;
}

bool operator!(Stack& stack)
{
	if (stack.idx == 0) return true;
	return false;
}


int main()
{
	Stack stack;
	stack << 3 << 5 << 10;
	while (true)
	{
		if (!stack) break;
		int x;
		stack >> x;
		cout << x << ' ';
	}
	cout << endl;
}

