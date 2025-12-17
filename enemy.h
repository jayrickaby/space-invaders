#pragma once
#include <SFML/Graphics.hpp>
#include "entity.h"

class Enemy : public Entity{
public:
    // Core methods
    Enemy(sf::Vector2f startPosition);
};
