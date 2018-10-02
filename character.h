#pragma once
#include "baseObject.h"

class Character :public BaseObject 
{
public:
	int health;
	int movementSpeed;
	 


	Character();
	Character(SDL_Rect rect, SDL_Rect colrect, int imageNUMB, int healthB, int movementSpeedB);


};