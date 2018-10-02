#include "Game.h"
using namespace std;



int main(int argc, char* args[])
{
	Game g0;
	//initialize
	if (!g0.initialize())
	{
		cout << "Could not initialize";
		return -1;
	}
	

	//run
	g0.loop();

	//free resources
	g0.close();




	int c;
	cin >> c;
	return 0;
}

