#include <iostream>

using namespace std;

int main()
{
	int menuidx, inbun;

	char menu[3][100] = { "짬뽕","짜장","군만두" };

	cout << "*****  승리장에 오신 것을 환영합니다.  *****\n";

	while (true)
	{
		cout << "짬뽕:1, 짜장:2, 군만두:3, 종료:4>>  ";
		cin >> menuidx;

		if (menuidx == 4) break;

		if (menuidx > size(menu) || menuidx < 1)
		{
			cout << "다시 주문하세요!!\n";
			continue;
		}
		

		cout << "몇인분?";
		cin >> inbun;

		cout << menu[menuidx-1] << " " << inbun << "인분 나왔습니다.\n";

	}

	cout << "오늘 영업 끝났습니다.";
	return 0;
}
