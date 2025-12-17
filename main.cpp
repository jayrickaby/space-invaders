#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <algorithm>
#include <cstdlib>
#include <iostream>
#include "enemy.h"
#include "player.h"

int main() {
    sf::RenderWindow window(sf::VideoMode({1024,1024}), "Interstellar Colonisers");
    sf::View camera(sf::FloatRect({0.f, 0.f}, {128,128}));
    bool isPaused = false;

    // Music
    sf::Music mus_mars("assets/music/mus_mars.ogg");
    mus_mars.setLooping(true);
    mus_mars.play();

    // Game Objects
    Player player({56.f, 112.f});
    std::vector<std::unique_ptr<Enemy>> enemyList;
    float enemyCooldown{1};
    float enemyTimer{0};

    // Background
    sf::Texture tex_background("assets/sprites/spr_background.png");
    sf::Sprite spr_background(tex_background);

    // Text stuff
    sf::Font font("assets/fonts/font_DTM-Sans.otf");
    font.setSmooth(false);
    sf::Text pointsText(font);
    pointsText.setString("Points: 0");
    pointsText.setCharacterSize(window.getDefaultView().getSize().x / 16);
    pointsText.setFillColor(sf::Color::Black);
    pointsText.setOutlineColor(sf::Color::White);
    pointsText.setOutlineThickness(pointsText.getCharacterSize() / 16);
    pointsText.setPosition({0 + pointsText.getOutlineThickness(),
        window.getDefaultView().getSize().y - pointsText.getCharacterSize() - pointsText.getOutlineThickness()});
    std::cout << pointsText.getPosition().x << '\n';

    int points{0};

    sf::Clock clock;

    while (window.isOpen()){
        while (const std::optional event = window.pollEvent()){
            if (event->is<sf::Event::Closed>()){
                window.close();
            }

            if (const auto* keyPress = event->getIf<sf::Event::KeyPressed>()) {
                if (keyPress->code == sf::Keyboard::Key::Escape) {
                    isPaused = !isPaused;
                }
            }
        }

        float deltaTime = clock.restart().asSeconds();

        // Configure render targets
        window.setView(camera);

        // Clear Screen
        window.clear();

        // Game Logic
        if (!isPaused){
            enemyTimer += deltaTime;
            if (enemyTimer >= enemyCooldown){
                enemyTimer = 0;
                float enemyX = (rand() % 96) + 16;
                enemyList.push_back(std::make_unique<Enemy>(sf::Vector2f{enemyX, -16.f}));
            }

            // Update stuff
            player.update(deltaTime);

            for (auto& enemy : enemyList){
                enemy->update(deltaTime);
            }

            player.updateBullets(deltaTime, enemyList);

            for (auto& enemy : enemyList){
                if (enemy->getNeedsDestroyingState()){
                    points += 1;
                    pointsText.setString("Points: " + std::to_string(points));
                }
            }

            enemyList.erase(
                std::remove_if(enemyList.begin(), enemyList.end(),
                            [](const std::unique_ptr<Enemy>& enemy) {
                                return enemy->getNeedsDestroyingState();
                            }),
                            enemyList.end()
            );
            if (mus_mars.getStatus() == sf::Music::Status::Paused) {
                mus_mars.play();
            }
        } else {
            mus_mars.pause();
        }


        // Draw stuff to rendertargets
        window.draw(spr_background);
        for (auto& enemy : enemyList){
            enemy->draw(window);
        }
        player.draw(window);

        // draw ui
        window.setView(window.getDefaultView());
        window.draw(pointsText);

        // Finalise and update the screen!
        window.display();
    }

    return 0;
}
