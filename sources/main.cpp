#include <SFML/Graphics.hpp>

#include <soldier/soldier.hpp>
#include <level_1/level_1.hpp>

int main() {
    sf::RenderWindow window(sf::VideoMode(1920, 1080), "2d_Game");

    sf::Texture texture;
    texture.loadFromFile("../content/fang.png");

    Soldier soldier(&window, texture);
    Level_1 level1(&window);

    sf::Clock clock;


    while (window.isOpen()) {
        sf::Event event{};

        auto time = clock.getElapsedTime().asMicroseconds() / 250;
        clock.restart();

        while (window.pollEvent(event)) {
            if ((event.type == sf::Event::Closed)
                || (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape))
                window.close();
        }

        soldier.update(time);

        window.clear();
        level1.draw();
        soldier.draw();
        window.display();
    }


    return EXIT_SUCCESS;
}