//
// Created by CJ on 5/20/2025.
//

#include <iostream>

#include "includes.h"
#include "objects/StaticObject.h"

int main() {

	sf::Vector2u windowSize = sf::Vector2u(1920, 1080);
	sf::RenderWindow window(sf::VideoMode(windowSize), "Window");
	window.setFramerateLimit(60);

	sf::Texture texture("textures/wood_1.jpg", false, sf::IntRect({0, 0}, {128, 128}));
	sf::Sprite sprite = sf::Sprite(texture);

	StaticObject obj = StaticObject(Position(100.0f, 100.0f, 0), sprite);
	obj.initHitbox();

	std::cout << obj.getHitbox().getWidth() << std::endl
	<< obj.getHitbox().getHeight() << std::endl;

	while (window.isOpen()) {

		while (const std::optional event = window.pollEvent()) {
			// Request for closing the window
			if (event->is<sf::Event::Closed>()) window.close();
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Escape)) window.close();
		}

		window.clear(sf::Color::Black);
		window.draw(sprite);
		window.display();
	}

	return 0;
}
