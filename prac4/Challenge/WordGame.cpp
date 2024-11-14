#include "WordGame.h"

WordGame::WordGame()
{
	cout << "끝말 잇기 게임을 시작합니다\n";
	cout << "게임에 참가하는 인원은 몇명입니까?";

	int player_cnt;

	cin >> player_cnt;

	player.SetPlayerCnt(player_cnt);
}

void WordGame::Start(string startWord)
{
	int playerTurnIdx = 0;
	int playerMaxIdx = player.getPlayerCnt();

	string givenWord = startWord;
	string ansWord;

	cout << "시작하는 단어는 아버지 입니다.\n";

	while (true)
	{
		cout << player.getPlayerName(playerTurnIdx) << ">>";

		cin >> ansWord;

		if (WordCheck(ansWord, givenWord))
		{
			playerTurnIdx++;
			playerTurnIdx %= playerMaxIdx;

			givenWord = ansWord;
			continue;
		}
		break;
	}

	// 끝말 읽기 실패
	End(player.getPlayerName(playerTurnIdx));
}

bool WordGame::WordCheck(string answord, string checkWord)
{
	if (answord.at(0) == checkWord.at(checkWord.length() - 2) &&
		answord.at(1) == checkWord.at(checkWord.length() - 1))
	{
		return true;
	}

	return false;
}

void WordGame::End(string playerName)
{
	cout << playerName << "님이 틀렸습니다.";
}
