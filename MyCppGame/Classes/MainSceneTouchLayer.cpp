#include "MainSceneTouchLayer.h"
#include "tetrisMainScene.h"

USING_NS_CC;

void MainSceneTouchLayer::onEnter()
{
	Layer::onEnter();

	auto controlListener = EventListenerTouchOneByOne::create();
	controlListener->setSwallowTouches(true);

	controlListener->onTouchBegan = [](Touch* touch, Event* event){
		return true;
	};

	controlListener->onTouchMoved = [=](Touch* touch, Event* event){
		Vec2 delta = touch->getDelta();
		if (delta.x < 0 && abs(delta.x) / 8 > 1)
		{
			static_cast<MainScene*>(this->getParent())->getCurrentGameLayer()->getCurrentTetromino()->moveLeft();
		}
		else if (delta.x > 0 && abs((delta.x) / 8 > 1))
		{
			static_cast<MainScene*>(this->getParent())->getCurrentGameLayer()->getCurrentTetromino()->moveRight();
		}
		else if (delta.y < 0 && abs(delta.y) > 16 &&
			abs(atan(delta.x / delta.y)) < MATH_PIOVER2 * 3 / 10)
		{
			static_cast<MainScene*>(this->getParent())->getCurrentGameLayer()->getCurrentTetromino()->moveTetromino();
		}
	};

	controlListener->onTouchEnded = [=](Touch* touch, Event* event){
		if (touch->getStartLocation() == touch->getLocation())
		{
			static_cast<MainScene*>(this->getParent())->getCurrentGameLayer()->getCurrentTetromino()->deForm();
		}
	};

	this->getEventDispatcher()->addEventListenerWithFixedPriority(controlListener, 1);

}

void MainSceneTouchLayer::onExit()
{
	this->getEventDispatcher()->removeAllEventListeners();
	Layer::onExit();
}