#pragma once
#include <SFML/Graphics.hpp>

using namespace std;
using namespace sf;

class Sword {
private:
    Sprite sprite;
public:
    Sword() = default;
    Sword(const Texture& texture);
    void update(const Vector2f& playerPos, const Vector2f& mousePos);
    void draw(RenderWindow& window);
    Vector2f getPosition() const;
    Sprite& getSprite();

    void setPosition(const Vector2f& pos);
};