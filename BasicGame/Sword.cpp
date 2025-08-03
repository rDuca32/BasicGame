#include "Sword.h"
#include <cmath>

#include "Math.h"

Sword::Sword(const Texture& texture)
    : sprite(texture)
{
    sprite.setScale({ 8, 8 });
}

void Sword::update(const Vector2f& playerPos, const Vector2f& mousePos) {
    Vector2f dir = Math::normalize(mousePos - playerPos);
    sprite.setPosition(playerPos + dir * 100.f);
}

void Sword::draw(RenderWindow& window) {
    window.draw(sprite);
}

Vector2f Sword::getPosition() const {
    return sprite.getPosition();
}

Sprite& Sword::getSprite() {
    return sprite;
}

void Sword::setPosition(const Vector2f& pos) {
    sprite.setPosition(pos);
}