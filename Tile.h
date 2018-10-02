#pragma once
#include "baseObject.h"

class Tile :public BaseObject
{
	bool collidable;
	bool doesDamage;

	Tile();
	Tile(bool collidable, bool doesDamage, int imageNUM);

};