#ifndef STATE_H
#define STATE_H

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <fstream>
#include <sstream>

#include <SFML\Graphics.hpp>
#include <SFML\Window.hpp>
#include <SFML\System.hpp>
#include <SFML\Audio.hpp>
#include <SFML\Network.hpp>

class State
{
private:
	std::vector<sf::Texture*> imgTextures;


public:
	State();
	virtual ~State();

	virtual void fnUpdate() = 0; //Makes function a pure virtual
	virtual void fnRender() = 0;
};

#endif