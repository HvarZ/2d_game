#ifndef INC_2D_GAME_SOLDIER_HPP
#define INC_2D_GAME_SOLDIER_HPP

#include <SFML/Graphics.hpp>

class Soldier final {
private:
    sf::RenderWindow* window_;
    sf::Sprite sprite_;
    sf::FloatRect rect_;

    float speedX_;
    float speedY_;
    float currentFrame_;
    bool isOnGround_;

    [[maybe_unused]] int health_;
    [[maybe_unused]] int score_;

    void jump(float time) noexcept;
    void move(float speedJump, float speedRun, float time) noexcept;
    void stand(float time) noexcept;


public:
    Soldier(sf::RenderWindow* _window, const sf::Texture& _image);

    void update(float time);
    void draw() const noexcept;
};

#endif //INC_2D_GAME_SOLDIER_HPP
