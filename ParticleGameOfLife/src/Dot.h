#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

class Dot
{
public:
    Dot(float xpos, float ypos, sf::Color colour);
    ~Dot();

    float x;
    float y;
    float vx = 0;
    float vy = 0;
    const float size = 3.f;
    sf::CircleShape shape;
    void draw(sf::RenderWindow &window);
};