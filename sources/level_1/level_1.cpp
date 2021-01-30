#include <level_1/level_1.hpp>

#define FILL_COLOR(number, color)           \
    if (map_[i][j] == (number))             \
        rectangleShape.setFillColor(color); \


void Level_1::draw() noexcept {
    sf::RectangleShape rectangleShape;
    rectangleShape.setSize(sf::Vector2f(64, 64));

    auto height = map_.size();
    auto weight = map_[0].size();

    for (size_t i = 0; i < height; i++) {
        for (size_t j = 0; j < weight; j++) {
            FILL_COLOR('0', sf::Color::White);
            FILL_COLOR('1', sf::Color::Cyan);
            FILL_COLOR('2', sf::Color::Green);

            if (map_[i][j] == ' ')
                continue;

            rectangleShape.setPosition(static_cast<float>(j) * 64, static_cast<float>(i) * 64);
            window_->draw(rectangleShape);
        }
    }
}

Level_1::Level_1(sf::RenderWindow* window) noexcept : window_(window) {}
