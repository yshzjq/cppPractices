#include <iostream>

int main()
{
	const int minValue = 1;
	const int maxValue = 10;

	int resultValue = 0;

	for (int value = minValue;value<=maxValue;value++)
	{
		resultValue += value;
	}

	std::cout << minValue << "에서 " << maxValue << "까지 더한 결과는 " << resultValue << "입니다.";

	return 0;
}