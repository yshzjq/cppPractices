#include <iostream>
#include <string>

using namespace std;

int main()
{
	int cnt = 0;

	while (true)
	{
		char c = cin.get();
		if (c == 'a')
		{
			cnt++;
		}
		else if(c == '\n')
		{
			break;
		}
	}

	cout << cnt;

}