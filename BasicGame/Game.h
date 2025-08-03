#pragma once

#include <SFML/Graphics.hpp>

#include "Player.h"
#include "Enemy.h"
#include "Sword.h"

using namespace std;
using namespace sf;

class Game
{
private:
	RenderWindow window;

	enum GameState
	{
		MENU,
		PLAYING
	};

	GameState gameState;

	Font font;
	Text gameModeText;

	Sprite playerSprite;
	Sprite enemySprite;
	Sprite swordSprite;

	Texture playerTexture;
	Texture enemyTexture;
	Texture swordTexture;

	Player player;
	vector<Enemy> enemies;
	Sword sword;

public:
	Game();
	~Game();

	void run();
	void renderPlaying();
	void renderMenu();

	void handleEvents();
	void updatePlaying(Clock& clock);
};