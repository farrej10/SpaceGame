#pragma once
#include <SDL.h>
#include <SDL_image.h>
#include <string>
#include <iostream>
#include "player.h"
#include "Bullet.h"
#include "enemy.h"
#include "powerUp.h"

using namespace std;
class Imagemanger
{
public:
	//all the textures
	SDL_Texture* spaceship;
	SDL_Texture* planet;
	SDL_Texture* enemyShip;
	SDL_Texture* noImage;
	SDL_Texture* outerSpace;
	SDL_Texture* bullet;
	SDL_Texture* healthBar;


	void initialize(SDL_Renderer* renderer);
	SDL_Texture* LoadTexture(string filename, SDL_Renderer* renderer);
	bool loadMedia(SDL_Renderer* renderer);

	void drawMediaBaseObject(BaseObject* baseObjectToRender, SDL_Renderer* renderer);
	void drawMediaBaseObject(BaseObject* baseObjectToRender, SDL_Renderer* renderer, SDL_Rect* objectSize);

};