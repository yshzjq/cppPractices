#include <iostream>
#include <random>
#include <string>

using namespace std;

class AbstractPlayer {
	string name;
protected:
	static string gbb[3];
public:
	AbstractPlayer(string name) { 
		this->name = name; 		
	}

	virtual string turn() = 0;
	string getName() { return name; }

};

class Player : public AbstractPlayer
{
public:
	Player(string name) : AbstractPlayer(name) {};

	string turn() 
	{
		

		while (true)
		{
			string str;

			cout << getName() << ">>";
			cin >> str;

			for (int i = 0; i < 3; i++)
			{
				if (gbb[i] == str)
				{
					return str;
				}
			}
		}
	}
};

string AbstractPlayer:: gbb[3] = { "가위","바위","보" };

class Computer : public AbstractPlayer
{
public:
	Computer(string name) : AbstractPlayer(name) {};

	string turn()
	{
		random_device rd;
		mt19937 gen(rd());
		uniform_int_distribution<> dis(0, 2);

		int n = dis(gen);

		cout << getName() << ">>" << gbb[n] << '\n';

		return gbb[n];
	}
};

int main()
{
	

	cout << "***** 컴퓨터와 사람이 가위 바위 보 대결을 펼칩니다. *****\n";

	cout << "선수 이름을 입력하세요>>";
	string playerName;
	cin >> playerName;

	Player player(playerName);
	Computer computer("Computer");

	string player_Hand;
	string computer_Hand;

	while (true)
	{
		
		player_Hand = player.turn();
		computer_Hand = computer.turn();

		if (player_Hand == computer_Hand)
		{
			cout << "the same";
		}
		else
		{
			if (player_Hand == "바위")
			{
				if (computer_Hand == "가위")
				{
					cout << player.getName() << " is winner.";
				}
				else
				{
					cout << computer.getName() << " is winner";
				}
			}
			else if (player_Hand == "가위")
			{
				if (computer_Hand == "보")
				{
					cout << player.getName() << " is winner.";
				}
				else
				{
					cout << computer.getName() << " is winner";
				}
			}
			else if (player_Hand == "보")
			{
				if (computer_Hand == "바위")
				{
					cout << player.getName() << " is winner.";
				}
				else
				{
					cout << computer.getName() << " is winner";
				}
			}
		}
		cout << '\n';
	}

	


}