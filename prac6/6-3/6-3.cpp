#include <iostream>

using namespace std;

int big(int n1, int n2, int n3 = 100)
{
	if (n1 > n2 ? n1 : n2 > n3) return n3;
	else return n1 > n2 ? n1 : n2;
}

int main() {
	int x = big(3, 5); // 3과 5 중 큰 값 S는 최대값 100보다 작으므로, 5 리턴 
	int y = big(300, 60); // 300과 的 중 큰 값 300이 최대값 100보다 크므로, 100 리턴 
	int z = big(30, 60, 50); // 30과 60 중 큰 값 的이 최대값 50보다 크므로, 50 리턴 
	cout << x << ' ' << y << ' ' << z << endl;
} 