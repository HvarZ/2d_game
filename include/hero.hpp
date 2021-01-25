#ifndef INC_2D_GAME_HERO_HPP
#define INC_2D_GAME_HERO_HPP

#include <string>
#include <SFML/Graphics.hpp>

class hero {
private:
    sf::RenderWindow* window;
    std::string name;
    sf::Texture texture;
    sf::Sprite sprite;
    int health;
    int score;
    float current_frame;

public:
    virtual void move();
    virtual void upUlt();

    [[nodiscard]] virtual auto get_health() const noexcept -> int;
    virtual void set_health(const int damage) noexcept;

    [[nodiscard]] virtual auto get_score() const noexcept -> int;
    virtual void upScore() noexcept;

    virtual void drawScore() const noexcept;

};


#endif //INC_2D_GAME_HERO_HPP
