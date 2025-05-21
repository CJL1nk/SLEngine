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
	sf::Texture texture("textures/wood_1.jpg", false, sf::IntRect({0, 0}, {128, 128}));
	sf::Sprite spr = sf::Sprite(texture);
	StaticObject woodObj = StaticObject(Position(300, 300, 0), spr);

	// Create scene and add our object
	UI::Scene scene = UI::Scene();
	scene.addObject(woodObj);

	// Create window and set its scene, scene can also be passed as another arg to constructor
	UI::GameWindow window = UI::GameWindow(480, 480, 60, "New Window!");
	window.setScene(scene);

	while (window.isOpen()) {

		window.pollEvents();
		window.drawScene();

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Escape)) {
			window.close();
		}
	}

	return 0;
}
