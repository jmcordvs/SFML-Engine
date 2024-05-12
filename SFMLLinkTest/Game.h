#ifndef GAME_H
#define GAME_H

#include "State.h"

class Game
{
private:
	// Variables
	sf::RenderWindow  *sfWindow;
	sf::Event		  sfEvent;
	sf::Clock		  deltaTimeClock;

	float flDeltaTime;
	
	//Call the window initialization function
	void fnInitializeWindow();


public:
	// Constructors and Destructors
	Game();
	virtual ~Game();

	//Creating functions
	void fnUpdateDeltaTime();
	void fnUpdateSFMLEvents();
	void fnUpdate();
	void fnRender();
	void fnRun();
};

#endif