#include "powerUP.h"

PowerUp::PowerUp()
{
	addedHealth = 0;
	addedGunDamage = 0;
	addedMovementSpeed = 0;
	imageNUM = 0;
}

PowerUp::PowerUp(int addedHealtht, int addedGunDamaget, int addedMovementSpeedt, SDL_Rect objectPlacet, SDL_Rect collisionBoxt, int imageNumt)
{
	addedHealth = addedHealtht;
	addedGunDamage = addedGunDamaget;
	addedMovementSpeed = addedMovementSpeedt;
	objectPlace = objectPlacet;
	objectCollisionBox = collisionBoxt;
	imageNUM = imageNumt;
}


