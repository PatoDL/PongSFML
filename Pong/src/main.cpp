#include "SFML/Graphics.hpp"
#include "STP/TMXLoader.hpp"

#include "../Pong/juego.h"
int main()
{
	sf::RenderWindow window(sf::VideoMode(800, 600), "STP Example");
	tmx::TileMap map("res/atr.tmx");

	map.ShowObjects(); // Display all the layer objects.

	float recY = 0.f;

	sf::View view1;
	
	Juego::initSprite();

	sf::View view2(sf::Vector2f(400.f, 300.f), sf::Vector2f(800.f, 600.f));

	while (window.isOpen()) {    // Start the game loop
		// Process events
		sf::Event event;
		while (window.pollEvent(event)) {
			// Close window : exit
			if (event.type == sf::Event::Closed)
				window.close();
		}
		
		view1.reset(sf::FloatRect(0.f, recY, 800.f, 600.f));

		window.setView(view1);
		sf::View currentview = window.getView();
		
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
		{
			recY++;
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
		{
			recY--;
		}

		// Clear screen
		window.clear();
		// Draw the map
		window.draw(map);
		window.draw(Juego::drawSprite());
		// Update the window
		window.display();
	}

	return EXIT_SUCCESS;
}