#include "Skeleton.h"

void Skeleton::Initialize() {

}

void Skeleton::Draw(sf::RenderWindow& window) {

    window.draw(sprite);
}

void Skeleton::Update() {

}

void Skeleton::Load() {

    texture.loadFromFile("assets/skeleton/textures/spriteSheet.png");
    sprite.setTexture(texture);
    sprite.scale(sf::Vector2f(3, 3));
    int XSkeletonIndex = 2;
    int YSkeletonIndex = 3;
    sprite.setTextureRect(sf::IntRect(XSkeletonIndex * 64, YSkeletonIndex * 64, 64, 64));
    sprite.setPosition(sf::Vector2f(180, 800));
}