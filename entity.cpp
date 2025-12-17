#include <SFML/Graphics.hpp>
#include <algorithm>
#include <cmath>
#include "entity.h"

Entity::Entity(sf::Vector2f startPosition, float speed):
Entity(startPosition, speed, {0,0})
{

}

Entity::Entity(sf::Vector2f startPosition, float speed, sf::Vector2i direction):
speed(speed),
direction(direction),
velocity({0.f,0.f}),
collisionBox(sf::FloatRect(startPosition, {16.f, 16.f})),
texture("assets/sprites/spr_sheet.png"),
sprite(texture),
needsDestroyingState(false)

{
    sf::IntRect spriteRect({0,0}, {16,16});
    sprite.setTextureRect(spriteRect);
}

void Entity::update(float deltaTime){
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

void Entity::move(float deltaTime) {
    collisionBox.position += sf::Vector2f({velocity.x * deltaTime, velocity.y * deltaTime});
}

void Entity::draw(sf::RenderTarget& target) const {
    target.draw(sprite);
}
