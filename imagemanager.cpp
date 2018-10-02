#include "imagemanager.h"
using namespace std;

void Imagemanger::initialize(SDL_Renderer* renderer)
{
	loadMedia(renderer);
}


bool Imagemanger::loadMedia(SDL_Renderer* renderer)
{



	spaceship = LoadTexture("speedship.png", renderer);
	if (spaceship == NULL)
	{
		cout << "Failed to load PNG image";
		return false;
	}


	planet = LoadTexture("planet.png", renderer);
	if (planet == NULL)
	{
		cout << "Failed to load PNG image", renderer;
		return false;
	}

	enemyShip = LoadTexture("enemyShip.png", renderer);
	if (enemyShip == NULL)
	{
		cout << "Failed to load PNG image";
		return false;
	}

	noImage = LoadTexture("noimagenum.png", renderer);
	if (noImage == NULL)
	{
		cout << "Failed to load PNG image";
		return false;
	}

	outerSpace = LoadTexture("Outerspace.png", renderer);
	if (outerSpace == NULL)
	{
		cout << "Failed to load PNG image";
		return false;
	}

	bullet = LoadTexture("bullet.png", renderer);
	if (bullet == NULL)
	{
		cout << "Failed to load PNG image";
		return false;
	}

	healthBar = LoadTexture("healthbar.png", renderer);
	if (healthBar == NULL)
	{
		cout << "Failed to load PNG image";
		return false;
	}

	return true;
}

SDL_Texture * Imagemanger::LoadTexture(string filename, SDL_Renderer* renderer)
{	//final image
	SDL_Texture* newTexture = NULL;
	//loading image
	SDL_Surface* loadedSurface = IMG_Load(filename.c_str());
	//error checking
	if (loadedSurface == NULL)
	{
		cout << "Unable to load image, SDL_Image ERROR: " << filename << IMG_GetError();
	}

	newTexture = SDL_CreateTextureFromSurface(renderer, loadedSurface);
	if (newTexture == NULL)
	{
		cout << "Unable to create texture, SDL_Image ERROR: " << filename << " " << SDL_GetError();
	}

	SDL_FreeSurface(loadedSurface);

	return newTexture;
}



void Imagemanger::drawMediaBaseObject(BaseObject*  baseObjectToRender, SDL_Renderer* renderer)
{
	SDL_Texture* tempTexture = NULL;
	SDL_Point point;
	point.x = 32;
	point.y = 32;
	int tempImageNum = baseObjectToRender->imageNUM;
	SDL_Rect tempRect = baseObjectToRender->objectPlace;
	switch (tempImageNum)
	{
	case 0:
		tempTexture = noImage;
		SDL_RenderCopy(renderer, tempTexture, NULL, &tempRect);
		break;
	case 1:
		tempTexture = spaceship;
		SDL_RenderCopyEx(renderer, tempTexture, NULL, &tempRect, 90, &point, SDL_FLIP_NONE);
		break;
	case 2:
		tempTexture = planet;
		SDL_RenderCopy(renderer, tempTexture, NULL, &tempRect);
		break;
	case 3:
		tempTexture = enemyShip;
		SDL_RenderCopyEx(renderer, tempTexture, NULL, &tempRect, -90, &point, SDL_FLIP_NONE);
		break;
	case 4:
		tempTexture = outerSpace;
		SDL_RenderCopy(renderer, tempTexture, NULL, &tempRect);
		break;
	case 5:
		tempTexture = bullet;
		SDL_RenderCopy(renderer, tempTexture, NULL, &tempRect);
		break;
	case 6:
		tempTexture = healthBar;
		SDL_RenderCopy(renderer, tempTexture, NULL, &tempRect);
		break;
	}

}

void Imagemanger::drawMediaBaseObject(BaseObject*  baseObjectToRender, SDL_Renderer* renderer,SDL_Rect* objectSize)
{
	SDL_Texture* tempTexture = NULL;
	SDL_Point point;
	point.x = 32;
	point.y = 32;
	int tempImageNum = baseObjectToRender->imageNUM;
	SDL_Rect tempRect = baseObjectToRender->objectPlace;
	switch (tempImageNum)
	{
	case 0:
		tempTexture = noImage;
		SDL_RenderCopy(renderer, tempTexture, NULL, &tempRect);
		break;
	case 1:
		tempTexture = spaceship;
		SDL_RenderCopyEx(renderer, tempTexture, NULL, &tempRect, 90, &point, SDL_FLIP_NONE);
		break;
	case 2:
		tempTexture = planet;
		SDL_RenderCopy(renderer, tempTexture, NULL, &tempRect);
		break;
	case 3:
		tempTexture = enemyShip;
		SDL_RenderCopyEx(renderer, tempTexture, NULL, &tempRect, -90, &point, SDL_FLIP_NONE);
		break;
	case 4:
		tempTexture = outerSpace;
		SDL_RenderCopy(renderer, tempTexture, NULL, &tempRect);
		break;
	case 5:
		tempTexture = bullet;
		SDL_RenderCopy(renderer, tempTexture, NULL, &tempRect);
		break;
	case 6:
		tempTexture = healthBar;
		SDL_RenderCopy(renderer, tempTexture,objectSize, &tempRect);
		break;
	}

}
