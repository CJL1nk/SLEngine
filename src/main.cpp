//
// Created by CJ on 5/20/2025.
//

#include "includes.h"

int main() {

	sf::Vector2u windowSize = sf::Vector2u(1920, 1080);
	sf::RenderWindow window(sf::VideoMode(windowSize), "Window");
	window.setFramerateLimit(60);

	while (window.isOpen()) {

		while (const std::optional event = window.pollEvent()) {
			// Request for closing the window
			if (event->is<sf::Event::Closed>()) window.close();
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Escape)) window.close();
		}

		window.clear(sf::Color::Black);
		window.display();
	}

	return 0;
}
