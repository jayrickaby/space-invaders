#pragma once
#include <SFML/Graphics.hpp>
#include "enemy.h"
#include "projectile.h"

class Player{
public:
    // Core methods
    Player(sf::Vector2f startPosition);
    void update(float deltaTime);
    void updateBullets(float deltaTime, std::vector<std::unique_ptr<Enemy>>& enemies);
    void draw(sf::RenderTarget& target) const;

private:
    // Physics stuffs
    float speed;
    sf::Vector2i direction;
    sf::Vector2f position;
    sf::Vector2f velocity;
    sf::FloatRect collisionBox;

    // Visual stuff
    sf::Texture texture;
    sf::Sprite sprite;

    // Gameplay stuff
    bool isShooting;
    float bulletRecharge;
    float bulletTimer;
    std::vector<std::unique_ptr<Projectile>> bulletList;

    // Core methods
    void handleInput();
    void move(float deltaTime);
    void shoot();
};
