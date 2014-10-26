#ifndef __TETRIS_GAME_MAIN_SCENE_TETROMINO_H__
#define __TETRIS_GAME_MAIN_SCENE_TETROMINO_H__

#include "cocos2d.h"
#include "Tetromino.h"

USING_NS_CC;

class MainSceneTetromino : public Layer
{

public:
	virtual void onEnter() override;
	virtual void onExit() override;

	CREATE_FUNC(MainSceneTetromino);

	Sprite* getSpriteWithPoint(const Vec2 &p, Tetromino** tet = nullptr);
	Tetromino* getCurrentTetromino();


private:
	void produceTetromino();
	void eliminateTetromino();
	void moveCurrentTetromino(float dt);
	void addSolidTetromino(Tetromino* t);
	void currentTetrominoHitsBottom();

	bool isGameOver();
	
	Vector<Tetromino*> _solidTetromino;
	Tetromino* _currentTetromino;

};

#endif