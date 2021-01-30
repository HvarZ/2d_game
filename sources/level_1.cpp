#include <level_1.hpp>

void Level_1::draw() noexcept {
    sf::RectangleShape rectangleShape;
    rectangleShape.setSize(sf::Vector2f(64, 64));

    auto height = map_.size();
    auto weight = map_[0].size();

    for (size_t i = 0; i < height; i++) {
        for (size_t j = 0; j < weight; j++) {
            if (map_[i][j] == '0')
                rectangleShape.setFillColor(sf::Color::White);
            else if (map_[i][j] == '1')
                rectangleShape.setFillColor(sf::Color::Cyan);
            else if (map_[i][j] == '2')
                rectangleShape.setFillColor(sf::Color::Green);

            rectangleShape.setPosition(static_cast<float>(j) * 64, static_cast<float>(i) * 64);
            window_->draw(rectangleShape);
        }
    }
}

Level_1::Level_1(sf::RenderWindow* window) noexcept : window_(window) {}
