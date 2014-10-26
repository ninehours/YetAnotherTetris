#ifndef __TETRIS_GAME_MAIN_SCENE_TOUCH_LAYER_H__
#define __TETRIS_GAME_MAIN_SCENE_TOUCH_LAYER_H__

#include "cocos2d.h"

class MainSceneTouchLayer : public cocos2d::Layer
{

public:
	virtual void onEnter() override;
	virtual void onExit() override;
	CREATE_FUNC(MainSceneTouchLayer);
};

#endif