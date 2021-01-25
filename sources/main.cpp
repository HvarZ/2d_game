#include <SFML/Graphics.hpp>

int main () {
    sf::RenderWindow window(sf::VideoMode(1920, 1080), "2d_Game");
    sf::Texture texture;
    texture.loadFromFile("../content/fang.png");

    float current_frame = 0;

    sf::Sprite main_hero;
    main_hero.setTexture(texture);
    main_hero.setTextureRect(sf::IntRect(0, 244, 40, 50));
    main_hero.setPosition(50, 100);

    while (window.isOpen()) {
        sf::Event event{};
        while (window.pollEvent(event)) {
            if ((event.type == sf::Event::Closed)
                || (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape))
                window.close();
        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
            main_hero.move(-0.1, 0);

            if (current_frame += 0.005, current_frame > 6) current_frame -= 6;

            main_hero.setTextureRect(sf::IntRect(40 * int(current_frame) + 40, 244, -40, 50));
        }

        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
            main_hero.move(0.1, 0);

            if (current_frame += 0.005, current_frame > 6) current_frame -= 6;

            main_hero.setTextureRect(sf::IntRect(40 * int(current_frame), 244, 40, 50));
        }


        window.clear();
        window.draw(main_hero);
        window.display();
    }


    return EXIT_SUCCESS;
}