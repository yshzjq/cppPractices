#include <iostream>

using namespace std;

istream& pos(istream& ism)
{
	cout << "��ġ��? ";

	return ism;
}

int main()
{
	int x, y;
	cin >> pos >> x;
	cin >> pos >> y;
	cout << x << ',' << y << endl;
}
