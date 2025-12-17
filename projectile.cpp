#include <SFML/Graphics.hpp>
#include "projectile.h"

Projectile::Projectile(sf::Vector2f startPosition):
speed(100.f),
direction({0,-1}),
velocity({0.f,0.f}),
collisionBox(sf::FloatRect(startPosition, {16.f, 16.f})),
texture("assets/sprites/spritesheet.png"),
sprite(texture),
needsDestroyingState(false)
{
    sf::IntRect spriteRect({16,0}, {16,16});
    sprite.setTextureRect(spriteRect);
}

void Projectile::update(float deltaTime){
    velocity.x = speed * direction.x;
    velocity.y = speed * direction.y;

    move(deltaTime);

    position = collisionBox.position;
    sprite.setPosition(position);

    if (position.y < 0 - collisionBox.size.y){
        needsDestroyingState = true;
    }
}

void Projectile::move(float deltaTime) {
    collisionBox.position += sf::Vector2f({velocity.x * deltaTime, velocity.y * deltaTime});
}


void Projectile::draw(sf::RenderTarget& target) const {
    target.draw(sprite);
}


sf::Vector2f Projectile::getPosition(){
    return position;
}

sf::Vector2f Projectile::getSize() {
    return collisionBox.size;
}

bool Projectile::getNeedsDestroyingState(){
    return needsDestroyingState;
}

void Projectile::setNeedsDestroyingState(bool state) {
    needsDestroyingState = state;
}
sf::FloatRect Projectile::getCollisionBox() {
    return collisionBox;
}


