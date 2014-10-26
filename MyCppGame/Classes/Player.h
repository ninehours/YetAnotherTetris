#ifndef __TETRIS_PLAYER_H__
#define __TETRIS_PLAYER_H__

#include <iostream>
#include "cocos2d.h"
#include "GameConfig.h"

class Player 
{
public:
	static Player* getInstance();

	int getMaxScore();
	void setMaxScore(int score);	

	void goal();
	cocos2d::Value* getScore();

private:
	Player();

private:
	cocos2d::Value _score;
	static Player* _player;
};

#endif
