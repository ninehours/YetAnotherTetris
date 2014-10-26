#ifndef __TERIS_MAIN_SCENE_H__
#define __TERIS_MAIN_SCENE_H__

#include "cocos2d.h"

#include "Tetromino.h"
#include "Player.h"

#include "MainSceneGameLayer.h"
#include "MainSceneSpriteLayer.h"
#include "MainSceneTouchLayer.h"
#include "MainSceneMenuLayer.h"

class MainScene : public cocos2d::Scene
{
public:
	static MainScene* getInstance();
	MainSceneTetromino* getCurrentGameLayer();
	CREATE_FUNC(MainScene);
	
	void lostGame();

	virtual bool init() override;
	//virtual void onEnter() override;
	//virtual void onExit() override;

private:
	bool isGameOver();
	void pause();
	void resume();

private:
	static MainScene* mainScene;
	MainSceneTetromino* _tetrominoLayer;
	MainSceneMenuLayer* _menuLayer;
	MainSceneTouchLayer* _touchLayer;
	MainSceneSpriteLayer* _spriteLayer;

};

#endif
