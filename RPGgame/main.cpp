#include "Player.h"
#include "Skeleton.h"

using namespace std;
using namespace sf;

int main() {   
    //-------------------------Initialize-------------------
    // changing settings
    sf::ContextSettings settings;
    settings.antialiasingLevel = 8;

    //creating a SFML window
    sf::RenderWindow window(sf::VideoMode(1920, 1080), "RPG Game", sf::Style::Default, settings);
    //-------------------------Initialize-------------------

    Skeleton skeleton;
    Player player;

    //-------------------------INITIALIZE-------------------
    player.Initialize();
    skeleton.Initialize();
    //-------------------------INITIALIZE-------------------
    
    //-------------------------LOAD-------------------
    skeleton.Load();
    player.Load();
    //-------------------------LOAD-------------------

    //creating a game loop
    while (window.isOpen()) {

        //-------------------------UPDATE-------------------
        //taking event inputs
        sf::Event event;

        while (window.pollEvent(event)) {

            if (event.type == sf::Event::Closed) {

                window.close();
            }
        }
        //-------------------------UPDATE-------------------
        skeleton.Update();
        player.Update(skeleton);
        //-------------------------DRAW-------------------
        window.clear(sf::Color::Black);

        skeleton.Draw(window);
        player.Draw(window);

        window.display();
        //-------------------------DRAW-------------------
    }
    return 0;
}