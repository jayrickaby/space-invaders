#pragma once
#include <SFML/Graphics.hpp>
#include "entity.h"

// Copyright (c) 2025 Jay Rickaby


class Enemy : public Entity{
public:
    // Core methods
    Enemy(sf::Vector2f startPosition);
};
