#ifndef __TETRIS_START_SCENE_H__
#define __TETRIS_START_SCENE_H__

#include "cocos2d.h"
#include "ui/CocosGUI.h"

class StartScene : public cocos2d::Scene
{
public:
	CREATE_FUNC(StartScene);
	virtual void onEnter() override;
	virtual	void onExit() override;

private:
	void playIsPressed(Ref* sender, cocos2d::ui::Widget::TouchEventType type);
	void closeIsPressed(Ref* sender, cocos2d::ui::Widget::TouchEventType type);

};

#endif
