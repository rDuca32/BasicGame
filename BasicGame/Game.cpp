#include "Game.h"

#include "Player.h"
#include "Enemy.h"
#include "Sword.h"
#include "Math.h"
#include <SFML/Graphics.hpp>
#include <iostream>

using namespace std;
using namespace sf;

Game::Game()
	: window(VideoMode({ 1280, 720 }), "Game"), gameState(MENU), gameModeText(font, "Menu"),
	playerTexture(), enemyTexture(), swordTexture(), playerSprite(playerTexture), enemySprite(enemyTexture), swordSprite(swordTexture), player(playerTexture), enemies(), sword(swordTexture)
{
	// Load font 
	if (!font.openFromFile("fonts/PlayfulBoxes.otf")) {
		cerr << "Failed to load font!" << endl;
	}

	// Load textures
	if (!playerTexture.loadFromFile("images/Player.png")) {
		cerr << "Failed to load player texture!" << endl;
	}
	if (!enemyTexture.loadFromFile("images/Enemy.png")) {
		cerr << "Failed to load enemy texture!" << endl;
	}
	if (!swordTexture.loadFromFile("images/Sword.png")) {
		cerr << "Failed to load sword texture!" << endl;
	}

	// Set up sprites
	playerSprite.setTexture(playerTexture);
	enemySprite.setTexture(enemyTexture);
	swordSprite.setTexture(swordTexture);

	// Initialize game objects with textures
	player = Player(playerTexture);
	for (int i = 0; i < 5; ++i) {
		enemies.emplace_back(enemyTexture, Vector2f(100 + i * 150, 300 + i * 50));
	}
	sword = Sword(swordTexture);

	// Optionally set up gameModeText if used
	gameModeText.setFont(font);
	gameModeText.setCharacterSize(24);
	gameModeText.setFillColor(Color::Black);
	gameModeText.setPosition(Vector2f(10, 40));
}

Game::~Game() {
	// Resources will be automatically cleaned up by SFML
}

void Game::run() {

	Clock clock;

	while (window.isOpen()) {
		handleEvents();

		switch (gameState) {
		case PLAYING:
			updatePlaying(clock);
			renderPlaying();
			break;
		case MENU:
			renderMenu();
			break;
		default:
			cerr << "Unknown game state!" << endl;
			break;
		}
	}
}

void Game::handleEvents() {
	while (const optional<Event> event = window.pollEvent()) {
		if (event->is<Event::Closed>()) {
			window.close();
		}
		if (event->is<Event::KeyPressed>()) {
			const auto* keyEvent = event->getIf<Event::KeyPressed>();
			if (keyEvent && keyEvent->code == Keyboard::Key::Escape) {
				if (gameState == PLAYING) {
					gameState = MENU;
				}
				else if (gameState == MENU) {
					gameState = PLAYING;
				}
			}
		}
	}
}

void Game::updatePlaying(Clock& clock) {
	float dt = clock.restart().asSeconds();

	player.handleInput(dt);
	Vector2f mousePos = (Vector2f)Mouse::getPosition(window);
	sword.update(player.getPosition(), mousePos);

	for (auto& enemy : enemies) {
		float dist = Math::vLength(enemy.getPosition() - sword.getPosition());
		if (dist < 160.0f && !enemy.isDead()) {
			enemy.takeDamage(player.getDamage(), dt);
			if (enemy.isDead()) {
				enemy.respawn();
			}
		}
		enemy.update(player.getPosition(), dt);
	}
}

void Game::renderPlaying() {

	window.clear(Color::White);
	for (auto& enemy : enemies) {
		enemy.draw(window);
	}
	player.draw(window);
	sword.draw(window);

	Text text(font, "Playing");
	text.setCharacterSize(24);
	text.setFillColor(Color::Black);
	text.setPosition(Vector2f(10, 10));
	window.draw(text);

	window.display();
}

void Game::renderMenu() {
	window.clear(Color::White);

	Text title(font, "Menu");
	title.setCharacterSize(48);
	title.setFillColor(Color::Black);
	title.setPosition(Vector2f(540, 200));
	window.draw(title);

	Text instruction(font, "Press ESC to Play");
	instruction.setCharacterSize(24);
	instruction.setFillColor(Color::Black);
	instruction.setPosition(Vector2f(540, 300));
	window.draw(instruction);

	window.display();
}