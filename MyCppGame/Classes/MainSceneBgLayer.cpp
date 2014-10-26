#include "MainSceneBgLayer.h"
#include "tetrisResources.h"

USING_NS_CC;

bool MainSceneBgLayer::init() 
{
	Layer::init();
	Size visualSize = Director::getInstance()->getVisibleSize();
	Vec2 visualBoarder = Director::getInstance()->getVisibleOrigin();

	auto bgSprite = Sprite::create(Res_Img_MainScene_Background);
	bgSprite->setPosition(visualSize.width * 0.5 + visualBoarder.x, visualSize.height * 0.5 + visualBoarder.y);
	this->addChild(bgSprite);
	return true;
}