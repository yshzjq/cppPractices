#include <iostream>
#include <string>
using namespace std;

int main()
{
	string str;

	char findChar = 'a';

	int cnt = 0;

	cout << "문자열 입력>> ";
	getline(cin, str);

	/* (1)
	for (char c : str)
	{
		if (c == findChar) cnt++;
	}
	*/

	/* (2)
	int startIdx = 0;

	while ((startIdx = str.find(findChar,startIdx)) >= 0)
	{
		cnt++;
		startIdx++;
	}
	*/

	cout << "문자 " << findChar << "는 " << cnt << "개 있습니다.";

}

