#include <iostream>
#include <SFML/Graphics.hpp>

using namespace std;
using namespace sf;

int main() {   
    //-------------------------Initialize-------------------
    // changing settings
    sf::ContextSettings settings;
    settings.antialiasingLevel = 8;

    //creating a SFML window
    sf::RenderWindow window(sf::VideoMode(800, 600), "RPG Game", sf::Style::Default, settings);

    //-------------------------Initialize-------------------
    
    //-------------------------Load-------------------
     
    sf::Texture playerTexture;
    sf::Sprite playerSprite;

    playerTexture.loadFromFile("assets/player/textures/spriteSheet.png");
    playerSprite.setTexture(playerTexture);
    playerSprite.scale(sf::Vector2f(3, 3));

    int XIndex = 0;
    int YIndex = 0;
    playerSprite.setTextureRect(sf::IntRect(XIndex * 64, YIndex * 64, 64, 64));
    //-------------------------Load-------------------
    
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
        //-------------------------Update-------------------

        //-------------------------Draw-------------------
        window.clear(sf::Color::Black);
        window.draw(playerSprite);
        window.display();
        //-------------------------Draw-------------------
    }
    return 0;
}