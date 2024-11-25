#include <iostream>
#include <random>
#include <string>

using namespace std;

class UpAndDownGame
{
	static int num;
	static int up;
	static int down;

	static string player1;
	static string player2;

	static bool turn;

public:
	UpAndDownGame();
	void start();
};

UpAndDownGame::UpAndDownGame()
{
	random_device rd;
	mt19937 gen(rd());
	uniform_int_distribution<> dis(0, 99);

	num = dis(gen);

}

int UpAndDownGame::up = 99;
int UpAndDownGame::down = 0;
int UpAndDownGame::num = 0;

string UpAndDownGame::player1 = "김인수";
string UpAndDownGame::player2 = "오은경";

bool UpAndDownGame::turn = false;

void UpAndDownGame::start()
{
	cout << "게임을 시작합니다." << '\n';

	while (true)
	{
		cout << "답은 " << down << "과 " << up << "사이에 있습니다.\n";

		if (turn = !turn) cout << player1 << ">>";
		else cout << player2 << ">>";

		int n;

		cin >> n;

		if (num == n)
		{
			if(turn) cout << player1 << "가 이겼습니다!!";
			else cout << player2 << "가 이겼습니다!!";
			break;
		}
		else
		{
			if (num < n)
			{
				up = n;
			}
			else
			{
				down = n;
			}
		}
	}
}

int main()
{
	UpAndDownGame game;

	game.start();

	return 0;
}

