#include "Player.h"

void Player::SetPlayerCnt(int player_cnt)
{
	this->player_cnt = player_cnt;

	player_names = new string[player_cnt];

	SetPlayersNames();
}

void Player::SetPlayersNames()
{
	for (int i = 0; i < player_cnt; i++)
	{
		cout << "참가자의 이름을 입력하세요. 빈칸 없이>>";
		cin >> player_names[i];
	}
}

int Player::getPlayerCnt()
{
	return player_cnt;
}

string Player::getPlayerName(int playerNum)
{
	return player_names[playerNum];
}
