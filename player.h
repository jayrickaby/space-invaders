#pragma once
#include <SFML/Graphics.hpp>
#include "entity.h"
#include "enemy.h"
#include "projectile.h"

class Player : public Entity{
public:
    // Core methods
    Player(sf::Vector2f startPosition);
    void update(float deltaTime) override;
    void updateBullets(float deltaTime, std::vector<std::unique_ptr<Enemy>>& enemies);
    void draw(sf::RenderTarget & target) const override;

private:
    // Gameplay stuff
    bool isShooting;
    float bulletRecharge;
    float bulletTimer;
    std::vector<std::unique_ptr<Projectile>> bulletList;

    // Core methods
    void handleInput();
    void shoot();
};
