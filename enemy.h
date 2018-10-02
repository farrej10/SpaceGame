#pragma once
#include "character.h"

class Enemy:public Character
{
public:
	
	int damage;


	Enemy();
	Enemy(SDL_Rect rect, SDL_Rect colrect, int imageNUMB, int healthB, int movementSpeedB,int damageB);
	void move(int direction);
	void jump(bool jumpHeld);
};

