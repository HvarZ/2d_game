#ifndef INC_2D_GAME_SOLDIER_HPP
#define INC_2D_GAME_SOLDIER_HPP

#include <SFML/Graphics.hpp>

class Soldier final {
private:
    sf::RenderWindow* window;
    sf::Sprite sprite;
    sf::FloatRect rect;

    float speedX;
    float speedY;
    float currentFrame;
    bool onGround;

    int health;
    int score;

public:
    Soldier(sf::RenderWindow* _window, const sf::Texture& _image);

    void update(float time);
    void draw();

    void set_speedX(float sX);
    void set_speedY(float sY);
    void set_onGround(bool value);

    [[nodiscard]] auto get_onGround() const noexcept -> bool;

};

#endif //INC_2D_GAME_SOLDIER_HPP
