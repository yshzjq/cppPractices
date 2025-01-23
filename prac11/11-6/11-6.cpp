#include <iostream>

using namespace std;

int main()
{


	cout.setf(ios::left);
	cout.fill('_');

	cout.width(15);
	cout << "Number";

	cout.width(15);
	cout << "Square";

	cout.width(15);
	cout << "Square Root";

	cout << '\n';

	for (int i = 0; i < 10; i++)
	{
		cout.width(15);
		cout << 5 * i;

		cout.width(15);
		cout << 5 * i * i;

		cout.width(15);
		cout.precision(3);
		cout << sqrt(5 * i);

		cout << '\n';

	}
}