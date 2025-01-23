#include <iostream>
#include <cctype>

#define WIDTH 8

using namespace std;

int main()
{
	cout.setf(ios::left);

	for (int i = 0; i < 4; i++)
	{
		cout.width(WIDTH);
		cout << "dec";

		cout.width(WIDTH);
		cout << "hexa";

		cout.width(WIDTH);
		cout << "char";
	}

	cout << '\n';

	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			cout.width(WIDTH);
			cout << "----";
		}
	}

	cout << '\n';

	for (int i = 0; i < 128; i++)
	{
		cout.setf(ios::dec);
		cout.width(WIDTH);
		cout << i;

		cout.unsetf(ios::dec);
		cout.setf(ios::hex);

		cout.width(WIDTH);
		cout << i;

		cout.unsetf(ios::hex);

		cout.width(WIDTH);

		if (isprint(i) || isgraph(i)) cout << (char)i;
		else cout << '.';

		if (i % 4 == 3) cout << '\n';
	}
}