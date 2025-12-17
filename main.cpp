#include <SFML/Graphics.hpp>
#include "player.h"

int main() {
    sf::RenderWindow window(sf::VideoMode({1024,1024}), "Interstellar Colonisers");
    sf::View camera(sf::FloatRect({0.f, 0.f}, {128.f,128.f}));

    Player player({64.f, 64.f});
    sf::Clock clock;

    while (window.isOpen()){
        while (const std::optional event = window.pollEvent()){
            if (event->is<sf::Event::Closed>()){
                window.close();
            }
        }

        float deltaTime = clock.restart().asSeconds();

        // Configure render targets
        window.setView(camera);

        // Clear Screen
        window.clear();

        player.update(deltaTime);

        player.draw(window);

        // Finalise and update the screen!
        window.display();
    }

    return 0;
}
