#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

class Dot : public sf::CircleShape
{
public:
    Dot(float xpos, float ypos, sf::Color colour);
    ~Dot();

    float x;
    float y;
    float size = 10.f;
    float speed = 5.f;
    sf::CircleShape shape;
    void update(float deltaTime);
    void draw(sf::RenderWindow *window);
};