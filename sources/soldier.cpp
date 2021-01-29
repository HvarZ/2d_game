#include <soldier.hpp>
#include <settingsSoldier.hpp>

Soldier::Soldier(sf::RenderWindow* window, const sf::Texture& image) :
        window_(window), rect_(soldierSettings::getRectStartPosition()),
        speedX_(0), speedY_(0),
        currentFrame_(0), isOnGround_(true),
        health_(soldierSettings::getStandardHealthSoldier()), score_(0) {
    sprite_.setTexture(image);
    sprite_.setTextureRect(soldierSettings::getStartPosition());
    sprite_.setScale(soldierSettings::getCoefficientScale(), soldierSettings::getCoefficientScale());
}

void Soldier::update(float time) {                                                  // every tick
    stand(time);
    move(soldierSettings::getStandardSpeedJump(), soldierSettings::getStandardSpeedRun(), time);
    jump(time);
}

void Soldier::draw() const noexcept {
    window_->draw(sprite_);
}

void Soldier::move(const float speedJump, const float speedRun, const float time) noexcept {
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
        speedX_ = -speedRun;

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
        speedX_ = speedRun;

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
        if (isOnGround_) {
            speedY_ = speedJump;
            isOnGround_ = false;
        }

    rect_.left += speedX_ * time;

    if (currentFrame_ += (soldierSettings::getStandardFpsRun() * time), currentFrame_ > static_cast<float>(soldierSettings::getNumberFramesRun()))
        currentFrame_ -= static_cast<float>(soldierSettings::getNumberFramesRun());

    if (speedX_ > 0)
        sprite_.setTextureRect(soldierSettings::getRectAnimationRunRight(currentFrame_));
    if (speedX_ < 0)
        sprite_.setTextureRect(soldierSettings::getRectAnimationRunLeft(currentFrame_));

    sprite_.setPosition(rect_.left, rect_.top);

    speedX_ = 0;
}

void Soldier::jump(float time) noexcept {
    if (!isOnGround_)
        speedY_ += (soldierSettings::getStandardFpsJump() * time);

    isOnGround_ = false;

    if (rect_.top += speedY_ * time, rect_.top > soldierSettings::getPositionGround()) {
        rect_.top = soldierSettings::getPositionGround();
        speedY_ = 0;
        isOnGround_ = true;
    }
}

void Soldier::stand(float time) noexcept {
    if(speedX_ == 0 && speedY_ == 0
                    && !sf::Keyboard::isKeyPressed(sf::Keyboard::Left)
                    && !sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {

        if (currentFrame_ += (soldierSettings::getStandardFpsStand() * time),
            currentFrame_ > static_cast<float>(soldierSettings::getNumberFramesStand()))

            currentFrame_ -= static_cast<float>(soldierSettings::getNumberFramesStand());
        sprite_.setTextureRect(soldierSettings::getRectAnimationStand(currentFrame_));
    }
}
