#include <soldier.hpp>

const int ground = 800;

Soldier::Soldier(sf::RenderWindow* _window, const sf::Texture& image) :
        window(_window),rect(sf::FloatRect(0, 0, 40, 50)),
        speedX(0), speedY(0),
        currentFrame(0), onGround(true),
        health(200), score(0) {
    sprite.setTexture(image);
    sprite.setTextureRect(sf::IntRect(0, 244, 40, 40));
    sprite.setScale(2, 2);
}

void Soldier::update(float time) {              // every tick
    stand(time);
    move(-0.4f, 0.1f, time);
    jump(time);
}

void Soldier::set_speedX(float sX) {
    speedX = sX;
}

void Soldier::set_speedY(float sY) {
    speedY = sY;
}

void Soldier::set_onGround(bool value) {
    onGround = value;
}

void Soldier::draw() {
    window->draw(sprite);
}

auto Soldier::get_onGround() const noexcept -> bool {
    return onGround;
}

void Soldier::move(const float speedJump, const float speedRun, const float time) noexcept {
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
        set_speedX(-speedRun);
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
        set_speedX(speedRun);
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
        if (get_onGround()) {
            set_speedY(speedJump);
            set_onGround(false);
        }
    }

    rect.left += speedX * time;

    if (currentFrame += (0.005f * time), currentFrame > 6) currentFrame -= 6;

    if (speedX > 0) sprite.setTextureRect(sf::IntRect(40 * static_cast<int>(currentFrame), 244, 40, 50));
    if (speedX < 0) sprite.setTextureRect(sf::IntRect(40 * static_cast<int>(currentFrame) + 40, 244, -40, 50));

    sprite.setPosition(rect.left, rect.top);

    speedX = 0;

}

void Soldier::jump(float time) noexcept {
    if(!onGround) speedY += (0.0005f * time);

    set_onGround(false);

    if (rect.top += speedY * time, rect.top > ground) {
        rect.top = ground;
        set_speedY(0);
        set_onGround(true);
    }
}

void Soldier::stand(float time) noexcept {
    if(speedX == 0 && speedY == 0
                   && !sf::Keyboard::isKeyPressed(sf::Keyboard::Left)
                   && !sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
        if (currentFrame += (0.000001f * time), currentFrame > 3) currentFrame -= 3;
        sprite.setTextureRect(sf::IntRect(44 * static_cast<int>(currentFrame), 190, 40, 50));
    }
}
