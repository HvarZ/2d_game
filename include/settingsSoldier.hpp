#ifndef INC_2D_GAME_SETTINGSSOLDIER_HPP
#define INC_2D_GAME_SETTINGSSOLDIER_HPP

auto getCoefficientScale() -> float {
    return 2;
}

auto getPositionGround() -> float {
    return 800;
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


#endif //INC_2D_GAME_SETTINGSSOLDIER_HPP
