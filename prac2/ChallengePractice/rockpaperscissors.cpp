#include <iostream>
#include <string>
using namespace std;

int main()
{
	string A, B; // 가위 바위 보 입력 받을 변수

	cout << "가위 바위 보 게임을 합니다. 가위, 바위, 보 중에서 입력하세요.\n";
	
	cout << "로미오>>";
	cin >> A;
	cout << "줄리엣>>";
	cin >> B;

	if ((A == "가위" && B == "보") || (A == "보" && B == "바위") || (A == "바위" && B == "가위"))
	{
		cout << "로미오가 이겼습니다.";
	}
	else if ((B == "가위" && A == "보") || (B == "보" && A == "바위") || (B == "바위" && A == "가위"))
	{
		cout << "줄리엣이 이겼습니다.";
	}
	else
	{
		cout << "비겼습니다.";
	}
	// return 0 생략 가능
}