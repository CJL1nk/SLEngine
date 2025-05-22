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
	StaticObject background = StaticObject(Position(500, 350, 0), spr);

	sf::Texture texture2("../textures/wood_1.jpg", false, sf::IntRect({0, 0}, {64, 64}));
	sf::Sprite spr2 = sf::Sprite(texture2);
	StaticObject wood = StaticObject(Position(0, 0, 1), spr2);
	wood.initHitbox();

	sf::Texture texture2_1("../textures/wood_1.jpg", false, sf::IntRect({0, 0}, {64, 64}));
	sf::Sprite spr2_1 = sf::Sprite(texture2_1);
	StaticObject wood2 = StaticObject(Position(300, 300, 1), spr2_1);
	wood2.initHitbox();

	// Button initialization
	sf::Texture texture3("../textures/button.png", false, sf::IntRect({0, 0}, {516, 516}));
	sf::Sprite spr3 = sf::Sprite(texture3);
	spr3.setScale(sf::Vector2f(0.2f, 0.2f));
	UI::Button btn = UI::Button(Position(120, 120, 0), spr3);

	btn.setOnPress([&spr3]() {spr3.setColor(sf::Color::Cyan);});
	btn.setOnRelease([&spr3]() {spr3.setColor(sf::Color::White);});
	btn.setOnHover([&spr3]() {spr3.setScale(sf::Vector2f(0.22f, 0.22f));});
	btn.setOffHover([&spr3]() {spr3.setScale(sf::Vector2f(0.2f, 0.2f));});

	// Create scene and add our object
	UI::Scene scene = UI::Scene();
	scene.addObject(background);
	scene.addObject(wood);
	scene.addObject(wood2);
	scene.addObject(wood2); // Should NOT add to scene because it's already there
	scene.addUIObject(btn);

	// Create window and set its scene, scene can also be passed as another arg to constructor
	UI::GameWindow window = UI::GameWindow(480, 480, 60, "New Window!");
	window.setScene(scene);

	// Some nice music to play
	sf::SoundBuffer buffer("../audios/Crateman.mp3");
	sf::Sound sound(buffer);
	sound.setLooping(true);
	sound.play();

	while (window.isOpen()) {

		window.update();
		window.drawScene();

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Escape)) {
			window.close();
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W)) {
			wood.move(Position(0, -1.5));
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A)) {
			wood.move(Position(-1.5, 0));
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S)) {
			wood.move(Position(0, 1.5));
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D)) {
			wood.move(Position(1.5, 0));
		}

		background.move(Position(-0.5, 0));
		wood2.rotate(0.5);

		if (wood.collidesWith(wood2)) {
			spr3.setColor(sf::Color::Blue);
			scene.removeObject(wood2);
		} else {
		}
	}

	return 0x00000000;
}
