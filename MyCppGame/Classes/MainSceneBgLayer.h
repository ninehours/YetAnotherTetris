#ifndef __TETRIS_MAIN_SCENE_BACKGROUND_LAYER_H__
#define __TETRIS_MAIN_SCENE_BACKGROUND_LAYER_H__

#include "cocos2d.h"

class MainSceneBgLayer : public cocos2d::Layer 
{

public:
	virtual bool init();
	CREATE_FUNC(MainSceneBgLayer);
};

#endif