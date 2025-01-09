#include <iostream>
#include <string>
#include <map>

using namespace std;

int main()
{
	cout << "***** 점수관리 프로그램 HIGH SCORE을 시작합니다. *****\n";

	map<string, int> m;

	while (true)
	{
		int n;
		cout << "입력:1, 조회:2, 종료:3 >> ";
		cin >> n;

		string name;
		int score;


		if (n == 1)
		{
			cout << "이름과 점수>> ";
			cin >> name >> score;

			m[name] = score;
		}
		else if (n == 2)
		{
			cout << "이름 >> ";
			cin >> name;

			if(m[name] != 0) cout << name << "의 점수는 " << m[name] << '\n';
		}
		else if (n == 3)
		{
			cout << "프로그램을 종료합니다...";
			break;
		}

	}
}