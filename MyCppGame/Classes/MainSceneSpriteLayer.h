#ifndef __TETRIS_MAIN_SCENE_SPRITE_LAYER_H__
#define __TETRIS_MAIN_SCENE_SPRITE_LAYER_H__

#include "cocos2d.h"

class MainSceneSpriteLayer : public cocos2d::Layer
{

public:
	virtual bool init() override;
	void updateScore();
	CREATE_FUNC(MainSceneSpriteLayer);
};

#endif