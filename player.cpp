#include <SFML/Graphics.hpp>
#include "player.h"

Player::Player(sf::Vector2f startPosition):
speed(50),
bulletRecharge(2),
velocity({0,0}),
texture("assets/sprites/spritesheet.png"),
sprite(texture)
{
    collisionBox.position = startPosition;
    sf::IntRect spriteRect({0,0}, {16,16});
    sprite.setTextureRect(spriteRect);
}

void Player::handleInput() {
    direction.x = (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D)) - (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A));
    direction.y = (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S)) - (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W));
}


void Player::update(float deltaTime){
    handleInput();
    velocity.x = speed * direction.x;
    velocity.y = speed * direction.y;

    move(deltaTime);

    position = collisionBox.position;
    sprite.setPosition(position);
}

void Player::move(float deltaTime) {
    collisionBox.position.x += velocity.x * deltaTime;
    collisionBox.position.y += velocity.y * deltaTime;
}


void Player::render(sf::RenderTarget& target) const {
    target.draw(sprite);
}

