#pragma once
#include <SFML/Graphics.hpp>
#include "AComponent.h"

namespace YnovGameEngine {
	class CircleComponent : public AComponent, public sf::Drawable
	{
	protected:
		sf::CircleShape _shape;

	public:
		CircleComponent();
		sf::CircleShape getShape() {
			return _shape;
		}
		virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
	};
}
