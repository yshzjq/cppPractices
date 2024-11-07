#include <iostream>
using namespace std;

int main()
{
	char str[10000];
	int starcnt[26] = { 0 };

	int sum = 0;
	
	cout << "영문 텍스트를 입력하세요. 히스토그램을 그립니다.\n텍스트의 끝은; 입니다. 10000개까지 가능합니다.\n";

	cin.getline(str, 10000, ';');

	for (char c = 'a'; c <= 'z'; c++)
	{
		int ccnt = 0;
	
		for (int i = 0; i < strlen(str); i++)
		{
			if (tolower(str[i]) == c) ccnt++;
		}

		sum += ccnt;
		starcnt[c - 'a'] = ccnt;
	}

	cout << "총 알파벳 수 " << sum << "\n\n";

	for (char c = 'a'; c <= 'z'; c++)
	{
		cout << c << " (" << starcnt[c - 'a'] << ")   : ";

		for (int i = 0; i < starcnt[c - 'a']; i++)
		{
			cout << '*';
		}

		cout << '\n';
	}
}




