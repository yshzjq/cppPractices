#include <iostream>
#include <vector>
using namespace std;

int main()
{
	const int iValue = 4;

	vector<string> str = { "age","aya" };

	cout << str[0].find("lge");

	if (str[0].find("ge") == NULL) cout << "find";
}


