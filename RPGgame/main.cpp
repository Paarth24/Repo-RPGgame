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

    //creating circle
    sf::CircleShape circle(50.f);
    circle.setFillColor(sf::Color::Red);
    circle.setPosition(sf::Vector2f(100, 100));
    circle.setOutlineThickness(10.0f);
    circle.setOutlineColor(sf::Color::Magenta);

    //creating rectangle
    sf::RectangleShape rectangle(sf::Vector2f(100, 70));
    rectangle.setFillColor(sf::Color::Magenta);
    rectangle.setOutlineThickness(8.f);
    rectangle.setOutlineColor(sf::Color::Cyan);
    rectangle.setPosition(sf::Vector2f(200, 100));
    rectangle.setOrigin(rectangle.getSize() / 2.f);
    rectangle.setRotation(45.f); 
    //-------------------------Initialize-------------------
    
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
        //-------------------------Update-------------------
        

        //-------------------------Draw-------------------
        window.clear(sf::Color::Black);

        window.draw(circle);
        window.draw(rectangle);

        window.display();
        //-------------------------Draw-------------------
    }
    return 0;
}