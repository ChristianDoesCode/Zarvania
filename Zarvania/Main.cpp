#include "SFML/Graphics.hpp"

#define SCREEN_WIDTH 1920
#define SCREEN_HEIGHT 1080

const bool isFullScreen = false;



int main()
{
	sf::RenderWindow window(sf::VideoMode(SCREEN_WIDTH, SCREEN_HEIGHT), "Zarvania", isFullScreen ? sf::Style::Fullscreen : sf::Style::Default);



	return 0;
}