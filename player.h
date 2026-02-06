#pragma once
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include "entity.h"
#include "enemy.h"
#include "projectile.h"

// Copyright (c) 2025 Jay Rickaby

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

    // Sound stuff
    sf::SoundBuffer buf_shoot;
    sf::SoundBuffer buf_explosion;
    sf::Sound snd_shoot;
    sf::Sound snd_explosion;

    // Core methods
    void handleInput();
    void shoot();
};
