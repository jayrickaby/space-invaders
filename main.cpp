#include <SFML/Graphics.hpp>
#include <algorithm>
#include "enemy.h"
#include "player.h"

int main() {
    sf::RenderWindow window(sf::VideoMode({1024,1024}), "Interstellar Colonisers");
    sf::View camera(sf::FloatRect({0.f, 0.f}, {128.f,128.f}));

    Player player({56.f, 112.f});
    std::vector<std::unique_ptr<Enemy>> enemyList;
    enemyList.push_back(std::make_unique<Enemy>(sf::Vector2f{56.f, -16.f}));
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

        for (auto& enemy : enemyList){
            enemy->update(deltaTime);
        }

        player.updateBullets(deltaTime, enemyList);

        enemyList.erase(
            std::remove_if(enemyList.begin(), enemyList.end(),
                           [](const std::unique_ptr<Enemy>& enemy) {
                               return enemy->getNeedsDestroyingState();
                           }),
                         enemyList.end()
        );

        for (auto& enemy : enemyList){
            enemy->draw(window);
        }
        player.draw(window);

        // Finalise and update the screen!
        window.display();
    }

    return 0;
}
