#include <iostream>

using namespace std;

int main()
{
	char coffee[100];
	int cnt;

	int sum = 0;

	int price = 0;

	cout << "에스프레소 2000원, 아메리카노 2300원, 카푸치노 2500원입니다.\n";

	while (sum <= 20000)
	{
		cout << "주문>>";
		cin >> coffee >> cnt;

		if (strcmp(coffee, "에스프레소") == 0)
		{
			price = 2000;
			sum += 2000 * cnt;
		}
		else if (strcmp(coffee, "아메리카노") == 0)
		{
			price = 2300;
			sum += 2300 * cnt;
		}
		else if (strcmp(coffee, "카푸치노") == 0)
		{
			price = 2500;
			sum += 2500 * cnt;
		}

		cout << price * cnt << "원입니다. 맛있게 드세요\n";

	}

	cout << "오늘 "<< sum << "원을 판매하여 카페를 닫습니다. 내일봐요~";

	return 0;
}
