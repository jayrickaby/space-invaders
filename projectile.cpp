#include <SFML/Graphics.hpp>
#include "projectile.h"

Projectile::Projectile(sf::Vector2f startPosition):
Entity(startPosition, 100.f, {0, -1})
{
    sf::IntRect spriteRect({16,0}, {16,16});
    sprite.setTextureRect(spriteRect);
}

void Projectile::update(float deltaTime){
    Entity::update(deltaTime);
    if (position.y < 0 - collisionBox.size.y){
        needsDestroyingState = true;
    }
}

