#pragma once
#include "Tile.h"


class LevelManger
{
	Tile levelArray[500][200];



	void loadLevel(string levelName);
};