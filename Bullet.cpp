#include "Bullet.h"



Bullet::Bullet()
{
	objectPlace.x = 0;
	objectPlace.y = 0;
	objectPlace.h = 0;
	objectPlace.w = 0;

	objectCollisionBox.x = 0;
	objectCollisionBox.y = 0;
	objectCollisionBox.h = 0;
	objectCollisionBox.w = 0;
	imageNUM = 0;
	bulletDamage = 0;
}

Bullet::Bullet(SDL_Rect rect, SDL_Rect colrect, int imageNUMB, int bulletDamageB)
{
	objectPlace.x = rect.x;
	objectPlace.y = rect.y;
	objectPlace.h = rect.h;
	objectPlace.w = rect.w;

	objectCollisionBox.x = colrect.x;
	objectCollisionBox.y = colrect.y;
	objectCollisionBox.h = colrect.h;
	objectCollisionBox.w = colrect.w;

	imageNUM = imageNUMB;

	bulletDamage = bulletDamageB;
}

void Bullet::move(bool direction)// false left to right, true right to left
{
	if (direction == false)
	{
		objectPlace.x = objectPlace.x + 6;
	}

	if (direction == true)
	{
		objectPlace.x = objectPlace.x - 6;
	}

}

Bullet Bullet::returnBullet()
{
	Bullet temp;
	temp.bulletDamage = bulletDamage;
	temp.imageNUM = imageNUM;
	temp.objectCollisionBox = objectCollisionBox;
	temp.objectPlace = objectPlace;
	return temp;
}