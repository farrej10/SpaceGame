#pragma once
#include <SDL.h>
#include <SDL_image.h>
#include <string>
#include <iostream>
#include "imagemanager.h"
#include "BaseObjectList.h"
#include "EnemyList.h"
#include <fstream>

class Game 
{
public:
	//attributes
	const int SCREEN_WIDTH = 720;
	const int SCREEN_HEIGHT = 480;
	int ENEMYSPAWNRATE;//used to increase and decrease the spawn rate
	SDL_Window* window = NULL;
	SDL_Renderer* renderer = NULL;
	Imagemanger im;




	//methods
	bool initialize();
	bool collision(BaseObject* bullet,BaseObject* enemyship);
	void loop();
	void close();


};