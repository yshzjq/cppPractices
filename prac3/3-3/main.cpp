#include <iostream>
using namespace std;

class Account
{
	string name;
	int id;
	int money;
public:
	Account(string _name, int _id, int _money);
	void deposit(int _money);
	string getOwner();
	int inquiry();
	int withdraw(int _money);
};

Account::Account(string _name, int _id, int _money)
{
	name = _name;
	id = _id;
	money = _money;
}

void Account::deposit(int _money)
{
	money += _money;
}

string Account::getOwner()
{
	return name;
}

int Account::inquiry()
{
	return money;
}

int Account::withdraw(int _money)
{
	money -= _money;
	return money;
}

int main()
{
	Account a("kitae", 1, 5000);
	a.deposit(50000);
	cout << a.getOwner() << "ÀÇ ÀÜ¾×Àº " << a.inquiry() << endl;
	int money = a.withdraw(20000);
	cout << a.getOwner() << "ÀÇ ÀÜ¾×Àº " << a.inquiry() << endl;
}
