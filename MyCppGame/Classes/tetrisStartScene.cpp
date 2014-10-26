#include "tetrisStartScene.h"

#include "SimpleAudioEngine.h"
#include "extensions/cocos-ext.h"
#include "CocoStudio.h"

#include "tetrisMainScene.h"
#include "tetrisResources.h"

#if(CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID)
#include "../proj.android/jni/hellocpp/test.h"
#endif

USING_NS_CC;
USING_NS_CC_EXT;
using namespace ui;
using namespace cocostudio;

void StartScene::onEnter()
{
	Scene::onEnter();
	do 
	{
		auto uiLayer = Layer::create();
		CC_BREAK_IF(!uiLayer);
		//uiLayer->scheduleUpdate();
		this->addChild(uiLayer);

		auto layout = dynamic_cast<Layout*>(GUIReader::getInstance()->widgetFromJsonFile(Res_Layout_StartScene.c_str()));
		uiLayer->addChild(layout);

		auto exitButton = static_cast<Button*>(Helper::seekWidgetByName(layout, Res_Button_StartScene_Exit));
		exitButton->addTouchEventListener(CC_CALLBACK_2(StartScene::closeIsPressed, this));

		auto playButton = static_cast<Button*>(Helper::seekWidgetByName(layout, Res_Button_StartScene_Play));
		playButton->addTouchEventListener(CC_CALLBACK_2(StartScene::playIsPressed, this));

	} while (false);

	return;
}

void StartScene::onExit()
{

	cocostudio::SceneReader::destroyInstance();
	cocostudio::GUIReader::destroyInstance();
	cocostudio::ActionManagerEx::destroyInstance();

	Scene::onExit();
}

void StartScene::playIsPressed(Ref* sender, Widget::TouchEventType type)
{
	if (Widget::TouchEventType::ENDED == type)
	{
		Director::getInstance()->replaceScene(TransitionSplitRows::create(1.5f, MainScene::create()));
	}
}

void StartScene::closeIsPressed(Ref* sender, Widget::TouchEventType type)
{
	if (Widget::TouchEventType::ENDED == type)
	{
#if(CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID)
		showTipDialog("exit", "alexzhou,really go?");
#endif

#if(CC_TARGET_PLATFORM == CC_PLATFORM_WIN32)
		Director::getInstance()->end();
#endif
	}
}
