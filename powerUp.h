#pragma once
#include "baseObject.h"


class PowerUp :public BaseObject
{
public:
	//attributes
	int addedHealth;
	int addedGunDamage;
	int addedMovementSpeed;
	//methods
	PowerUp();
	PowerUp(int addedHealth, int addedGunDamage, int addedMovementSpeed, SDL_Rect objectPlace, SDL_Rect collisionBox,int imageNum);



};