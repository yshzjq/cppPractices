#include <iostream>

using namespace std;

int main()
{
	char password[100];
	char check[100];

	cout << "새 암호를 입력하세요 >>";

	cin >> password;

	cout << "새 암호를 다시 한 번 입력하세요>>";

	cin >> check;

	if (strcmp(password,check) == 0)
	{
		cout << "같습니다";
	}
	else
	{
		cout << "같지 않습니다";
	}
}


