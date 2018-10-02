#pragma once
#include "baseObject.h"

class Bullet:public BaseObject
{
public:
	int bulletDamage;


	Bullet();
	Bullet(SDL_Rect rect, SDL_Rect colrect, int imageNUMB, int bulletDamageB);
	void move(bool direction);// false left to right, true right to left
	Bullet returnBullet();
};

