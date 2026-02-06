#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <algorithm>
#include "entity.h"
#include "enemy.h"
#include "player.h"

Player::Player(sf::Vector2f startPosition):
Entity(startPosition, (50.f)),
bulletRecharge(0.75f),
bulletTimer(bulletRecharge),
buf_shoot("assets/sounds/snd_shoot.wav"),
buf_explosion("assets/sounds/snd_explosion.wav"),
snd_shoot(buf_shoot),
snd_explosion(buf_explosion)
{
    sf::IntRect spriteRect({0,0}, {16,16});
    sprite.setTextureRect(spriteRect);

    snd_shoot.setVolume(50);
    snd_explosion.setVolume(50);
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
    Entity::update(deltaTime);

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
                snd_explosion.play();
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

void Player::draw(sf::RenderTarget& target) const {
    Entity::draw(target);

    for (auto& bullet : bulletList){
        bullet->draw(target);
    }
}

void Player::shoot() {
    bulletList.push_back(std::make_unique<Projectile>(position));
    snd_shoot.play();
}


