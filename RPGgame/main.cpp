#include <iostream>
#include <vector>
#include <SFML/Graphics.hpp>

using namespace std;
using namespace sf;

sf::Vector2f NormalizeVector(sf::Vector2f vector) {

    float magnitude = sqrt(vector.x* vector.x + vector.y * vector.y);

    sf::Vector2f normalizedVector;
    normalizedVector.x = vector.x / magnitude;
    normalizedVector.y = vector.y / magnitude;

    return normalizedVector;
}

int main() {   
    //-------------------------Initialize-------------------
    // changing settings
    sf::ContextSettings settings;
    settings.antialiasingLevel = 8;

    //creating a SFML window
    sf::RenderWindow window(sf::VideoMode(1920, 1080), "RPG Game", sf::Style::Default, settings);

    //-------------------------Initialize-------------------
    
    //-------------------------Load-------------------
    //-------------------------Skeleton-------------------
    sf::Texture skeletonTexture;
    sf::Sprite skeletonSprite;
    skeletonTexture.loadFromFile("assets/skeleton/textures/spriteSheet.png");
    skeletonSprite.setTexture(skeletonTexture);
    skeletonSprite.scale(sf::Vector2f(3, 3));
    int XSkeletonIndex = 2;
    int YSkeletonIndex = 3;
    skeletonSprite.setTextureRect(sf::IntRect(XSkeletonIndex * 64, YSkeletonIndex * 64, 64, 64));
    skeletonSprite.setPosition(sf::Vector2f(180, 800));
    //-------------------------Skeleton-------------------
    
    //-------------------------Player-------------------
    sf::Texture playerTexture;
    sf::Sprite playerSprite;

    playerTexture.loadFromFile("assets/player/textures/spriteSheet.png");
    playerSprite.setTexture(playerTexture);
    playerSprite.scale(sf::Vector2f(3, 3));
    playerSprite.setPosition(sf::Vector2f(0, 0));

    int XPlayerIndex = 0;
    int YPlayerIndex = 0;
    playerSprite.setTextureRect(sf::IntRect(XPlayerIndex * 64, YPlayerIndex * 64, 64, 64));
    //-------------------------Player-------------------

    vector<sf::RectangleShape> bullets;

    float bulletSpeed = 0.5f;
    //bullet.setPosition(playerSprite.getPosition());
    
    //-------------------------Load-------------------
    
    //-------------------------Calculating direction of bullet-------------------
    

    //-------------------------Calculating direction of bullet-------------------
    
    //creating a game loop
    while (window.isOpen()) {

        //-------------------------Update-------------------
        //taking event inputs
        sf::Event event;

        while (window.pollEvent(event)) {

            if (event.type == sf::Event::Closed) {

                window.close();
            }
        }

        
        sf::Vector2f position = playerSprite.getPosition();
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {

            playerSprite.setPosition(position + sf::Vector2f(1, 0));
        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {

            playerSprite.setPosition(position + sf::Vector2f(-1, 0));
        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {

            playerSprite.setPosition(position + sf::Vector2f(0, -1));
        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {

            playerSprite.setPosition(position + sf::Vector2f(0, 1));
        }

        if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {

            bullets.push_back(sf::RectangleShape(sf::Vector2f(45, 15)));
            bullets[bullets.size() - 1].setPosition(playerSprite.getPosition());
        }

        for (size_t i = 0; i < bullets.size(); i++) {
            
            sf::Vector2f bulletDirection;
            bulletDirection = skeletonSprite.getPosition() - bullets[i].getPosition();
            bulletDirection = NormalizeVector(bulletDirection) * bulletSpeed;
            bullets[i].setPosition(bullets[i].getPosition() + bulletDirection);
        }
        //-------------------------Update-------------------

        //-------------------------Draw-------------------
        window.clear(sf::Color::Black);
        window.draw(playerSprite);
        window.draw(skeletonSprite);
        for (size_t i = 0; i < bullets.size(); ++i) {
            window.draw(bullets[i]);
        }
        window.display();
        //-------------------------Draw-------------------
    }
    return 0;
}