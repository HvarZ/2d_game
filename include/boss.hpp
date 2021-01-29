#ifndef INC_2D_GAME_BOSS_HPP
#define INC_2D_GAME_BOSS_HPP

#include <string>

#include <SFML/Graphics.hpp>

class Boss {
private:
    sf::RenderWindow* window_;
    std::string name_;
    sf::Texture texture_;
    sf::Sprite sprite_;

    float startPosition_;
    float currentFrame_;

    int health_;

    bool onGround_;

public:
    virtual void move();

};

#endif //INC_2D_GAME_BOSS_HPP
