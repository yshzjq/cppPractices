#include <iostream>
using namespace std;

int main()
{
	char str[100];
	char val[100];

	int idx = 0;

	int a, b, result;

	char c;

	while (true)
	{
		cout << "? ";
		cin.getline(str,100);

		for (int i = idx; i < strlen(str); i++)
		{
			if (str[i] == ' ')
			{
				a = atoi(val);
				c = str[i + 1];
				idx = i + 3;

				break;
			}
			else
			{
				val[i] = str[i];
			}
		}


		strcpy_s(val, "");

		for (int i = idx; i < strlen(str); i++)
		{
			val[i - idx] = str[i];
		}

		b = atoi(val);

		switch (c)
		{
		case '+':
			result = a + b;
			break;
		case '-':
			result = a - b;
			break;
		case '*':
			result = a * b;
			break;
		case '/':
			result = a / b;
			break;
		case '%':
			result = a % b;
			break;
		default:
			break;
		}
		cout << a << ' ' << c << ' ' << b << " = " << result << '\n';

		idx = 0;
		strcpy_s(val, "");

	}
}
