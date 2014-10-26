#include "RetryGameScene.h"
#include "tetrisMainScene.h"

Scene * RetryGameScene::scene() 
{
	Scene * scene = Scene::create();
	RetryGameScene * layer = RetryGameScene::create();
	scene->addChild(layer);
	return scene;
}

bool RetryGameScene::init() 
{


	this->setColor(ccWHITE);
	this->schedule(schedule_selector(RetryGameScene::retry), 0.5, 0, 2);
	return true;
}

void RetryGameScene::retry(float dt) 
{
	Director::getInstance()->replaceScene(TransitionSplitRows::create(1.0, MainScene::create()));
}