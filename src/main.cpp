#include <SFML/Graphics.hpp>
#include "../include/MyLibrary/Game.h"
#include <iostream>
#include <thread>

int main()
{   
    sf::RenderWindow window(sf::VideoMode(500, 500), "SFML works!", sf::Style::Default);
    window.setVerticalSyncEnabled(true);

    Game game;
    //sf::CircleShape shape(50.f);
    //shape.setFillColor(sf::Color::Green);

    while (window.isOpen())
    {
        sf::Event event;
        sf::Clock clock; // starts the clock
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();

            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
            {
                game.setSnakeDirection(-1, 0);
                game.update();
            }
            else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
            {
                game.setSnakeDirection(1, 0);
                game.update();
            }
            else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
            {
                game.setSnakeDirection(0, -1);
                game.update();
            }
            else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
            {
                game.setSnakeDirection(0, 1);
                game.update();
            }
        }

        window.clear();
        game.draw(window);
        //window.draw(shape);
        window.display();
    }

    return 0;
}