#include <SFML/Graphics.hpp>
#include <iostream>
#include "../include/MyLibrary/Game.h"

int main()
{   
    sf::RenderWindow window(sf::VideoMode(750, 750), "SFML works!", sf::Style::Default);
    window.setVerticalSyncEnabled(true);

    sf::CircleShape shape(100.f);
    shape.setFillColor(sf::Color::Green);

    Game game;
    while (window.isOpen())
    {
        sf::Event event;
        sf::Clock clock; // starts the clock
        while (window.pollEvent(event))
        {   
            // check the type of the event...
            if (event.type == sf::Event::Closed)
                window.close();

            else if (event.type == sf::Event::Resized)
            {
                // update the view to the new size of the window
                sf::FloatRect visibleArea(0, 0, event.size.width, event.size.height);
                window.setView(sf::View(visibleArea));
            }
        }

        window.clear();
        game.draw(window, game.getFieldSize().x, game.getFieldSize().y);
        window.display();
    }

    return 0;
}