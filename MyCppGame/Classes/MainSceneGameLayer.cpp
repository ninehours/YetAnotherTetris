#include "MainSceneGameLayer.h"

#include "tetrisMainScene.h"

#include "tetrisResources.h"
#include "GameConfig.h"

USING_NS_CC;

void MainSceneTetromino::produceTetromino()
{
	//O1 = 0, I1 = 1, I2 = 2, 
	//LA1 = 3, LA2 = 4, LA3 = 5, LA4 = 6, 
	//LB1 = 7, LB2 = 8, LB3 = 9, LB4 = 10, 
	//SA1 = 11, SA2 = 12, SB1 = 13, SB2 = 14, 
	//T1 = 15, T2 = 16, T3 = 17, T4 = 18
	
	//generate random tetromino
	//TODO change pseudo random generator 
	TetrominoSubType type;
	int i = (int)(CCRANDOM_0_1() * 1000) % 19;
	switch (i)
	{
	case 0:
		type = O1;
		break;
	case 1:
		type = I1;
		break;
	case 2:
		type = I2;
		break;
	case 3:
		type = LA1;
		break;
	case 4:
		type = LA2;
		break;
	case 5:
		type = LA3;
		break;
	case 6:
		type = LA4;
		break;
	case 7:
		type = LB1;
		break;
	case 8:
		type = LB2;
		break;
	case 9:
		type = LB3;
		break;
	case 10:
		type = LB4;
		break;
	case 11:
		type = SA1;
		break;
	case 12:
		type = SA2;
		break;
	case 13:
		type = SB1;
		break;
	case 14:
		type = SB2;
		break;
	case 15:
		type = T1;
		break;
	case 16:
		type = T2;
		break;
	case 17:
		type = T3;
		break;
	case 18:
		type = T4;
		break;

	default:
		break;
	}

	//create tetromino and add it to layer
	Tetromino* t = Tetromino::create(type);
	for (auto sp_obj : *t->getBlocks())
	{
		this->addChild(sp_obj);
	}
	this->_currentTetromino = t;
}

void MainSceneTetromino::moveCurrentTetromino(float dt)
{
	if (this->_currentTetromino != nullptr)
	{
		if (!this->_currentTetromino->moveTetromino())
		{
			this->currentTetrominoHitsBottom();
		}
	}
}

void MainSceneTetromino::currentTetrominoHitsBottom()
{
	//tetromino hit the button.
	addSolidTetromino(this->_currentTetromino);
	_currentTetromino = nullptr;

	//judge if tetromino fills one row
	eliminateTetromino();

	//reproduce tetromino
	produceTetromino();

	if (isGameOver())
	{
		MainScene::getInstance()->lostGame();
	}
}

void MainSceneTetromino::addSolidTetromino(Tetromino* t)
{
	this->_solidTetromino.pushBack(t);
}

void MainSceneTetromino::eliminateTetromino()
{
	int rowCount = 0;

	//search from the bottom row
	for (int row = 0; row < ROWS;)
	{
		bool canDisapear = true;
		for (int col = 0; col < COLS; col++)
		{
			Sprite* sp = getSpriteWithPoint(Vec2(col, row));
			if (sp == nullptr)
			{
				//there is an empty block in this row
				canDisapear = false;
				continue;
			}
		}

		// the row is full, eliminate it
		if (canDisapear)
		{
			rowCount++;

			for (int col = 0; col < COLS; col++)
			{
				Tetromino* tet = nullptr;
				Sprite* s = getSpriteWithPoint(Vec2(col, row), &tet);
				
				// play the animation here
				// playBitDead(s);

				this->removeChild(s);
				tet->getBlocks()->eraseObject(s);
			}

			//move the remain blocks down one row.
			for (int row2 = row + 1; row2 < ROWS; row2++)
			{
				for (int col2 = 0; col2 < COLS; col2++)
				{
					Sprite* sp = getSpriteWithPoint(Vec2(col2, row2));
					if (sp != nullptr) 
					{
						sp->setPosition(Tetromino::GamePointConvertToPoint(Vec2(col2, row2 - 1), sp->getContentSize()));
					}
				}
			}
			Player::getInstance()->goal();
		}
		else 
		{
			row++;
		}

	}

	if (rowCount > 0)
	{
		log("disapear count %d", rowCount);
	}

}

bool MainSceneTetromino::isGameOver()
{
	bool isOver = false;

	for (int col = 0; col < COLS; col++)
	{
		if (this->getSpriteWithPoint(Vec2(col, ROWS - 1)))
		{
			isOver = true;
			break;
		}
	}

	return isOver;
}

Sprite* MainSceneTetromino::getSpriteWithPoint(const Vec2 &p, Tetromino** tet)
{
	Sprite* sp_ret = nullptr;
	bool isFind = false;
	for (auto tet_obj : _solidTetromino)
	{
		for (auto sp_obj : *tet_obj->getBlocks())
		{
			Vec2 oPoint = Tetromino::PointConvertToGamePoint(sp_obj->getPosition(), sp_obj->getContentSize());

			if (oPoint.x == p.x && oPoint.y == p.y)
			{
				sp_ret = sp_obj;
				isFind = true;
				break;
			}
		}
		if (isFind)
		{
			if (tet != nullptr)
			{
				*tet = tet_obj;
			}
			break;
		}
	}

	return sp_ret;
}

Tetromino* MainSceneTetromino::getCurrentTetromino()
{
	return _currentTetromino;
}

void MainSceneTetromino::onEnter()
{
	Layer::onEnter();

	produceTetromino();

	this->schedule(schedule_selector(MainSceneTetromino::moveCurrentTetromino), 0.5);
}

void MainSceneTetromino::onExit()
{
	this->unscheduleAllSelectors();

	Layer::onExit();
}
