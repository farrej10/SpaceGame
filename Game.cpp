#include "Game.h"



using namespace std;


bool Game::initialize()
{
	ENEMYSPAWNRATE = 500;
	if (SDL_Init(SDL_INIT_VIDEO) < 0)
	{
		cout << "SDL could not be initialized SDL ERROR: ";
		cout << SDL_GetError();
		return false;
	}

	window = SDL_CreateWindow("Game", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);

	if (window == NULL)
	{
		cout << "Window could not be created, SDL ERROR: " << SDL_GetError();
		return false;
	}

	int imgFlags = IMG_INIT_PNG;
	if (!IMG_Init(imgFlags) & imgFlags)
	{
		cout << "SDL_image could not initialize, SDL ERROR: " << IMG_GetError();
		return false;
	}

	renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
	if (renderer == NULL)
	{
		cout << "renderer could not be created SDL ERROR: " << SDL_GetError();
		return false;
	}

	
	im.initialize(renderer);

	return true;
}

void Game::close()
{

	SDL_DestroyWindow(window);
	SDL_DestroyRenderer(renderer);


	window = NULL;
	renderer = NULL;

	IMG_Quit();
	SDL_Quit();


}


void Game::loop()
{

	SDL_Event e;//checking keypress for exit
	bool exit = false;//opening/closing the game loop
	//rects used to make player,enemy and background sizes
	SDL_Rect playerSize = {10,216,64,64};
	SDL_Rect enemySize = { 360,240,64,64 };
	SDL_Rect playerColBox = {4,4,56,56};
	SDL_Rect enemyColBox = { 2,11,53,42 };
	SDL_Rect backgroundSize = {0,0,720,480};
	SDL_Rect backgroundColBox = { 0,0,0,0 };
	//rect used for random place
	SDL_Rect size;
	//making the player and background
	Player player1(playerSize, playerColBox, 1, 10, 6, 1);//settting up a player size colboxsize imageNum health  movementspeed gunDamage
	BaseObject background(backgroundSize, backgroundColBox, 4);//setting up a background object
	// Health Bar stuff
	SDL_Rect healthBarSize = { 5,5,25,202 };
	SDL_Rect healthBarColBox = { 0,0,0,0 };
	SDL_Rect healthShowingSize = { 320,140,100,805};//315,140,100,810
	BaseObject healthBar(healthBarSize, healthBarColBox, 6);
	SDL_Rect tempRect = healthShowingSize;

	//an array of keys being pressed
	const Uint8* currentKeyStates = SDL_GetKeyboardState(NULL);
	//setting current time and setting delay times to 0;
	int currentTime = SDL_GetTicks();
	int bullettime = 0;
	int spawntime = 0;

	//setting up an array of bullets and the number of bullets allowed
	const int NUMOFBULLETSALLOWED = 20;
	Bullet bulletArray[NUMOFBULLETSALLOWED];
	Bullet* bp = NULL;
	int bulletcounter = 0;

	//Enemy firstenemy(enemySize,enemyColBox,3,5,6,1); used for testing enemies

	//setting up pointer for the new enemies
	Enemy* newEnemyShipPointer=NULL;
	//setting the score player has to reach to increase the spawn rate
	int INCREASESPAWNRATE = 1;


	//making a list of enemies
	EnemyList enemyList;
	EnemyNode* temp = enemyList.head;


	//game loop while player score is less or equal to 100 and player's health is not 0
	while (!exit && player1.score <= 1000 && player1.health >0)
	{

		currentTime = SDL_GetTicks();//resetting time each loop

	



		while (SDL_PollEvent(&e) != 0) 
		{
			if (e.type == SDL_QUIT || e.key.keysym.sym == SDLK_ESCAPE)
				exit = true;

		}
			
		//resetting keystates
		currentKeyStates = SDL_GetKeyboardState(NULL);
		// MOVEMENT 0 right, 1 left, 2 up, 3 down, 4 upright, 5 downright, 6 upleft, 7 downleft
		if (currentKeyStates[SDL_SCANCODE_D] && currentKeyStates[SDL_SCANCODE_W])
			player1.move(4);
		else if (currentKeyStates[SDL_SCANCODE_D] && currentKeyStates[SDL_SCANCODE_S])
			player1.move(5);
		else if (currentKeyStates[SDL_SCANCODE_A] && currentKeyStates[SDL_SCANCODE_W])
			player1.move(6);
		else if (currentKeyStates[SDL_SCANCODE_A] && currentKeyStates[SDL_SCANCODE_S])
			player1.move(7);
		else if (currentKeyStates[SDL_SCANCODE_D])
			player1.move(0);
		else if (currentKeyStates[SDL_SCANCODE_A])
			player1.move(1);
		else if (currentKeyStates[SDL_SCANCODE_W])
			player1.move(2);
		else if (currentKeyStates[SDL_SCANCODE_S])
			player1.move(3);
		//spawns enemy when P is pressed used in testing
		if (currentKeyStates[SDL_SCANCODE_P])
		{
		

			if (currentTime - spawntime < 500)
			{
				cout << "Spaw Delay" << endl;
			}
			else
			{
				size = { 800,rand()%480,64,64 };

				newEnemyShipPointer = new Enemy(size, enemyColBox, 3, 2, 4, 1);
				enemyList.addNode(newEnemyShipPointer);
				spawntime = SDL_GetTicks();
			}
		}

		// fire bullets while space is pressed
		if (currentKeyStates[SDL_SCANCODE_SPACE])
		{

			if (currentTime - bullettime < 300)
			{
				cout << "Fire Delay" << endl;
			}
			else
			{

				if (bulletcounter == NUMOFBULLETSALLOWED)
					bulletcounter = 0;

				bp = player1.fire();
				bulletArray[bulletcounter] = bp->returnBullet();
				bulletcounter++;
				cout << bulletcounter << endl;
				bullettime = SDL_GetTicks();
			}
			
				
		}
			

		//checking FPS im limiting to 60 FPS
		if ((SDL_GetTicks() - currentTime) < 1000 / 60)
		{
			SDL_Delay(((1000 / 60) - (SDL_GetTicks() - currentTime)));
		}
		 
		//spawning enemies
		if (currentTime - spawntime < ENEMYSPAWNRATE)
		{
			//cout << "Spaw Delay" << endl;
		}
		else
		{
			cout << "SPAWNED" << endl;
			size = { 800,rand() % 480,64,64 };

			newEnemyShipPointer = new Enemy(size, enemyColBox, 3, 1, 4, 1);//size colsize imageNUM health movementspeed damage
			enemyList.addNode(newEnemyShipPointer);
			spawntime = SDL_GetTicks();
			
		}
		
		//increasing enemy spawn rate;
		if (player1.score > INCREASESPAWNRATE)
		{
			ENEMYSPAWNRATE -= 30;
			INCREASESPAWNRATE += 10;
		}


		//clearing renderer
		SDL_RenderClear(renderer);
	
		//rendering background texture
		im.drawMediaBaseObject(&background, renderer);

		//rendering bullet textures to screen
		for (int i=0;i<NUMOFBULLETSALLOWED;i++)
		{
			if (bulletArray[i].objectPlace.x != 0 )
			{
				im.drawMediaBaseObject(&bulletArray[i], renderer);
			}

		}
		//moving the bullets
		for (int i = 0; i<NUMOFBULLETSALLOWED; i++)
		{
			if (bulletArray[i].objectPlace.x != 0)
			{
				bulletArray[i].move(false);
			}
		}

		// drawing all the enemies to the screen
		temp = enemyList.head;
		while (temp != NULL)
		{

			im.drawMediaBaseObject(temp->theEnemy, renderer);
			temp = temp->nextEnemy;
		}
		
		//checking bullet collision
		temp = enemyList.head;
		while (temp != NULL)
		{
			for (int i = 0; i<NUMOFBULLETSALLOWED; i++)
			{
				if (bulletArray[i].objectPlace.x != 0)
				{
					if (temp != NULL)
					{
						if (collision(&bulletArray[i], temp->theEnemy))
						{
							
						
							bulletArray[i].objectPlace.x = 0;
							//decreasing health
							temp->theEnemy->health--;
							//if health 0 delete the ship
							if (temp->theEnemy->health <= 0)
							{
								enemyList.removeNode(temp);
								player1.score++;
								cout << "Ship Deleted" << endl;
								temp = NULL;
							}
						}
					}

				}
			}
			if (temp != NULL) 
			{
				temp = temp->nextEnemy;
			}
		}

		//moving all the enemies
		temp = enemyList.head;
		while (temp != NULL)
		{

			temp->theEnemy->move(1);
			temp = temp->nextEnemy;

		}
		// removing the enemies that are off the screen
		temp = enemyList.head;
		while (temp != NULL)
		{

			if (temp->theEnemy->objectPlace.x < -20)
			{
				enemyList.removeNode(temp);
				cout << "Ship Deleted" << endl;
				temp = NULL;
			}

			if (temp != NULL)
			{
				temp = temp->nextEnemy;
			}

		}

		//removing the enemies that hit the player
		temp = enemyList.head;
		while (temp != NULL)
		{

			if (collision(&player1, temp->theEnemy))
			{
				//decreasing the player health based on the damage caused by the enemy
				player1.health = player1.health - temp->theEnemy->damage;
				
				//decreasing health bar
				for (int i = 0; i < temp->theEnemy->damage; i++)
				{
					tempRect.y = tempRect.y + 80;
					tempRect.h = tempRect.h - 80;
					healthBar.objectPlace.y = healthBar.objectPlace.y + 20;
					healthBar.objectPlace.h = healthBar.objectPlace.h - 20;
				}

				//delete the ship
				enemyList.removeNode(temp);
				cout << "Ship Deleted" << endl;
				temp = NULL;

			}
			if (temp != NULL)
			{
				temp = temp->nextEnemy;
			}
	

		}
		
	
		//drawing health bar
		im.drawMediaBaseObject(&healthBar, renderer,&tempRect);


		//drawing the player
		im.drawMediaBaseObject(&player1, renderer);

	
		//Update Screen
		SDL_RenderPresent(renderer);
		
		PowerUp powerUp1;
		
	
		if (collision(&player1, &powerUp1))
		{
			player1.health += powerUp1.addedHealth;
			player1.movementSpeed += powerUp1.addedMovementSpeed;
			player1.gunDamage += powerUp1.addedGunDamage;

		}
		








	}
	//if player gets a score of 1000
	if (player1.score >= 1000) 
	{
		cout << "YOU GOT A SCORE 1000 YOU WIN!!!!!!!!!" << endl;
	}
	//if the player dies
	if (player1.health <= 0)
		cout << "YOU LOSE YOUR SCORE WAS: " << player1.score << endl;




	fstream outputFile;
	outputFile.open("ScoreSheet.txt",ios::out);
	if (!outputFile)
	{
		cout << "ERROR opening file" << endl;
	}

	outputFile << "Player score: " << player1.score << endl;
	
	outputFile.close();

}


bool Game::collision(BaseObject* bullet, BaseObject* enemyship)
{
	int top1 = bullet->objectPlace.y + bullet->objectCollisionBox.y;
	int bottom1 = bullet->objectPlace.y + bullet->objectCollisionBox.h + bullet->objectCollisionBox.y;
	int right1 = bullet->objectPlace.x + bullet->objectCollisionBox.x + bullet->objectCollisionBox.w;
	int left1 = bullet->objectPlace.x + bullet->objectCollisionBox.x;

	int top2 = enemyship->objectPlace.y + enemyship->objectCollisionBox.y;
	int bottom2 = enemyship->objectPlace.y + enemyship->objectCollisionBox.h + enemyship->objectCollisionBox.y;
	int right2 = enemyship->objectPlace.x + enemyship->objectCollisionBox.x + enemyship->objectCollisionBox.w;
	int left2 = enemyship->objectPlace.x + enemyship->objectCollisionBox.x;



	if (left1<right2 && right1 > left2 && top1 < bottom2 && bottom1 > top2)
	{
		return true;
	}
	else
		return false;
}