#include <iostream>
#include <string>

using namespace std;

class Buffer 
{
	string text;
public:
	Buffer(string text) { this->text = text; }
	void add(string next) { text += next; } // text 에 next 문자열 덧붙이기 
	void print() { cout << text << endl; }
};

Buffer& append(Buffer& buf, string text) 
{
	buf.add(text);
	return buf;
}

int main() 
{
	Buffer buf("Hello");
	Buffer& temp = append(buf, "Guys"); // b니f의 문자열에 "Guys" 덧붙임
	temp.print(); // "HelloGuys" 출력
	buf.print(); // "HelioGuys" 출력
};

