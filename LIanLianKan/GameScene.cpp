#include "GameScene.h"
#include "Control.h"
#include "StartScene.h"
#include "SetScene.h"
extern Control* now;

GameScene::GameScene(int m, int n)
{
	map = new Map{ m,n };
		map->setConnectLine(nullptr);
}

GameScene::~GameScene()
{
	delete map;
}

void GameScene::update()
{
	now->putImage("./Pic/Game.png", 0, 0, 960, 640);

	if (map->anyMatch() == false)map->RandomOrder();
	map->draw();

	if (map->getConnectLine() != nullptr) {
		map->getConnectLine()->drawLine(now);
		map->getConnectLine()->cnt--;
		if(map->getConnectLine()->cnt==0){
			map->setConnectLine(nullptr);
		}
	}

}

void GameScene::onMouse(Sint32 x, Sint32 y)
{
	/*对于图标的判断*/
	int linearMousePositionOnMap = getMousePositionOnMap(x, y);
	if (linearMousePositionOnMap >= 0 && map->map[linearMousePositionOnMap]->getValid())
	{
		if(last==nullptr){
			last = map->map[linearMousePositionOnMap];
			last->setIsStroke(true);
		}
		else if(map->isMatch(last, map->map[linearMousePositionOnMap])==false){
			last->setIsStroke(false);
			last = map->map[linearMousePositionOnMap];
			last->setIsStroke(true);
		}else{
			last = nullptr;
		}
	//	printf("%d %d\n", map->map[linearMousePositionOnMap]->getX(), map->map[linearMousePositionOnMap]->getY());
	}

	/*功能按键的判断*/
	/*设置界面*/
	if (x >= 900 && x <= 960 && y >= 0 && y <= 50) new SetScene(this);
}

/*
*this function returns the index in map which represents the picture
*that has benn clicked.
*It returns **-1** if the spot that has been clicked is outside the map.
*/
int GameScene::getMousePositionOnMap(Sint32 x, Sint32 y)
{
	// how many pictures are there horizontally
	const int NUM_OF_HORIZONTAL_PICTURES = 16;
	// how many pictures are there vertically
	const int NUM_OF_VERTICAL_PICTURES = 13;

	// consider the map as a rectangle
	// this is the coordinate of the upper left corner
	const int MAP_START_POSOTION_X = 50;
	const int MAP_START_POSOTION_Y = 50;
	// this is the coordinate of the lower right corner
	const int MAP_END_POSOTION_X = 50 * (NUM_OF_HORIZONTAL_PICTURES);
	const int MAP_END_POSOTION_Y = 50 * (NUM_OF_VERTICAL_PICTURES);

	int ln, col;
	// return value
	int ret = -1;

	if ((x >= MAP_START_POSOTION_X)
		&& (y >= MAP_START_POSOTION_Y)
		&& (x <= MAP_END_POSOTION_X)
		&& (y <= MAP_END_POSOTION_Y))
	{
		ln = (y - MAP_START_POSOTION_Y) / Pic::height + 1; // line index
		col = (x - MAP_START_POSOTION_X) / Pic::width + 1; // column index

		// index in map to return
		ret = col * NUM_OF_VERTICAL_PICTURES + ln;
	}

	return ret;
}

