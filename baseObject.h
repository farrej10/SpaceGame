#pragma once
#include <SDL.h>
#include <SDL_image.h>
#include <string>
#include <iostream>
using namespace std;

class BaseObject {
public:
	SDL_Rect objectPlace;
	SDL_Rect objectCollisionBox;
	
	int imageNUM;// number will represent an image which is held in image manager, that way i only load image one rather than each time i make a character

	BaseObject();
	BaseObject(SDL_Rect rect, SDL_Rect colrect, int imageNUMB);
	void getPlace();
};
