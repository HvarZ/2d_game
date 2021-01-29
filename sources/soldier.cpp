#include <soldier.hpp>
#include <settingsSoldier.hpp>

Soldier::Soldier(sf::RenderWindow* window, const sf::Texture& image) :
        window_(window), rect_(sf::FloatRect(0, 0, 40, 50)),
        speedX_(0), speedY_(0),
        currentFrame_(0), isOnGround_(true),
        health_(getStandardHealthSoldier()), score_(0) {
    sprite_.setTexture(image);
    sprite_.setTextureRect(sf::IntRect(0, 244, 40, 40));
    sprite_.setScale(getCoefficientScale(), getCoefficientScale());
}

void Soldier::update(float time) {              // every tick
    stand(time);
    move(getStandardSpeedJump(), getStandardSpeedRun(), time);
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

    if (currentFrame_ += (getStandardFpsRun() * time), currentFrame_ > static_cast<float>(getNumberFramesRun()))
        currentFrame_ -= static_cast<float>(getNumberFramesRun());

    if (speedX_ > 0)
        sprite_.setTextureRect(sf::IntRect(40 * static_cast<int>(currentFrame_), 244,
                               40, 50));
    if (speedX_ < 0)
        sprite_.setTextureRect(sf::IntRect(40 * static_cast<int>(currentFrame_) + 40, 244,
                               -40, 50));

    sprite_.setPosition(rect_.left, rect_.top);

    speedX_ = 0;
}

void Soldier::jump(float time) noexcept {
    if (!isOnGround_)
        speedY_ += (getStandardFpsJump() * time);

    isOnGround_ = false;

    if (rect_.top += speedY_ * time, rect_.top > getPositionGround()) {
        rect_.top = getPositionGround();
        speedY_ = 0;
        isOnGround_ = true;
    }
}

void Soldier::stand(float time) noexcept {
    if(speedX_ == 0 && speedY_ == 0
                    && !sf::Keyboard::isKeyPressed(sf::Keyboard::Left)
                    && !sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
        if (currentFrame_ += (getStandardFpsStand() * time), currentFrame_ > static_cast<float>(getNumberFramesStand()))
            currentFrame_ -= static_cast<float>(getNumberFramesStand());
        sprite_.setTextureRect(sf::IntRect(44 * static_cast<int>(currentFrame_), 190,
                               40, 50));
    }
}
