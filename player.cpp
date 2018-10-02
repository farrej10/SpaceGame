#include "player.h"

void Player::move(int direction)// 0 right, 1 left, 2 up, 3 down, 4 upright, 5 downright, 6 upleft, 7 downleft
{
	switch (direction)
	
	{
	case 0:
		objectPlace.x = objectPlace.x + movementSpeed;
		cout << "(" << objectPlace.x << "," << objectPlace.y << ")" << endl;
		break;
	case 1:
		objectPlace.x = objectPlace.x - movementSpeed;
		cout << "(" << objectPlace.x << "," << objectPlace.y << ")" << endl;
		break;
	case 2:
		objectPlace.y = objectPlace.y - movementSpeed;
		cout << "(" << objectPlace.x << "," << objectPlace.y << ")" << endl;
		break;
	case 3:
		objectPlace.y = objectPlace.y + movementSpeed;
		cout << "(" << objectPlace.x << "," << objectPlace.y << ")" << endl;
		break;
	case 4:
		objectPlace.x = objectPlace.x + movementSpeed/2;
		objectPlace.y = objectPlace.y - movementSpeed/2;
		cout << "(" << objectPlace.x << "," << objectPlace.y << ")" << endl;
		break;
	case 5:
		objectPlace.x = objectPlace.x + movementSpeed/2;
		objectPlace.y = objectPlace.y + movementSpeed/2;
		cout << "(" << objectPlace.x << "," << objectPlace.y << ")" << endl;
		break;
	case 6:
		objectPlace.x = objectPlace.x - movementSpeed/2;
		objectPlace.y = objectPlace.y - movementSpeed/2;
		cout << "(" << objectPlace.x << "," << objectPlace.y << ")" << endl;
		break;
	case 7:
		objectPlace.x = objectPlace.x - movementSpeed/2;
		objectPlace.y = objectPlace.y + movementSpeed/2;
		cout << "(" << objectPlace.x << "," << objectPlace.y << ")" << endl;
		break;


	}
	

}

Player::Player()
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
	gunDamage = 0;
	score = 0;
}

Player::Player(SDL_Rect rect, SDL_Rect colrect, int imageNUMB, int healthB, int movementSpeedB, int gunDamageB)
{
	objectPlace.x = rect.x;
	objectPlace.y = rect.y;
	objectPlace.h = rect.h;
	objectPlace.w = rect.w;


	objectCollisionBox.x = colrect.x;
	objectCollisionBox.y = colrect.y;
	objectCollisionBox.h = colrect.h;
	objectCollisionBox.w = colrect.w;

	health = healthB;
	imageNUM = imageNUMB;
	movementSpeed = movementSpeedB;
	gunDamage = gunDamageB;
	score = 0;
}

Bullet * Player::fire()
{
	Bullet* temp;
	SDL_Rect bulletSize = { objectPlace.x + 64, objectPlace.y + 16,64,32 };
	SDL_Rect bulletColBox = { 10,15,35,10 };
	temp = new Bullet(bulletSize, bulletColBox, 5, 1);

	return temp;
}