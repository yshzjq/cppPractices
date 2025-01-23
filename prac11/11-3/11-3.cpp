#include <iostream>
#include <string>

using namespace std;

int main()
{
	char c[100];

	while (true)
	{
			cin.ignore(100, ';');

			cin.get(c, 100);

			if (cin.eof() == true) break;

			cout << c << '\n';
	}
}