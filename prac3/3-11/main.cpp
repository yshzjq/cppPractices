#include <iostream>
#include "Box.h"
using namespace std;

int main() {
	Box b(10, 2);
	b.draw(); // 박스를그린다.
	cout << endl;
	b.setSize(7, 4); // 박스의크기를변경한다.
	b.setFill('^'); // 박스의 내부를채울문자를 로변경한다.
	b.draw(); // 박스를그린다.
}
