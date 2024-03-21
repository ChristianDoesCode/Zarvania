#include "SFML/Graphics.hpp"

#define SCREEN_WIDTH 1920
#define SCREEN_HEIGHT 1080

const bool isFullScreen = false;



int main()
{
	sf::RenderWindow window(sf::VideoMode(SCREEN_WIDTH, SCREEN_HEIGHT), "Zarvania", isFullScreen ? sf::Style::Fullscreen : sf::Style::Default);

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
		}

	return 0;
}
