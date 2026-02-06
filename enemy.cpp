#include <SFML/Graphics.hpp>
#include "entity.h"
#include "enemy.h"

// Copyright (c) 2025 Jay Rickaby

Enemy::Enemy(sf::Vector2f startPosition):
Entity(startPosition, 10.f, {0,1})
{
    sf::IntRect spriteRect({32,0}, {16,16});
    sprite.setTextureRect(spriteRect);
}

