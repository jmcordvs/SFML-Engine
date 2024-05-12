#include "State.h"
#include "Game.h"

#include <Windows.h>

// Static functions

// Initializer functions

// Constructors and Destructors

void Game::fnInitializeWindow()
{
	std::ifstream iFileStream("Config/window.ini");
	std::string sTitle = "None";
	sf::VideoMode sfWindowBounds(800, 600);

	unsigned uFrameRateLimit = 120;

	bool bVerticalSyncEnabled = false;

	if (iFileStream.is_open())
	{
		std::getline(iFileStream, sTitle);
		iFileStream >> sfWindowBounds.width, sfWindowBounds.height;
		iFileStream >> uFrameRateLimit;
		iFileStream >> bVerticalSyncEnabled;
	}

	this->sfWindow = new sf::RenderWindow(sfWindowBounds, sTitle);
	this->sfWindow->setFramerateLimit(uFrameRateLimit);
	this->sfWindow->setVerticalSyncEnabled(bVerticalSyncEnabled);

	// Set an image icon for the window
	sf::Image imgIcon;

	if (!imgIcon.loadFromFile("C:\\Users\\ryzen\\Downloads\\imgIcon.png"))
	{
		// Error handling, TODO
	}

	//Get all the properties of the image icon
	sfWindow->setIcon(imgIcon.getSize().x, imgIcon.getSize().y, imgIcon.getPixelsPtr());
}

Game::Game()
{
	this->fnInitializeWindow();
}

Game::~Game()
{
	delete this->sfWindow;
}

// Functions

void Game::fnUpdateDeltaTime()
{
	//Updates the flDeltaTime variable with the time it takes to update and render 1 frame
	this->flDeltaTime = this->deltaTimeClock.restart().asSeconds();
}

void Game::fnUpdateSFMLEvents()
{
	while (this->sfWindow->pollEvent(this->sfEvent))
	{
		if (this->sfEvent.type == sf::Event::Closed)
			this->sfWindow->close();
	}
}

void Game::fnUpdate()
{
	this->fnUpdateSFMLEvents();

	int iSum = 0;

	for (size_t i = 0; i < 1000000000; i++)
	{
		iSum += i;
	}
}

void Game::fnRender()
{
	this->sfWindow->clear();

	this->sfWindow->display();

	this->sfWindow->requestFocus();
}

void Game::fnRun()
{
	while (this->sfWindow->isOpen())
	{
		this->fnUpdateDeltaTime();
		this->fnUpdate();
		this->fnRender();
	}

}