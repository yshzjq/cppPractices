#include <iostream>

using namespace std;

int main()
{
	char str[100];

	cin >> str;

	for (int i = 0; i < strlen(str); i++)
	{
		for (int j = 0; j <= i; j++)
		{
			cout << str[j];
		}
		cout << '\n';
	}
}