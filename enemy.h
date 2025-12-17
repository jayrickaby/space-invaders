#pragma once
#include <SFML/Graphics.hpp>

class Enemy {
public:
    // Core methods
    Enemy(sf::Vector2f startPosition);
    void update(float deltaTime);
    void draw(sf::RenderTarget& target) const;

    // Getter
    sf::FloatRect getCollisionBox();
    bool getNeedsDestroyingState();

    // Setters
    void setNeedsDestroyingState(bool state);

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

    // Gameplay
    bool needsDestroyingState;

    // Core methods
    void move(float deltaTime);
};
