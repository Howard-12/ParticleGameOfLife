#include "Dot.h"

Dot::Dot(float xpos, float ypos, sf::Color colour) {
	x = xpos;
	y = ypos;
	shape.setRadius(size);
	shape.setFillColor(colour);
}

Dot::~Dot()
{

}

void Dot::update(float deltaTime)
{
	if (shape.getPosition().x >= 475 || shape.getPosition().x <= 0)
	{
		speed *= -1;
	}
	x += speed * deltaTime;
	shape.setPosition(x, y);
}

void Dot::draw(sf::RenderWindow *window)
{
	window->draw(shape);
}
