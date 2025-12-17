#pragma once
#include <SFML/Graphics.hpp>
#include "entity.h"

class Projectile: public Entity{
public:
    // Core methods
    Projectile(sf::Vector2f startPosition);
    void update(float deltaTime) override;
};
