#include <iostream>
#include "Calculator.h"
using namespace std;

int main() {
	int num1, num2;
	char c;

	Add a;
	Sub s;
	Mul m;
	Div d;
	
	while (true)
	{
		cout << "두 정수와 연산자를 입력하세요>>";
		cin >> num1 >> num2 >> c;

		switch (c)
		{
		case '+':
			a.setValue(num1, num2);
			cout << a.calculate() << '\n';
			break;
		case '-':
			s.setValue(num1, num2);
			cout << s.calculate() << '\n';
			break;
		case '*':
			m.setValue(num1, num2);
			cout << m.calculate() << '\n';
			break;
		case '/':
			d.setValue(num1, num2);
			cout << d.calculate() << '\n';
			break;

		}
	}
}

