#ifndef INC_2D_GAME_LEVEL1_HPP
#define INC_2D_GAME_LEVEL1_HPP

#include <vector>
#include <string>

class Level_1 {
private:
    std::vector<std::string> map_;

public:
    Level_1(const std::vector<std::string>& map) noexcept;

    void printMap() const noexcept;
};

#endif //INC_2D_GAME_LEVEL1_HPP
