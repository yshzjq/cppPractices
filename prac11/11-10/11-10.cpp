#include <iostream>
#include <string>
using namespace std;

istream& prompt(istream& ism)
{
	cout << "¾ÏÈ£?";
	return ism;
}


int main() {
	string password;
	while (true) {
		cin >> prompt >> password;
		if (password == "C++") {
			cout << "login success!!" << endl;
			break;
		}
		else
			cout << "login fail, try againH" << endl;
	}
}