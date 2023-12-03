#include <SFML/Graphics.hpp>
#include <iostream>
#include <thread>

int main()
{   
    sf::RenderWindow window(sf::VideoMode(200, 200), "SFML works!");
    sf::CircleShape shape(100.f);
    shape.setFillColor(sf::Color::Green);

    while (window.isOpen())
    {
        sf::Event event;
        sf::Clock clock; // starts the clock
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
            sf::Time elapsed1 = clock.getElapsedTime();
            std::cout << elapsed1.asSeconds() << std::endl;
            clock.restart();
        }

        window.clear();
        window.draw(shape);
        window.display();
    }

    return 0;
}