#include "Player.h"
#include "Math.h"

void Player::Initialize() {

}

void Player::Draw(sf::RenderWindow& window) {

    window.draw(sprite);

    for (size_t i = 0; i < bullets.size(); ++i) {
        window.draw(bullets[i]);
    }
}

void Player::Update(Skeleton& skeleton) {

    sf::Vector2f position = sprite.getPosition();

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {

        sprite.setPosition(position + sf::Vector2f(1, 0));
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {

        sprite.setPosition(position + sf::Vector2f(-1, 0));
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {

        sprite.setPosition(position + sf::Vector2f(0, -1));
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {

        sprite.setPosition(position + sf::Vector2f(0, 1));
    }

    if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {

        bullets.push_back(sf::RectangleShape(sf::Vector2f(45, 15)));
        bullets[bullets.size() - 1].setPosition(sprite.getPosition());
    }

    for (size_t i = 0; i < bullets.size(); i++) {

        sf::Vector2f bulletDirection;
        bulletDirection = skeleton.sprite.getPosition() - bullets[i].getPosition();
        bulletDirection = Math::NormalizeVector(bulletDirection) * bulletSpeed;
        bullets[i].setPosition(bullets[i].getPosition() + bulletDirection);
    }

}

void Player::Load() {

    texture.loadFromFile("assets/player/textures/spriteSheet.png");
    sprite.setTexture(texture);
    sprite.scale(sf::Vector2f(3, 3));
    sprite.setPosition(sf::Vector2f(0, 0));

    int XPlayerIndex = 0;
    int YPlayerIndex = 0;
    sprite.setTextureRect(sf::IntRect(XPlayerIndex * 64, YPlayerIndex * 64, 64, 64));
}
