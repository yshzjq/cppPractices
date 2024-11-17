#include <iostream>
#include <string>

using namespace std;

int main()
{
	string str;

	cout << "아래에 한 줄을 입력하세요.(exit를 입력하면 종료합니다.)\n";

	while (true)
	{
		cout << ">>";
		getline(cin, str);

		if (str == "exit") break;

		int length = str.size() - 1;

		do
		{
			cout << str[length];
		} 
		while (length--);

		cout << '\n';

	}
	return 0;
}
