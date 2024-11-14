#include <iostream> 
#include <string>
using namespace std;

class Integer
{
	int value;
public:
	Integer(int _value);
	Integer(string _value);

	int get();
	void set(int value);
	bool isEven();
};

Integer::Integer(int _value)
{
	value = _value;
}

Integer::Integer(string _value)
{
	value = stoi(_value);
}

inline int Integer::get()
{
	return value;
}

void Integer::set(int _value)
{
	value = _value;
}

bool Integer::isEven()
{
	if (value % 2) return false;
	return true;
}




int main() {
	Integer n(30);
	cout << n.get() << ' '; 
	n.set(50);
	cout << n.get() << ' ';

	Integer m("300");
	cout << m.get() << ' '; 
	cout << m.isEven(); // true(정수로 1) 출력 
}

