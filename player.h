#pragma once
#include "character.h"
#include "Bullet.h"

class Player :public Character
{
public:
	int gunDamage;
	int score;


	Player();
	Player(SDL_Rect rect, SDL_Rect colrect, int imageNUMB, int healthB, int movementSpeedB, int gunDamageB);
	void move(int direction);
	Bullet* fire();
	void jump(bool jumpHeld);

};