#include "MainSceneSpriteLayer.h"
#include "Player.h"
#include "tetrisResources.h"

USING_NS_CC;

bool MainSceneSpriteLayer::init()
{
	do 
	{
		CC_BREAK_IF(!Layer::init());

		Size visualSize = Director::getInstance()->getVisibleSize();
		Vec2 origin = Director::getInstance()->getVisibleOrigin();

		auto scoreLabel = Label::createWithSystemFont("score 0000", "Helvetica-Bold", 50);
		scoreLabel->setName(Label_MainScene_Score);
		scoreLabel->setPosition(origin.x + scoreLabel->getContentSize().width / 2, origin.y + visualSize.height - scoreLabel->getContentSize().height / 2);
		this->addChild(scoreLabel);

		return true;
	} while (false);

	return false;
}

void MainSceneSpriteLayer::updateScore()
{
	Size visualSize = Director::getInstance()->getVisibleSize();
	Vec2 origin = Director::getInstance()->getVisibleOrigin();

	Label* scoreLabel = static_cast<Label*>(this->getChildByName(Label_MainScene_Score));
	auto scoreString = Value(("score" + Player::getInstance()->getScore()->asString()));
	scoreLabel->setString(scoreString.asString());
	scoreLabel->setPosition(origin.x + scoreLabel->getContentSize().width / 2, origin.y + visualSize.height - scoreLabel->getContentSize().height / 2);
}