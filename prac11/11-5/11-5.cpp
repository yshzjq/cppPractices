#include <iostream>
#include <string>
using namespace std;
int main() 
{
	string cmd;

	cout << "getline(cin, cmd, '\n')�� ���ڿ��� �н��ϴ�." << endl;

	while (true) 
	{
		cout << "�����Ϸ��� exit�� �Է��ϼ��� >>";
		getline(cin, cmd, '\n'); // 79�������ǹ�������

		if (cmd == "exit") {
			cout << "���α׷��������մϴ�....";
			return 0;
		}
		else cin.ignore(1); // ���ۿ� �����ִ� <Enter> Ű (1 \n*) ����
	}
}