#include <SFML/Graphics.hpp>
#include <algorithm>
#include <cmath>
#include <iostream>
#include "enemy.h"
#include "player.h"

Player::Player(sf::Vector2f startPosition):
speed(50.f),
velocity({0.f,0.f}),
collisionBox(sf::FloatRect(startPosition, {16.f, 16.f})),
texture("assets/sprites/spritesheet.png"),
sprite(texture),
bulletRecharge(1.f),
bulletTimer(bulletRecharge)
{
    sf::IntRect spriteRect({0,0}, {16,16});
    sprite.setTextureRect(spriteRect);
}

void Player::handleInput() {
    isShooting = false;
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Space)) {
        isShooting = true;
    }

    direction.x = (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D)) - (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A));
    direction.y = (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S)) - (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W));
}


void Player::update(float deltaTime){
    // Movement
    handleInput();
    float dampening = 7.5f;

    if (direction.x == 0){
        // Exponential decay
        velocity.x *= exp(-dampening * deltaTime);
    }
    else {
        velocity.x = speed * direction.x;
    }

    if (direction.y == 0){
        // Exponential decay
        velocity.y *= exp(-dampening * deltaTime);
    }
    else {
        velocity.y = speed * direction.y;
    }

    move(deltaTime);

    // Updating from movement
    position = collisionBox.position;
    sprite.setPosition(position);

    // Bullet stuff
    bulletTimer += deltaTime;
    if (isShooting && bulletTimer > bulletRecharge){
        Player::shoot();
        bulletTimer = 0;
    }
}

void Player::updateBullets(float deltaTime, std::vector<std::unique_ptr<Enemy>>& enemies){
    for (auto& bullet : bulletList){
        bullet->update(deltaTime);

        for (auto& enemy : enemies){
            if (enemy->getCollisionBox().findIntersection(bullet->getCollisionBox())){
                bullet->setNeedsDestroyingState(true);
                enemy->setNeedsDestroyingState(true);
                break;
            }
        }

    }

    bulletList.erase(
        std::remove_if(bulletList.begin(), bulletList.end(),
                       [](const std::unique_ptr<Projectile>& bullet) {
                           return bullet->getNeedsDestroyingState();
                       }),
        bulletList.end()
    );
}

void Player::move(float deltaTime) {
    collisionBox.position += sf::Vector2f({velocity.x * deltaTime, velocity.y * deltaTime});
}


void Player::draw(sf::RenderTarget& target) const {
    target.draw(sprite);

    for (auto& bullet : bulletList){
        bullet->draw(target);
    }
}

void Player::shoot() {
    bulletList.push_back(std::make_unique<Projectile>(position));
}


