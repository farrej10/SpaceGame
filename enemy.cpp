#include "enemy.h"



Enemy::Enemy()
{
	objectPlace.x = 0;
	objectPlace.y = 0;
	objectPlace.h = 0;
	objectPlace.w = 0;

	objectCollisionBox.x = 0;
	objectCollisionBox.y = 0;
	objectCollisionBox.h = 0;
	objectCollisionBox.w = 0;

	health = 0;
	imageNUM = 0;
	damage = 0;
}

Enemy::Enemy(SDL_Rect rect, SDL_Rect colrect, int imageNUMB, int healthB, int movementSpeedB, int damageB)
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
	health = healthB;
	movementSpeed = movementSpeedB;
	damage = damageB;
}

void Enemy::move(int direction)
{
	switch (direction)

	{
	case 0:
		objectPlace.x = objectPlace.x + movementSpeed;
		//cout << "(" << objectPlace.x << "," << objectPlace.y << ")" << endl;
		break;
	case 1:
		objectPlace.x = objectPlace.x - movementSpeed;
		//cout << "(" << objectPlace.x << "," << objectPlace.y << ")" << endl;
		break;
	case 2:
		objectPlace.y = objectPlace.y - movementSpeed;
		//cout << "(" << objectPlace.x << "," << objectPlace.y << ")" << endl;
		break;
	case 3:
		objectPlace.y = objectPlace.y + movementSpeed;
		//cout << "(" << objectPlace.x << "," << objectPlace.y << ")" << endl;
		break;
	case 4:
		objectPlace.x = objectPlace.x + movementSpeed / 2;
		objectPlace.y = objectPlace.y - movementSpeed / 2;
		//cout << "(" << objectPlace.x << "," << objectPlace.y << ")" << endl;
		break;
	case 5:
		objectPlace.x = objectPlace.x + movementSpeed / 2;
		objectPlace.y = objectPlace.y + movementSpeed / 2;
		//cout << "(" << objectPlace.x << "," << objectPlace.y << ")" << endl;
		break;
	case 6:
		objectPlace.x = objectPlace.x - movementSpeed / 2;
		objectPlace.y = objectPlace.y - movementSpeed / 2;
		//cout << "(" << objectPlace.x << "," << objectPlace.y << ")" << endl;
		break;
	case 7:
		objectPlace.x = objectPlace.x - movementSpeed / 2;
		objectPlace.y = objectPlace.y + movementSpeed / 2;
		//cout << "(" << objectPlace.x << "," << objectPlace.y << ")" << endl;
		break;


	}



}