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

	// Initialize scene
	UI::Scene scene = UI::Scene();

	// Create window and set its scene, scene can also be passed as another arg to constructor
	UI::GameWindow window = UI::GameWindow(480, 480, 60, "New Window!");
	window.setScene(scene);

	// Create some objects
	sf::Texture appleTexture("../textures/apple.png", false, sf::IntRect({0, 0}, {0, 0}));
	sf::Sprite appleSprite(appleTexture);
	StaticObject apple(Position(200, 240, 1), appleSprite);
	apple.initHitbox();
	apple.setScale(0.01f, 0.01f);
	scene.addObject(apple);

	sf::Texture pineappleTexture("../textures/pineapple.png", false, sf::IntRect({0, 0}, {0, 0}));
	sf::Sprite pineappleSprite(pineappleTexture);
	StaticObject pineapple(Position(280, 240, 2), pineappleSprite);
	pineapple.initHitbox();
	pineapple.setScale(0.02f, 0.02f);
	scene.addObject(pineapple);

	sf::Texture texture("../textures/landscape.png", false, sf::IntRect({0, 0}, {0, 0}));
	sf::Sprite spr = sf::Sprite(texture);
	StaticObject background = StaticObject(Position(670, 350, 0), spr);
	scene.addObject(background);

	// Create our Buttons
	sf::Texture arrowTexture("../textures/arrowBtn.png", false, sf::IntRect({0, 0}, {0, 0}));

	sf::Sprite upArrowSprite(arrowTexture);
	upArrowSprite.setScale({0.11f, 0.11f});
	UI::Button upArrowBtn(Position(400, 380), upArrowSprite);
	scene.addUIObject(upArrowBtn);

	upArrowBtn.setOnPress([&upArrowSprite, &pineapple]() {
		upArrowSprite.setColor(sf::Color::Green);
		pineapple.move(0.f, -5.0f);
	});
	upArrowBtn.setOnRelease([&upArrowSprite]() {upArrowSprite.setColor(sf::Color::White);});
	upArrowBtn.setOnHover([&upArrowSprite]() {upArrowSprite.setScale({0.12f, 0.12f});});
	upArrowBtn.setOffHover([&upArrowSprite]() {upArrowSprite.setScale({0.11f, 0.11f});});

	sf::Sprite downArrowSprite(arrowTexture);
	downArrowSprite.setRotation(sf::degrees(180.0f));
	downArrowSprite.setScale({0.11f, 0.11f});
	UI::Button downArrowBtn(Position(400, 440), downArrowSprite);
	scene.addUIObject(downArrowBtn);

	downArrowBtn.setOnPress([&downArrowSprite, &pineapple]() {
		downArrowSprite.setColor(sf::Color::Green);
		pineapple.move(0.f, 5.0f);
	});
	downArrowBtn.setOnRelease([&downArrowSprite]() {downArrowSprite.setColor(sf::Color::White);});
	downArrowBtn.setOnHover([&downArrowSprite]() {downArrowSprite.setScale({0.12f, 0.12f});});
	downArrowBtn.setOffHover([&downArrowSprite]() {downArrowSprite.setScale({0.11f, 0.11f});});

	sf::Sprite leftArrowSprite(arrowTexture);
	leftArrowSprite.setRotation(sf::degrees(-90.0f));
	leftArrowSprite.setScale({0.11f, 0.11f});
	UI::Button leftArrowBtn(Position(350, 410), leftArrowSprite);
	scene.addUIObject(leftArrowBtn);

	leftArrowBtn.setOnPress([&leftArrowSprite, &pineapple]() {
		leftArrowSprite.setColor(sf::Color::Green);
		pineapple.move(-5.f, -0.0f);
	});
	leftArrowBtn.setOnRelease([&leftArrowSprite]() {leftArrowSprite.setColor(sf::Color::White);});
	leftArrowBtn.setOnHover([&leftArrowSprite]() {leftArrowSprite.setScale({0.12f, 0.12f});});
	leftArrowBtn.setOffHover([&leftArrowSprite]() {leftArrowSprite.setScale({0.11f, 0.11f});});

	sf::Sprite rightArrowSprite(arrowTexture);
	rightArrowSprite.setRotation(sf::degrees(90.0f));
	rightArrowSprite.setScale({0.11f, 0.11f});
	UI::Button rightArrowBtn(Position(450, 410), rightArrowSprite);
	scene.addUIObject(rightArrowBtn);

	rightArrowBtn.setOnPress([&rightArrowSprite, &pineapple]() {
		rightArrowSprite.setColor(sf::Color::Green);
		pineapple.move(5.f, -0.0f);
	});
	rightArrowBtn.setOnRelease([&rightArrowSprite]() {rightArrowSprite.setColor(sf::Color::White);});
	rightArrowBtn.setOnHover([&rightArrowSprite]() {rightArrowSprite.setScale({0.12f, 0.12f});});
	rightArrowBtn.setOffHover([&rightArrowSprite]() {rightArrowSprite.setScale({0.11f, 0.11f});});

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
			apple.move(Position(0, -1.5));
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A)) {
			apple.move(Position(-1.5, 0));
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S)) {
			apple.move(Position(0, 1.5));
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D)) {
			apple.move(Position(1.5, 0));
		}

		background.move(Position(-0.5, 0));

		if (apple.collidesWith(pineapple)) {
			appleSprite.setColor(sf::Color::Blue);
		} else {
			appleSprite.setColor(sf::Color::White);
		}
	}

	return 0x00000000;
}
