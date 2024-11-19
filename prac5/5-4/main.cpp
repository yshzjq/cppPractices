#include <iostream>
#include <string>

using namespace std;

bool bigger(int a, int b, int& big)
{
	if (a == b) {
		big = a;
		return true;
	}
	else if (a > b) big = a;
	else big = b;

	return false;
}

int main() 
{
	int n1, n2, bigN;

	cout << "두 개의 정수를 입력하세요 >> ";
	cin >> n1 >> n2;

	cout << bigger(n1, n2, bigN) << '\n';

	cout << "큰 수 : " << bigN;

}