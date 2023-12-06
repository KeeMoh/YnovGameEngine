#include "CircleComponent.h"
#include <iostream>

YnovGameEngine::CircleComponent::CircleComponent()
{
	std::cout << " initialisation shape circleComponent";
	_shape.setRadius(100);
	_shape.setFillColor(sf::Color::Cyan);
}

void YnovGameEngine::CircleComponent::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	target.draw(_shape, states);
}
