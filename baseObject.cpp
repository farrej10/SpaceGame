#include "baseObject.h"


BaseObject::BaseObject()
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
}


BaseObject::BaseObject(SDL_Rect rect, SDL_Rect colrect, int imageNUMB)
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
}

void BaseObject::getPlace()
{
	cout << "(" << objectPlace.x << "," << objectPlace.y << ")" << endl;
}
