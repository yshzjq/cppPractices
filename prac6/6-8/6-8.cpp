#include <iostream>
#include <string>

using namespace std;

class Trace
{
public:
	static string debugs[100];
	static int didx;
	static void put(string tag, string debug);
	static void print(string tag = "All");
};

string Trace::debugs[100] = { "" };

int Trace::didx = 0;

void Trace::put(string tag, string debug)
{
	debugs[didx] = tag + ":" + debug;
	didx++;
}

void Trace::print(string tag)
{
	if (tag == "All")
	{
		cout << "-----" <<  "모든 Trace 정보를 출력합니다. -----\n";
		for (int i = 0;i<didx;i++)
		{
			cout << debugs[i] << '\n';
		}
	}
	else
	{
		cout << "-----" << tag << "태그의 Trace 정보를 출력합니다. -----\n";
		for (int i = 0; i < didx; i++)
		{
			if (debugs[i].find(tag) == 0)
			{
				cout << debugs[i] << '\n';
			}
		}

	}
}

void f() {
	int a, b, c;
	cout << "두 개의 정수를 이력하세요>>";
	cin >> a >> b;
	Trace::put("f()", "정수를 입력 받았음");
	c = a + b;
	Trace::put("f()", "합 계산");
	cout << "합은 " << c << endl;
}

int main()
{
	Trace::put("main()", "프로그램 시작합니다");
	f();
	Trace::put("main()", "종료");

	Trace::print("f()");
	Trace::print();
}


