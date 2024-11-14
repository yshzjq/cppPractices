#ifndef WORDGAME_H
#define WORDGAME_H

#include <iostream>
#include <string>

#include "Player.h"

using namespace std;

// 끝말잇기 게임 전체를 운영하는 클래스
class WordGame
{
	Player player;
public:
	WordGame();

	void Start(string startWord);

	bool WordCheck(string ansWord,string checkWord);

	void End(string playerName);
};

#endif 