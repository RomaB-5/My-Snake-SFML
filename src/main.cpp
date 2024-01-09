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
    while (window.isOpen() && !game.isOver())
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

            else if (event.type == sf::Event::KeyPressed)
            {
				if (event.key.code == sf::Keyboard::Escape)
					window.close();
				else if (event.key.code == sf::Keyboard::Up)
					game.snake->setDirection(Snake::Direction::UP);
				else if (event.key.code == sf::Keyboard::Down)
					game.snake->setDirection(Snake::Direction::DOWN);
				else if (event.key.code == sf::Keyboard::Left)
					game.snake->setDirection(Snake::Direction::LEFT);
				else if (event.key.code == sf::Keyboard::Right)
					game.snake->setDirection(Snake::Direction::RIGHT);
                game.update();
			}
        }

        window.clear();
        //game.update();
        game.draw(window, game.getFieldSize().x, game.getFieldSize().y);
        window.display();
    }

    std::cout << "Quit the game\n";

    return 0;
}