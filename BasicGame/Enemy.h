#pragma once
#include <SFML/Graphics.hpp>

using namespace std;
using namespace sf;

class Enemy {
private:
    Sprite sprite;
    float speed;
    float health;

public:
    Enemy() = default;
    Enemy(const Texture& texture, Vector2f pos);
    void update(const Vector2f& playerPos, float dt);
    void draw(RenderWindow& window);
    void takeDamage(float dmg, float dt);
    bool isDead() const;
    void respawn();
    Vector2f getPosition() const;
    Sprite& getSprite();

    void setPosition(const Vector2f& pos);
};