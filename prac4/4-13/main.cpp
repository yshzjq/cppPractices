#include <iostream>
#include <string>

using namespace std;

class Histogram
{
	string str;
public:
	Histogram(string str);
	void put(string add_str);
	void putc(char add_c);
	void print();
};

Histogram::Histogram(string str)
{
	this->str = str;
}

void Histogram::put(string add_str)
{
	this->str += add_str;
}

void Histogram::putc(char add_c)
{
	this->str += add_c;
}

void Histogram::print()
{
	cout << str << "\n\n";

	int str_alpha_cnt = 0;

	for (char c : str)
	{
		if (isalpha(c)) str_alpha_cnt++;
	}

	cout << "ÃÑ ¾ËÆÄºª ¼ö " << str_alpha_cnt << "\n\n";

	for (char c = 'a'; c <= 'z'; c++)
	{
		int alpha_cnt = 0;

		for (char ch : str)
		{
			if (tolower(ch) == c) alpha_cnt++;
		}

		cout << c << " (" << alpha_cnt << ")" << "    : ";

		for (int i = 0; i < alpha_cnt; i++) cout << '*';
		cout << '\n';
	}

}


int main()
{
	Histogram elvisHisto("Wise men say, only fools rush in But I can't help, ");
	elvisHisto.put("falling in love with you");
	elvisHisto.putc('-');
	elvisHisto.put(" Elvis Presley");
	elvisHisto.print();
}

