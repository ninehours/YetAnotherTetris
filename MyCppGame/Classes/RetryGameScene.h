#ifndef __TETRIS_RETRY_GAME_SCENE_H__
#define __TETRIS_RETRY_GAME_SCENE_H__

#include <iostream>
#include "cocos2d.h"

USING_NS_CC;

class RetryGameScene : public LayerRGBA {
public:
public:
	virtual bool init() override;
	void retry(float dt);
	static cocos2d::Scene * scene();
	CREATE_FUNC(RetryGameScene);
};

#endif