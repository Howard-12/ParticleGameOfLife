#include <iostream>

#include "Dot.h"

int main()
{
    sf::RenderWindow window(sf::VideoMode(500, 500), "SFML works!");
    window.setFramerateLimit(0);

    std::unique_ptr<Dot> dot = std::make_unique<Dot>(100.f, 300.f, sf::Color::Green);
    
    float speed = 10.0f;
    float cx = 100.0f;
    float cy = 100.0f;
    sf::CircleShape shape(10.f);
    sf::Color colour = sf::Color::Green;
    shape.setFillColor(colour);

    float speed1 = 1.0f;
    float cx1 = 100.0f;
    float cy1 = 200.0f;
    sf::CircleShape shape1(10.f);
    shape1.setFillColor(sf::Color::Green);

    sf::Clock clock;
    while (window.isOpen())
    {   
        sf::Time elapsed = clock.restart();
        float deltaTime = (float)elapsed.asMicroseconds() / 10000;
        //std::cout << (float)deltaTime << "\n";
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();

        dot->update(deltaTime);

        if (shape.getPosition().x >= 475 || shape.getPosition().x <= 0)
        {
            speed *= -1;
        }
        if (shape1.getPosition().x >= 475 || shape1.getPosition().x <= 0)
        {
            speed1 *= -1;
        }
        cx += speed * deltaTime;
        cx1 += speed1 * deltaTime;
        shape.setPosition(cx, cy);
        shape1.setPosition(cx1, cy1);
        window.draw(shape);
        window.draw(shape1);
        dot->draw(&window);
        window.display();


    }

    return 0;
}