#include <iostream>
#include <string>
#include <random>

using namespace std;

class Player
{
	string name;
public:
	Player(string name) { this->name = name; }
	string getName() { return name; }
};

class GamblinGame
{
	Player* players;
public:
	void GameStart();
};

void GamblinGame::GameStart()
{
	// 시드 
	random_device rd;

	mt19937 gen(rd());
	uniform_int_distribution<> dis(0, RAND_MAX);
	//

	cout << " ***** 갱블링 게임을 시작합니다. *****\n";

	string player1, player2;

	cout << "첫번째 선수 이름>>";
	cin >> player1;

	cout << "두번째 선수 이름>>";
	cin >> player2;

	players = new Player[2]{player1,player2};

	int Turn = 0;

	int num[3];

	cin.ignore();

	while (true)
	{
		Turn %= 2;

		cout << players[Turn].getName() << ":<Enter>";

		getchar();

		cout << "\t\t\t";

		for (int i = 0; i < 3; i++)
		{
			num[i] = rand() % 3;
			cout << num[i];
			cout << '\t';
		}

		if (num[0] == num[1] && num[1] == num[2])
		{
			cout << players[Turn].getName() << "님 승리!!";
			break;
		}
		else
			cout << "아쉽군요!\n";

		Turn++;
	}
}


int main()
{
	GamblinGame gamblingame;

	gamblingame.GameStart();
}

