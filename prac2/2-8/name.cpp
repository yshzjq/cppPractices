#include <iostream>

using namespace std;

int main()
{
	char str[5][100];

	char max[100];

	int size = 0;

	cout << "5 명의 이름을 ';' 으로 구분하여 입력하세요\n>>";

	for (int i = 0; i < 5; i++)
	{
		cin.getline(str[i], 100,';');

		if (size <= strlen(str[i]))
		{
			size = strlen(str[i]);
			strcpy_s(max, str[i]);
		};
	}

	for (int i = 0; i < 5; i++)
	{
		cout << i << " : " << str[i] << '\n';
		
	}

	cout << "가장 긴 이름은 " << max;
}