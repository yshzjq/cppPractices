#include <iostream>

using namespace std;

istream& pos(istream& ism)
{
	cout << "À§Ä¡´Â? ";

	return ism;
}

int main()
{
	int x, y;
	cin >> pos >> x;
	cin >> pos >> y;
	cout << x << ',' << y << endl;
}
