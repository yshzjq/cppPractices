#include <iostream>

using namespace std;

int main()
{
	double value;
	double max;

	cout << "5 개의 실수를 입력하라>>";

	cin >> value;
	max = value;
	
	for (int i = 0; i < 4; i++)
	{
		cin >> value;
		
		if (max < value) max = value;
	}

	cout << "제일 큰 수 = " << max;

}

