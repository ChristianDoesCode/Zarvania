#include "SFML/Graphics.hpp"
#include <iostream>
#include "Player.h"
#include "Background.h"

#define SCREEN_WIDTH 1920
#define SCREEN_HEIGHT 1080

const bool isFullScreen = false;

mac::Player player;
mac::Background gameBackground;

int main()
{
	sf::RenderWindow window(sf::VideoMode(SCREEN_WIDTH, SCREEN_HEIGHT), "Zarvania", isFullScreen ? sf::Style::Fullscreen : sf::Style::Default);

	//make texture for player
	sf::Texture playerTexture;

	//make a texture for background
	sf::Texture backgroundTexture;

	sf::Clock timer;
	sf::Time tickRate;

	//set the textures image
	if (!playerTexture.loadFromFile("amongus.png"))
	{
		std::cout << "There was an error loading the texture!";
	}
	if (!backgroundTexture.loadFromFile("background.jpg"))
	{
		std::cout << "There was an error loading the texture!";
	}

	//set player texture
	player.setTexture(playerTexture);
	player.setOrigin(player.getLocalBounds().width / 2, 0);

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
							sf::Vector2f movement(0, -10);

							tickRate = timer.restart();

							player.move(movement * ((float)tickRate.asMilliseconds() / 1000));
						}
						else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
						{
							player.move(0, 10);
						}
						if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
						{
							player.setScale(-1.0f, 1.0f);
							player.move(-10, 0);
						}
						else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
						{
							player.setScale(1.0f, 1.0f);
							player.move(10, 0);
						}
					}
				}

			//clear the window to black
			window.clear(sf::Color::Black);

			window.draw(gameBackground);

			window.draw(player);

			window.display();
		}

	return 0;
}
