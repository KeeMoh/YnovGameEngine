#include "spriterenderer.h"
#include <iostream>


void YnovGameEngine::SpriteRenderer::CreateSprite(std::string path)
{
	LoadTexture(path);
	_sprite.setTexture(_texture);

}



sf::Texture YnovGameEngine::SpriteRenderer::LoadTexture(std::string path)
{
	if(!_texture.loadFromFile(path)) {
		std::cout << "could not load the file path : " + path;
	}
	return _texture;
}

sf::Sprite YnovGameEngine::SpriteRenderer::GetSprite()
{
	return _sprite;
}


void YnovGameEngine::SpriteRenderer::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	target.draw(_sprite, states);
}

sf::Vector2f YnovGameEngine::SpriteRenderer::GetSize()
{
	return sf::Vector2f(GetSprite().getGlobalBounds().width, GetSprite().getGlobalBounds().width);
}
