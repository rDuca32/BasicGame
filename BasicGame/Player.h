#pragma once
#include <SFML/Graphics.hpp>

using namespace std;
using namespace sf;

class Player {
private:
    Sprite sprite;
    float speed;
    float damage;
    float health;

public:
    Player() = default;
    Player(const Texture& texture);
    void handleInput(float dt);
    void update(float dt);
    void draw(RenderWindow& window);
    Vector2f getPosition() const;
    float getDamage() const;
    Sprite& getSprite();

    void setPosition(const Vector2f& pos);
};