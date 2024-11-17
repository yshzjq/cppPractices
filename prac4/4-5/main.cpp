#include <iostream>
#include <string>
#include <random>
using namespace std;

int main()
{
	// 시드 
	random_device rd;

	mt19937 gen(rd());
	uniform_int_distribution<> dis(0, RAND_MAX);

	string str;

	cout << "아래에 한 줄을 입력하세요.(exit를 입력하면 종료합니다.)\n";

	while (true)
	{
		cout << ">>";
		getline(cin,str);

		if (str == "exit") break;

		char randalpha = dis(gen) % 26 + 'a';
		int randIndex;

		while (true)
		{
			randIndex = dis(gen) % str.size();
			if (isalpha(str[randIndex])) break;
		}
		
		str[randIndex] = randalpha;

		cout << str << '\n';

	}
	return 0;
}
