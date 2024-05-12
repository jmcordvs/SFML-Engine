#ifndef GAME_H
#define GAME_H

#include <iostream>
#include <cstdlib>
#include <ctime>

#include <SFML\Graphics.hpp>
#include <SFML\Window.hpp>
#include <SFML\System.hpp>
#include <SFML\Audio.hpp>
#include <SFML\Network.hpp>

class Game
{
private:
	// Variables
	sf::RenderWindow  *sfWindow;
	sf::Event		  sfEvent;
	sf::Clock		  deltaTimeClock;

	float flDeltaTime;
	
	// Initialization
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