#include <iostream>	
#include <vector>	
#include <iterator>
#include <random>

using namespace std;

class Nation
{
	string nation;
	string capital;
public:
	Nation(string nation, string capital)
	{
		this->nation = nation;
		this->capital = capital;
	}

	string getNation() { return nation; }
	string getCapital() { return capital; }
};

int main()
{
	cout << "***** 나라의 수도 맞추기 게임을 시작합니다. *****\n";

	vector<Nation> v;


	//초기 나라 입력들
	string nations[] = { "미국", "가나"};
	string capitals[] = { "와싱턴", "아크라"};

	random_device rd;
	mt19937 gen(rd());
	

	int num = 0;
	for (string nation : nations)
	{
		auto a = v.begin();

		for ( ; a < v.end(); ++a)
		{
			if (nation == a->getNation())
			{
				break;
			}
		}

		if (v.size() == 0 || a == v.end())
		{
			v.push_back(Nation(nations[num], capitals[num]));
		}
		num++;
	}

	while (true)
	{
		int n;
		cout << "정보 입력: 1, 퀴즈: 2, 종료: 3 >> ";
		cin >> n;

		if (n == 3) break;
		else if (n == 1)
		{
			cout << "현재 " << v.size() << "개의 나라가 입력되어 있습니다.\n나라와 수도를 입력하세요(no no 이면 입력끝)\n";
			
			while (true)
			{
				string str1, str2;

				cout << v.size() + 1 << ">>";

				cin >> str1 >> str2;

				if (str1 == "no" && str2 == "no") break;

				auto a = v.begin();
				for (; a < v.end(); a++)
				{
					if (a->getNation() == str1)
					{
						cout << "already exists !!\n";
						break;
					}
				}

				if (a == v.end())
				{
					v.push_back(Nation(str1, str2));
				}
			}
		}
		else if (n == 2)
		{
			string str;

			while (true)
			{
				uniform_int_distribution<> dis(0, v.size() - 1);

				int correct = dis(gen);

				cout << v[correct].getNation() << "의 수도는?";

				cin >> str;

				if (str == "exit") break;
				else
				{
					if (str == v[correct].getCapital())
					{
						cout << "Correct !!\n";
					}
					else
					{
						cout << "NO !!\n";
					}

				}
			}
		}
	}
}