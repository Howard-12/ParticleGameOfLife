#include <iostream>
#include <SFML/Graphics.hpp>

int main()
{
    sf::RenderWindow window(sf::VideoMode(500, 500), "SFML works!");

    float d = 0.2;
    float speed = 10.0f;
    float cx = 100.0f;
    float cy = 100.0f;
    sf::CircleShape shape(10.f);
    shape.setFillColor(sf::Color::Green);

    float speed1 = 2.0f;
    float cx1 = 100.0f;
    float cy1 = 200.0f;
    sf::CircleShape shape1(10.f);
    shape1.setFillColor(sf::Color::Green);

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();

        cx += speed;
        cx1 += speed1;
        shape.setPosition(cx, cy);
        shape1.setPosition(cx1, cy1);
        window.draw(shape);
        window.draw(shape1);

        window.display();

        if (shape.getPosition().x >= 480 || shape.getPosition().x <= 0)
        {
            speed *= -1;
        }
        if (shape1.getPosition().x >= 480 || shape1.getPosition().x <= 0)
        {
            speed1 *= -1;
        }

    }

    return 0;
}