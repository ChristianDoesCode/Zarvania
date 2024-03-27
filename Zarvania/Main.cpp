#include "SFML/Graphics.hpp"
#include <iostream>
#include "Player.h"

#define SCREEN_WIDTH 1920
#define SCREEN_HEIGHT 1080

const bool isFullScreen = false;

mac::Player maria;

int main()
{
	sf::RenderWindow window(sf::VideoMode(SCREEN_WIDTH, SCREEN_HEIGHT), "Zarvania", isFullScreen ? sf::Style::Fullscreen : sf::Style::Default);

	//make texture for player
	sf::Texture playerTexture;

	//set the textures image
	if (!playerTexture.loadFromFile("mariahead.png"))
	{
		std::cout << "There was an error loading the texture!";
	}

	//set player texture
	maria.setTexture(playerTexture);

	while(window.isOpen())
		{
			sf::Event event;

			while(window.pollEvent(event))
				{
					if(event.type == sf::Event::Closed)
					{
						window.close();
					}
				}

			//clear the window to black
			window.clear(sf::Color::Black);

			window.draw(maria);

			window.display();
		}

	return 0;
}
