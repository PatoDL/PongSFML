#include "SFML/Graphics.hpp"
#include "STP/TMXLoader.hpp"

int main()
{
	sf::RenderWindow window(sf::VideoMode(800, 1600), "STP Example");
	tmx::TileMap map("res/atr.tmx");

	map.ShowObjects(); // Display all the layer objects.

	//map.GetLayer("World").visible = false; // Hide a Layer named World

										   

	sf::View view1(sf::FloatRect(200.f, 200.f,800.f,600.f));
	sf::View view2(sf::Vector2f(400.f, 300.f), sf::Vector2f(800.f, 600.f));

	window.setView(view2);


	while (window.isOpen()) {    // Start the game loop
		// Process events
		sf::Event event;
		while (window.pollEvent(event)) {
			// Close window : exit
			if (event.type == sf::Event::Closed)
				window.close();
		}

		sf::View currentview = window.getView();

		// Clear screen
		window.clear();
		// Draw the map
		window.draw(window);
		// Update the window
		window.display();
	}

	return EXIT_SUCCESS;
}