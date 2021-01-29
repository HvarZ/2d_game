#ifndef INC_2D_GAME_BOSS_HPP
#define INC_2D_GAME_BOSS_HPP

#include <string>
#include <SFML/Graphics.hpp>

class Boss {
private:
    sf::RenderWindow* window;
    std::string name;
    sf::Texture texture;
    sf::Sprite sprite;

    float startPosition;
    float currentFrame;

    int health;

    bool onGround;

public:
    virtual void move();

};

#endif //INC_2D_GAME_BOSS_HPP
