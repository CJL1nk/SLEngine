//
// Created by CJ on 5/20/2025.
//

#include <iostream>

#include "includes.h"
#include "objects/StaticObject.h"
#include "menu/GameWindow.h"
#include "menu/Scene.h"
#include "menu/StaticTexture.h"

#include <SFML/Audio.hpp>

int main() {

	// Create object
	sf::Texture texture("../textures/landscape.png", false, sf::IntRect({0, 0}, {0, 0}));
	sf::Sprite spr = sf::Sprite(texture);
	StaticObject background = StaticObject(Position(0, 0, 0), spr);

	sf::Texture texture2("../textures/wood_1.jpg", false, sf::IntRect({0, 0}, {64, 64}));
	sf::Sprite spr2 = sf::Sprite(texture2);
	StaticObject wood = StaticObject(Position(100, 100, 1), spr2);

	sf::Texture texture3("../textures/button.png", false, sf::IntRect({0, 0}, {516, 516}));
	sf::Sprite spr3 = sf::Sprite(texture3);
	spr3.setScale(sf::Vector2f(0.2, 0.2));
	UI::StaticTexture btn = UI::StaticTexture(Position(120, 120, 0), spr3);

	// Create scene and add our object
	UI::Scene scene = UI::Scene();
	scene.addObject(background);
	scene.addObject(wood);
	scene.addUIObject(btn);

	// Create window and set its scene, scene can also be passed as another arg to constructor
	UI::GameWindow window = UI::GameWindow(480, 480, 60, "New Window!");
	window.setScene(scene);

	// Some nice music to play
	sf::SoundBuffer buffer("../audios/dark souls intro thing.mp3");
	sf::Sound sound(buffer);
	sound.setLooping(true);
	sound.play();

	while (window.isOpen()) {

		window.pollEvents();
		window.drawScene();

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Escape)) {
			window.close();
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W)) {
			wood.move(Position(0, -0.5));
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A)) {
			wood.move(Position(-0.5, 0));
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S)) {
			wood.move(Position(0, 0.5));
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D)) {
			wood.move(Position(0.5, 0));
		}

		background.move(Position(-0.5, 0));
	}

	return 0;
}
