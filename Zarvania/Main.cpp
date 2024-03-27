#include "SFML/Graphics.hpp"
#include <iostream>
#include "Player.h"
#include "Background.h"

#define SCREEN_WIDTH 1920
#define SCREEN_HEIGHT 1080

const bool isFullScreen = false;

mac::Player maria;
mac::Background gameBackground;

int main()
{
	sf::RenderWindow window(sf::VideoMode(SCREEN_WIDTH, SCREEN_HEIGHT), "Zarvania", isFullScreen ? sf::Style::Fullscreen : sf::Style::Default);

	//make texture for player
	sf::Texture playerTexture;

	//make a texture for background
	sf::Texture backgroundTexture;

	//set the textures image
	if (!playerTexture.loadFromFile("mariahead.png"))
	{
		std::cout << "There was an error loading the texture!";
	}
	if (!backgroundTexture.loadFromFile("background.jpg"))
	{
		std::cout << "There was an error loading the texture!";
	}

	//set player texture
	maria.setTexture(playerTexture);

	//set background texture
	gameBackground.setTexture(backgroundTexture);

	while(window.isOpen())
		{
			sf::Event event;

			while(window.pollEvent(event))
				{
					if(event.type == sf::Event::Closed)
					{
						window.close();
					}

					if (event.type == sf::Event::KeyPressed)
					{
						if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
						{
							maria.move(0, -10);
						}
						else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
						{
							maria.move(0, 10);
						}
						if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
						{
							maria.move(-10, 0);
						}
						else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
						{
							maria.move(10, 0);
						}
					}
				}

			//clear the window to black
			window.clear(sf::Color::Black);

			window.draw(gameBackground);

			window.draw(maria);

			window.display();
		}

	return 0;
}
