#include <soldier.hpp>

Soldier::Soldier(sf::RenderWindow* _window, const sf::Texture& image) :
        window(_window),rect(sf::FloatRect(0, 0, 40, 50)),
        speedX(0), speedY(0),
        currentFrame(0), onGround(true),
        health(200), score(0) {
    sprite.setTexture(image);
    sprite.setTextureRect(sf::IntRect(0, 244, 40, 40));
}

void Soldier::update(const float time) {
    rect.left += speedX * time;

    if(!onGround)
        speedY += 0.0005f * time;

    rect.top += speedY * time;

    onGround = false;

    if (rect.top > 150) {
        rect.top = 150;
        speedY = 0;
        onGround = true;
    }

    if (currentFrame += (0.005f * time), currentFrame > 6) currentFrame -= 6;

    if (speedX > 0) sprite.setTextureRect(sf::IntRect(40 * static_cast<int>(currentFrame), 244, 40, 50));
    if (speedX < 0) sprite.setTextureRect(sf::IntRect(40 * static_cast<int>(currentFrame) + 40, 244, -40, 50));

    sprite.setPosition(rect.left, rect.top);

    speedX = 0;
}

void Soldier::set_speedX(const float sX) {
    speedX = sX;
}

void Soldier::set_speedY(const float sY) {
    speedX = sY;
}

void Soldier::draw() {
    window->draw(sprite);
}