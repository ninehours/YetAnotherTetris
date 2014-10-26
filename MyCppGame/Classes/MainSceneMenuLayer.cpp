#include "MainSceneMenuLayer.h"
#include "RetryGameScene.h"
#include "tetrisStartScene.h"

#include "Player.h"

#include "tetrisResources.h"

USING_NS_CC;

bool MainSceneMenuLayer::init()
{
	do 
	{
		CC_BREAK_IF(!Layer::init());

		Size size = Director::getInstance()->getWinSize();

		auto layer = LayerColor::create(Color4B(0, 0, 0, 190), size.width, size.height);
		auto sp = Sprite::create("game_lost.png");
		sp->setPosition(Vec2(size.width*0.5, size.height*0.5));
		layer->addChild(sp);
		addChild(layer, 100);

		auto backLabel = Label::create("Back to Menu", "Helvetica-Bold", 40);
		auto backMenu = MenuItemLabel::create(backLabel, CC_CALLBACK_0(MainSceneMenuLayer::backToStartScene, this));
		backMenu->setPosition(Vec2(-100, -200));

		auto retryLabel = Label::create("Retry", "Helvetica-Bold", 40);
		auto retryMenu = MenuItemLabel::create(retryLabel, CC_CALLBACK_0(MainSceneMenuLayer::retryGame, this));
		retryMenu->setPosition(Vec2(150, -200));

		Menu* menu = Menu::create(backMenu, retryMenu, NULL);
		layer->addChild(menu, 100);

		Value scoreString = Value("Your Score: " + Player::getInstance()->getScore()->asString());
		auto scoreLabel = Label::create(scoreString.asString(), "Helvetica-Bold", 30);
		scoreLabel->setPosition(Vec2(350, 370));
		layer->addChild(scoreLabel);

		return true;
	} while (false);
	return false;
}

void MainSceneMenuLayer::onEnter()
{
	Layer::onEnter();
	Director::getInstance()->pause();
}

void MainSceneMenuLayer::retryGame()
{

	Director::getInstance()->resume();
	Director::getInstance()->replaceScene(TransitionFade::create(0.5, RetryGameScene::scene()));
}

void MainSceneMenuLayer::backToStartScene()
{

	Director::getInstance()->resume();
	auto startScene = new StartScene();

	Director::getInstance()->replaceScene(startScene);
	startScene->autorelease();
}
