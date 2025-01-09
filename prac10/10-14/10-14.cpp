#include <iostream>
#include <string>
#include <map>

using namespace std;

int main()
{
	map<string, string> PassWord_Manager;

	cout << "***** 암호 관리 프로그램 WHO를 시작합니다 *****\n";

	while (true)
	{
		cout << "삽입:1, 검사:2, 종료:3>> ";
		int n;
		cin >> n;

		string name;
		string password;

		if (n == 3)
		{
			cout << "프로그램을 종료합니다...\n";
			return 0;
		}
		else if (n == 1)
		{
			cout << "이름 암호>> ";

			cin >> name;
			cin >> password;

			PassWord_Manager[name] = password;
		}
		else if (n == 2)
		{
			cout << "이름? ";
			cin >> name;

			while (true)
			{
				cout << "암호?\n";
				cin >> password;

				if (PassWord_Manager[name] == password)
				{
					cout << "통과!!\n";
					break;
				}
				else
				{
					cout << "실패~~";
				}
			}
		}
	}
	

}