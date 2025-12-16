#pragma once
#include <SFML/Graphics.hpp>

class Player{
public:
    // Core methods
    Player(sf::Vector2f startPosition);
    void update(float deltaTime);
    void render(sf::RenderTarget& target) const;

private:
    // Core attributes
    float speed;
    float bulletTimer;
    float bulletRecharge;

    // Physics stuff
    sf::Vector2i direction;
    sf::Vector2f position;
    sf::Vector2f velocity;
    sf::FloatRect collisionBox;

    // Visual stuff
    sf::Texture texture;
    sf::Sprite sprite;

    // Core methods
    void handleInput();
    void move(float deltaTime);
    void shoot();
};
