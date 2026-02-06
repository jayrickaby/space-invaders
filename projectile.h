#pragma once
#include <SFML/Graphics.hpp>
#include "entity.h"

// Copyright (c) 2025 Jay Rickaby

class Projectile: public Entity{
public:
    // Core methods
    Projectile(sf::Vector2f startPosition);
    void update(float deltaTime) override;
};
