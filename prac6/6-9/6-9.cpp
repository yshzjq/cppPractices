#include <iostream>
#include <string>

using namespace std;

class Board
{
public:
	static string str[100];
	static int idx;
	static void add(string command);
	static void print();
};

string Board::str[100] = {};

int Board::idx = 0;

void Board::add(string command)
{
	str[idx] = to_string(idx) + ": " + command;
	idx++;
}

void Board::print()
{
	cout << "************** 게시판입니다. **************\n";

	for (int i = 0;i<idx;i++)
	{
		cout << str[i] << '\n';
	}
}


int main() {
	// Board myBoard; // 객체 생성은 컴파일 오류입니다.
	Board::add("증간고사는 감독 없는 자율 시험입니다.");
	Board::add("코딩 라운지 많이 이용해 주세요.");
	Board::print();
	Board::add("진소린 학생이 경진대회 입상하였습니다. 축하해주세요");
	Board::print();
}

