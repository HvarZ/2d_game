#ifndef INC_2D_GAME_SETTINGSSOLDIER_HPP
#define INC_2D_GAME_SETTINGSSOLDIER_HPP

#include <SFML/Graphics.hpp>

namespace soldierSettings {
    auto getRectStartPosition() -> sf::FloatRect {
        return sf::FloatRect(150, 150, 40, 50);
    }

    auto getStartPosition() -> sf::IntRect {
        return sf::IntRect(0, 244, 40, 40);
    }

    auto getRectAnimationRunLeft(float currentFrame_) -> sf::IntRect {
        return sf::IntRect(40 * static_cast<int>(currentFrame_) + 40, 244,
                           -40, 50);
    }

    auto getRectAnimationRunRight(float currentFrame_) -> sf::IntRect {
        return sf::IntRect(40 * static_cast<int>(currentFrame_), 244,
                           40, 50);
    }

    auto getRectAnimationStand(float currentFrame_) -> sf::IntRect {
        return sf::IntRect(44 * static_cast<int>(currentFrame_), 190,
                           40, 50);
    }

    auto getCoefficientScale() -> float {
        return 2.0f;
    }

    auto getPositionGround() -> float {
        return 800.0f;
    }

    auto getStandardSpeedJump() -> float {
        return -0.4f;
    }

    auto getStandardSpeedRun() -> float {
        return 0.1f;
    }

    auto getStandardHealthSoldier() -> int {
        return 200;
    }

    auto getStandardFpsRun() -> float {
        return 0.005f;
    }

    auto getStandardFpsJump() -> float {
        return 0.0005f;
    }

    auto getStandardFpsStand() -> float {
        return 0.000001f;
    }

    auto getNumberFramesRun() -> int {
        return 6;
    }

    auto getNumberFramesStand() -> int {
        return 3;
    }
}

#endif //INC_2D_GAME_SETTINGSSOLDIER_HPP
