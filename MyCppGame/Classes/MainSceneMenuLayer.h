#ifndef __TETRIS_MAIN_SCENE_MENU_LAYER_H__
#define __TETRIS_MAIN_SCENE_MENU_LAYER_H__

#include "cocos2d.h"

class MainSceneMenuLayer : public cocos2d::Layer
{

public:
	virtual bool init() override;
	virtual void onEnter() override;
	CREATE_FUNC(MainSceneMenuLayer);

private:
	void backToStartScene();
	void retryGame();
};

#endif