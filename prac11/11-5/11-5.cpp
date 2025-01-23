#include <iostream>
#include <string>
using namespace std;
int main() 
{
	string cmd;

	cout << "getline(cin, cmd, '\n')로 문자열을 읽습니다." << endl;

	while (true) 
	{
		cout << "종료하려면 exit을 입력하세요 >>";
		getline(cin, cmd, '\n'); // 79개까지의문자읽음

		if (cmd == "exit") {
			cout << "프로그램을종료합니다....";
			return 0;
		}
		else cin.ignore(1); // 버퍼에 남아있는 <Enter> 키 (1 \n*) 제거
	}
}