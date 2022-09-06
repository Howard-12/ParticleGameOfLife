#include "Dot.h"

Dot::Dot(float xpos, float ypos, sf::Color colour) : x(xpos), y(ypos) 
{
	shape.setRadius(size);
	shape.setFillColor(colour);
	shape.setPosition(x, y);
}

Dot::~Dot()
{

}

void Dot::draw(sf::RenderWindow &window)
{
	shape.setPosition(x, y);
	window.draw(shape);
}
