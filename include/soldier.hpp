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

    [[maybe_unused]] int health;
    [[maybe_unused]] int score;

    void jump(float time) noexcept;
    void move(float speedJump, float speedRun, float time) noexcept;
    void stand(float time) noexcept;

    void set_speedX(float sX);
    void set_speedY(float sY);
    void set_onGround(bool value);

public:
    Soldier(sf::RenderWindow* _window, const sf::Texture& _image);

    void update(float time);
    void draw() const noexcept;

    [[nodiscard]] auto get_onGround() const noexcept -> bool;
};

#endif //INC_2D_GAME_SOLDIER_HPP
