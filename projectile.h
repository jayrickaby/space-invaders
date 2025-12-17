#pragma once
#include <SFML/Graphics.hpp>

class Projectile{
public:
    // Core methods
    Projectile(sf::Vector2f startPosition);
    void update(float deltaTime);
    void draw(sf::RenderTarget& target) const;
   //~Projectile();

    // Getter
    sf::Vector2f getPosition();
    sf::Vector2f getSize();

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

    // Core methods
    void move(float deltaTime);
};
