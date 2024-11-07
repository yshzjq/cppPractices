#include <iostream>

using namespace std;

int main()
{
	char str[100];

	while (true)
	{
		cout << "종료하고싶으면 yes를 입력하세요>>";
		cin.getline(str, 100);

		if (strcmp(str, "yes") == 0) break;
	}

	cout << "종료합니다...";
}