
#include "Enemy.h"
#include <cmath>

Enemy::Enemy(const Texture& texture, Vector2f pos)
    : sprite(texture), speed(100), health(300)
{
    sprite.setScale({ 15, 15 });
    sprite.setPosition(pos);
}

void Enemy::update(const Vector2f& playerPos, float dt) {
    Vector2f dir = playerPos - sprite.getPosition();
    float len = sqrt(dir.x * dir.x + dir.y * dir.y);
    if (len != 0) dir /= len;
    sprite.move(dir * speed * dt);
}

void Enemy::draw(RenderWindow& window) {
    float enemyWidth = 15 * 16;
    Vector2f healthBarPos = sprite.getPosition() + Vector2f(0, -20);

    RectangleShape healthBarBg({ enemyWidth, 8 });
    healthBarBg.setPosition(healthBarPos);
    healthBarBg.setFillColor(Color(100, 100, 100));

    float healthPercent = max(0.f, health) / 300.f;
    RectangleShape healthBar({ enemyWidth * healthPercent, 8 });
    healthBar.setPosition(healthBarPos);
    healthBar.setFillColor(Color::Red);

    window.draw(sprite);
    window.draw(healthBarBg);
    window.draw(healthBar);

    if (isDead()) {
        respawn();
    }
}

void Enemy::takeDamage(float dmg, float dt) {
    health -= dmg * dt;
}

bool Enemy::isDead() const {
    return health <= 0;
}

void Enemy::respawn() {
    health = 300;
    sprite.setPosition({ rand() % 1800 + 60.f, rand() % 900 + 60.f });
}

Vector2f Enemy::getPosition() const {
    return sprite.getPosition();
}

Sprite& Enemy::getSprite() {
    return sprite;
}

void Enemy::setPosition(const Vector2f& pos) {
    sprite.setPosition(pos);
}
