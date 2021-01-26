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

    virtual void set_speedX(const float sX);
    virtual void set_speedY(const float sY);
};

#endif //INC_2D_GAME_SOLDIER_HPP
