#include <iostream>
#include <vector>

using namespace std;

int main()
{
	int n;
	double avg = 0;

	vector<int> v;

	while (true)
	{

		cout << "정수를 입력하세요(0을 입력하면 종료>>";

		cin >> n;

		

		if (n == 0) break;
		else
		{
			v.push_back(n);
			avg += *(v.end() - 1);
			for (auto i = v.begin(); i < v.end(); i++)
			{
				cout << *i << ' ';
			}
			cout << '\n' << "평균 = " << avg / v.size() << '\n';
		}

	}



}