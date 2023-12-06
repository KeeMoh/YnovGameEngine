#include "AComponent.h"
#include <SFML/Graphics.hpp>
namespace YnovGameEngine {
#pragma once
	class SpriteRenderer : public AComponent, public sf::Drawable
	{
	protected:
		sf::Texture _texture;
		sf::Sprite _sprite;

	public:
		void CreateSprite(std::string path);
		sf::Texture LoadTexture(std::string path);
		//void setSprite();
		sf::Sprite GetSprite();
		void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
		sf::Vector2f GetSize();
	};
}
