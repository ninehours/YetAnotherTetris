#include "StartScene.h"
#include "GameMainScene.h"
#include "SimpleAudioEngine.h"

#include "extensions/cocos-ext.h"

USING_NS_CC;
USING_NS_CC_EXT;
using namespace ui;
using namespace cocostudio;

StartScene::StartScene() : _uiLayer(nullptr), _layout(nullptr)
{
	Scene::init();
}

StartScene::~StartScene()
{
}

void StartScene::onEnter()
{
	Scene::onEnter();
	do 
	{
		_uiLayer = Layer::create();
		CC_BREAK_IF(!_uiLayer);
		_uiLayer->scheduleUpdate();
		this->addChild(_uiLayer);

		_layout = dynamic_cast<Layout*>(GUIReader::getInstance()->widgetFromJsonFile("tetrisStartScene_1.json"));
		_uiLayer->addChild(_layout);

		Button* closeButton = static_cast<Button*>(Helper::seekWidgetByName(_layout, "button_exit"));
		closeButton->addTouchEventListener(CC_CALLBACK_2(StartScene::closeIsPressed, this));

		Button* playButton = static_cast<Button*>(Helper::seekWidgetByName(_layout, "button_play"));
		playButton->addTouchEventListener(CC_CALLBACK_2(StartScene::playIsPressed, this));

	} while (false);

	return;
}

void StartScene::onExit()
{
	_uiLayer->removeFromParent();

	cocostudio::SceneReader::destroyInstance();
	cocostudio::GUIReader::destroyInstance();
	cocostudio::ActionManagerEx::destroyInstance();

	CCScene::onExit();
}

void StartScene::playIsPressed(Ref* sender, Widget::TouchEventType type)
{
	if (Widget::TouchEventType::ENDED == type)
	{
		Director::getInstance()->replaceScene(TransitionSplitRows::create(1.5, MainScene::createScene()));
	}
}

void StartScene::closeIsPressed(Ref* sender, Widget::TouchEventType type)
{
	if (Widget::TouchEventType::ENDED == type)
	{
		Director::getInstance()->end();
	}
}
