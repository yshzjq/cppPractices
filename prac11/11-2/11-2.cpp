#include <iostream>
#include <string>

using namespace std;

int main()
{
	char c;

	int cnt = 0;

	while (true)
	{
		cin.get(c);

		if (c == '\n') break;
		else if (c == ' ')
		{
			cnt++;
		}
	}

	cout << cnt;
}