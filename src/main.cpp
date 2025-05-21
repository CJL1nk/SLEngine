//
// Created by CJ on 5/20/2025.
//

#include <iostream>

#include "includes.h"
#include "objects/StaticObject.h"
#include "menu/GameWindow.h"
#include "menu/Scene.h"

int main() {

	int frame = 0;

	// Create object
	sf::Texture texture("textures/landscape.png", false, sf::IntRect({0, 0}, {0, 0}));
	sf::Sprite spr = sf::Sprite(texture);
	StaticObject background = StaticObject(Position(0, 0, 0), spr);

	sf::Texture texture2("textures/wood_1.jpg", false, sf::IntRect({0, 0}, {16, 16}));
	sf::Sprite spr2 = sf::Sprite(texture2);
	StaticObject wood = StaticObject(Position(100, 100, 1), spr2);

	// Create scene and add our object
	UI::Scene scene = UI::Scene();
	scene.addObject(background);
	scene.addObject(wood);

	// Create window and set its scene, scene can also be passed as another arg to constructor
	UI::GameWindow window = UI::GameWindow(480, 480, 60, "New Window!");
	window.setScene(scene);

	while (window.isOpen()) {

		window.pollEvents();
		window.drawScene();

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Escape)) {
			window.close();
		}

		spr.move(sf::Vector2f(-0.2, 0));
	}

	return 0;
}
