#ifndef __TETRIS_START_SCENE_H__
#define __TETRIS_START_SCENE_H__

#include "cocos2d.h"
#include "cocostudio/CocoStudio.h"
#include "ui/CocosGUI.h"

class StartScene : public cocos2d::Scene
{
public:
	StartScene();
	virtual void onEnter() override;
	virtual	void onExit() override;

private:
	void playIsPressed(Ref* sender, cocos2d::ui::Widget::TouchEventType type);
	void closeIsPressed(Ref* sender, cocos2d::ui::Widget::TouchEventType type);

	virtual ~StartScene();

	cocos2d::Layer* _uiLayer;
	cocos2d::ui::Layout* _layout;
};

#endif
