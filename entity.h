#pragma once
#include <SFML/Graphics.hpp>

class Entity {
public:
    // Core methods
    Entity(sf::Vector2f startPosition, float speed);
    Entity(sf::Vector2f startPosition, float speed, sf::Vector2i direction);
    virtual void update(float deltaTime);
    virtual void draw(sf::RenderTarget& target) const;
    virtual ~Entity() = default;

    // Getter
    sf::Vector2f getPosition() { return collisionBox.position; } const
    sf::Vector2f getSize() { return collisionBox.size; } const
    sf::FloatRect getCollisionBox() { return collisionBox; } const
    bool getNeedsDestroyingState() { return needsDestroyingState; } const

    // Setters
    void setNeedsDestroyingState(bool state) { needsDestroyingState = state; }

protected:
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
