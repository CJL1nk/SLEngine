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
	sf::Texture texture = sf::Texture(sf::Texture("textures/wood_1.jpg"));
	sf::Sprite spr = sf::Sprite(texture);
	StaticObject woodObj = StaticObject(Position(400, 500, 0), spr);

	// Create scene and add our object
	UI::Scene scene = UI::Scene();
	scene.addObject(woodObj);

	// Create window and set its scene
	UI::GameWindow window = UI::GameWindow(1920, 1080, 60, "New Window!");
	window.setScene(scene);

	while (window.isOpen()) {
		window.drawScene();
	}

	return 0;
}
