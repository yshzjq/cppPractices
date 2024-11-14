#ifndef PLAYER_H
#define PLAYER_H

#include <iostream>
#include <string>

using namespace std;

// 선수를 표현하는 클래스
class Player
{
	int player_cnt;

	string player_name;
	string* player_names;
public:
	Player() { player_cnt = 0; }

	void SetPlayerCnt(int player_name);
	void SetPlayersNames();

	int getPlayerCnt();

	string getPlayerName(int playerNum);
};

#endif