#include "tetrisMainScene.h"

#include "RetryGameScene.h"
#include "tetrisStartScene.h"
#include "MainSceneBgLayer.h"

#include "SimpleAudioEngine.h"
#include "math.h"

#include "tetrisResources.h"

USING_NS_CC;

MainScene* MainScene::mainScene = nullptr;

bool MainScene::init()
{
	do 
	{
		CC_BREAK_IF(!Scene::init());
		
		mainScene = this;
		
		Size size = Director::getInstance()->getWinSize();
		Size visibleSize = Director::getInstance()->getVisibleSize();
		Vec2 origin = Director::getInstance()->getVisibleOrigin();
		
		auto bgLayer = MainSceneBgLayer::create();
		this->addChild(bgLayer);

		_spriteLayer = MainSceneSpriteLayer::create();
		_spriteLayer->setName(Layer_MainScene_Sprite);
		this->addChild(_spriteLayer);

		_tetrominoLayer = MainSceneTetromino::create();
		_tetrominoLayer->setName(Layer_MainScene_Tetromino1);
		this->addChild(_tetrominoLayer);

		_menuLayer = MainSceneMenuLayer::create();
		CC_SAFE_RETAIN(_menuLayer);

		_touchLayer = MainSceneTouchLayer::create();
		this->addChild(_touchLayer);

		return true;
	} while (false);

	return false;
}

MainScene* MainScene::getInstance()
{
	if (mainScene != nullptr)
	{
		return mainScene;
	}
	return nullptr;
}

MainSceneTetromino* MainScene::getCurrentGameLayer()
{
	MainSceneTetromino* ret = static_cast<MainSceneTetromino*>(this->getChildByName(Layer_MainScene_Tetromino1));
	return ret;
}


void MainScene::lostGame()
{
	this->addChild(_menuLayer);
}
