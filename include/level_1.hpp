#ifndef INC_2D_GAME_LEVEL1_HPP
#define INC_2D_GAME_LEVEL1_HPP

#include <vector>
#include <string>
#include <SFML/Graphics.hpp>

class Level_1 final {
private:
    sf::RenderWindow* window_;

    const std::vector<std::string> map_ = {
            "000000000000000000000000000000",
            "0                            0",
            "0                            0",
            "0                            0",
            "0 1111                       0",
            "0                            0",
            "0       111             111  0",
            "0              11111         0",
            "0       111             111  0",
            "0                            0",
            "0                            0",
            "0                            0",
            "0                            0",
            "0 1111                       0",
            "0                            0",
            "222222222222222222222222222222",
            "222222222222222222222222222222"
    };
public:
    explicit Level_1(sf::RenderWindow* window) noexcept;

    void draw() noexcept;
};


#endif //INC_2D_GAME_LEVEL1_HPP
