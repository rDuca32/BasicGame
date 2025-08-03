#include "Player.h"
#include <cmath>

#include "Math.h"


Player::Player(const Texture& texture)
    : sprite(texture), health(500), speed(200), damage(100)
{
    sprite.setScale(Vector2f(10, 10));
    sprite.setPosition(Vector2f(400, 300));
}

void Player::handleInput(float dt) {
    Vector2f movement(0, 0);
    if (Keyboard::isKeyPressed(Keyboard::Key::W)) movement.y -= 1;
    if (Keyboard::isKeyPressed(Keyboard::Key::S)) movement.y += 1;
    if (Keyboard::isKeyPressed(Keyboard::Key::A)) movement.x -= 1;
    if (Keyboard::isKeyPressed(Keyboard::Key::D)) movement.x += 1;

    if (movement != Vector2f(0, 0))
        movement /= Math::normalize(movement).length();

    sprite.move(movement * speed * dt);
}

void Player::update(float) {}

void Player::draw(RenderWindow& window) {
    window.draw(sprite);
}

Vector2f Player::getPosition() const {
    return sprite.getPosition();
}

float Player::getDamage() const {
    return damage;
}

Sprite& Player::getSprite() {
    return sprite;
}

void Player::setPosition(const Vector2f& pos) {
    sprite.setPosition(pos);
}