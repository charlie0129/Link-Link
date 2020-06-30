#include "GameScene.h"
#include "Control.h"
#include "StartScene.h"

extern Control* now;

GameScene::GameScene(int m, int n)
{
	map = new Map{ m,n };
}

GameScene::~GameScene()
{
	delete map;
}

void GameScene::update()
{
	now->putImage("./Pic/Game.png", 0, 0, 960, 640);
	Pic* a = new Pic(1, 1, 2);
	Pic* b = new Pic(2, 2, 4);
	Pic* c1 = new Pic(3, 4, 2);
	Pic* c2 = new Pic(3, 4, 4);
	map->drawMatchedLine(a, b, c1, c2);
	map->draw();
}

void GameScene::onMouse(Sint32 x, Sint32 y)
{
	int linearMousePositionOnMap = getMousePositionOnMap(x, y);
	if (linearMousePositionOnMap >= 0)
	{
		map->Map::map[linearMousePositionOnMap]->setIsVisible(false);
	}
}

/*
*this function returns the index in map which represents the picture
*that has benn clicked.
*It returns **-1** if the spot that has been clicked is outside the map.
*/
int GameScene::getMousePositionOnMap(Sint32 x, Sint32 y)
{
	const int NUM_OF_HORIZONTAL_PICTURES = 14;
	const int NUM_OF_VERTICAL_PICTURES   = 11;

	const int MAP_START_POSOTION_X = 50;
	const int MAP_START_POSOTION_Y = 50;
	const int MAP_END_POSOTION_X   = 50 * (NUM_OF_HORIZONTAL_PICTURES + 1);
	const int MAP_END_POSOTION_Y   = 50 * (NUM_OF_VERTICAL_PICTURES   + 1);

	int ln, col;
	int ret = -1;

	if ((x >= MAP_START_POSOTION_X)
		&& (y >= MAP_START_POSOTION_Y)
		&& (x <= MAP_END_POSOTION_X)
		&& (y <= MAP_END_POSOTION_Y))
	{
		ln  = (y - MAP_START_POSOTION_Y) / Pic::height;
		col = (x - MAP_START_POSOTION_X) / Pic::width ;

		// index in map to return
		ret = col * NUM_OF_VERTICAL_PICTURES + ln;
	}

	return ret;
}
