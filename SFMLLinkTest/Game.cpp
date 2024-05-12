#include "Game.h"

// Static functions

// Initializer functions

// Constructors and Destructors

void Game::fnInitializeWindow()
{
	this->sfWindow = new sf::RenderWindow(sf::VideoMode(800, 400), "SFML works!");

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
	this->flDeltaTime = this->deltaTimeClock.getElapsedTime().asSeconds();
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
}

void Game::fnRender()
{
	this->sfWindow->clear();

	this->sfWindow->display();

	this->sfWindow->requestFocus();

	//Set the title of the window, visible in the title bar
	this->sfWindow->setTitle("SFML Engine v0.1");
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