#include <iostream>
#include <string>

using namespace std;

int main()
{
	char c;

	while (true)
	{
		while (true)
		{
			cin.get(c);

			if (c == ';')
			{
				cout << '\n';
				break;
			}

			cout << c;
		}
		cin.ignore(numeric_limits<streamsize>::max(),'\n');

	}
	
}