#include <iostream>
#include <string>

using namespace std;

void combine(string str1, string str2, string& mergedstr)
{
	mergedstr = str1 + ' ' + str2;
}

int main() {
	string textl("I love you"), text2("very much");
	string text3; // 비어 있는문자열
	combine(textl, text2, text3); //
	cout << text3; // "I love you very much" 출력
}