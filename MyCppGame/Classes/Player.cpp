#include "Player.h"

#include "tetrisMainScene.h"

#include "tetrisResources.h"

USING_NS_CC;

Player* Player::_player = new Player();

void Player::setMaxScore(int score) 
{
/*
	if (UserDefault::getInstance()->getIntegerForKey(SCORE_KEY, -1) == -1) 
	{
		UserDefault::getInstance()->setIntegerForKey(SCORE_KEY, 0);
	}
	
	UserDefault::getInstance()->setIntegerForKey(SCORE_KEY, score);*/
}

int Player::getMaxScore() 
{
/*
	return UserDefault::getInstance()->getIntegerForKey(SCORE_KEY, 0);
*/
	return 0;
}

Value* Player::getScore() 
{
	return &_score;
}

void Player::goal() 
{
	_score = _score.asInt() + SCORE_OF_ROW;
	static_cast<MainSceneSpriteLayer*>(MainScene::getInstance()->getChildByName(Layer_MainScene_Sprite))->updateScore();
}

Player* Player::getInstance()
{
	return _player;
}

Player::Player()
{
	_score = cocos2d::Value(0);
}

