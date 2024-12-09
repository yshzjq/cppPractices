#include <iostream>	
#include <string>

using namespace std;

class Histogram
{
	string str;
public:
	Histogram(string str) { this->str = str; }
	Histogram& operator << (string str)
	{
		this->str += str;
		return *this;
	}

	Histogram& operator << (char c)
	{
		this->str += c;
		return *this;
	}

	void operator!()
	{
		cout << str << "\n\n";

		int alpha[100] = {0};

		int count = 0;

		for (char c : str)
		{
			if (isalpha(c))
			{
				for (int i = 'a'; i <= 'z'; i++)
				{
					if (tolower(c) == i)
					{
						alpha[i - 'a']++;
						count++;
						break;
					}
				}
			}
		}

		cout << "총 알파벳 수 " << count << '\n';

		for (char i = 'a'; i <= 'z'; i++)
		{
			cout << i << ':';
			for (int j = 0; j < alpha[i-'a']; j++)
			{
				cout << '*';
			}
			cout << '\n';
		}
	}
};

int main()
{
	Histogram song("Wise men say, \nonly fools rush in But I can't help, \n");
	song << "falling" << " in love with you." << " - by"; // 히스토그램에 문지열 추가
	song << 'k' << 'i' << 't';
	!song; // 히스토그램 그리기
}