#include <SFML/Graphics.hpp>
#include <algorithm>
#include <cmath>
#include "enemy.h"

Enemy::Enemy(sf::Vector2f startPosition):
speed(10.f),
direction({0,1}),
velocity({0.f,0.f}),
collisionBox(sf::FloatRect(startPosition, {16.f, 16.f})),
texture("assets/sprites/spritesheet.png"),
sprite(texture),
needsDestroyingState(false)

{
    sf::IntRect spriteRect({32,0}, {16,16});
    sprite.setTextureRect(spriteRect);
}

void Enemy::update(float deltaTime){
    // Movement
    float dampening = 7.5f;

    if (direction.x == 0){
        // Exponential decay
        velocity.x *= exp(-dampening * deltaTime);
    }
    else {
        velocity.x = speed * direction.x;
    }

    if (direction.y == 0){
        // Exponential decay
        velocity.y *= exp(-dampening * deltaTime);
    }
    else {
        velocity.y = speed * direction.y;
    }

    move(deltaTime);

    // Updating from movement
    position = collisionBox.position;
    sprite.setPosition(position);

}

void Enemy::move(float deltaTime) {
    collisionBox.position += sf::Vector2f({velocity.x * deltaTime, velocity.y * deltaTime});
}


void Enemy::draw(sf::RenderTarget& target) const {
    target.draw(sprite);
}


sf::FloatRect Enemy::getCollisionBox() {
    return collisionBox;
}


bool Enemy::getNeedsDestroyingState(){
    return needsDestroyingState;
}

void Enemy::setNeedsDestroyingState(bool state) {
    needsDestroyingState = state;
}
