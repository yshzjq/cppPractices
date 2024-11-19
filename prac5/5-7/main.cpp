#include <iostream>
#include <string>

using namespace std;

//class MyIntStack {
//	int p[10]; // 최대 10개의정수 저장
//	int tos; // 스택의 꼭대기를 가리키는 인덱스
//public:
//	MyIntStack() { tos = 0; }
//	bool push(int n);// 정수 n 푸시. 꽉차 있으면 false, 아니면 true 리턴
//	bool pop(int& n); // 팝하여 n 에 저장. 스택이 비어 있으면 false, 아니면 true 리턴
//};
//
//bool MyIntStack::push(int n)
//{
//	if (tos >= 10) return false;
//
//	p[tos] = n;
//	tos++;
//	return true;
//}
//
//bool MyIntStack::pop(int& n)
//{
//	if (tos <= 0) return false;
//
//	n = p[tos-1];
//	tos--;
//	return true;
//}
//
//
//int main() {
//	MyIntStack a;
//	for (int i = 0; i < 11; i++) { // 11 개를 푸시하면, 마지막에는 stack full 이 된다. 
//		if (a.push(i)) cout << i << ' '; // 푸시된값에코
//		else cout << endl << i + 1 << " 번째 stack full" << endl;
//	}
//	int n;
//	for (int i = 0; i < 11; i++) { // 11 개를 팝하면，마지막에는 stack empty 가된다. 
//		if (a.pop(n)) cout << n << ' '; // 팝 한 값 출력 
//		else cout << endl << i + 1 << " 번째 stack empty";
//	}
//	cout << endl;
//}

