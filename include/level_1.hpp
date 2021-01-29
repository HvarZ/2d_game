#ifndef INC_2D_GAME_LEVEL1_HPP
#define INC_2D_GAME_LEVEL1_HPP

#include <vector>
#include <string>

class Level_1 final {
private:
    std::vector<std::string> map_;

public:
    explicit Level_1(const std::vector<std::string>& map) noexcept;

    void drawMap() const noexcept;
};

#endif //INC_2D_GAME_LEVEL1_HPP
