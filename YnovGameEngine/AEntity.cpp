#include "pch.h"
#include "AEntity.h"
#include "Application.h"

int YnovGameEngine::Entity::_ID = 0;

YnovGameEngine::Entity::Entity()
{
	_id = "ENT" + std::to_string(_ID++);
}

//draw (display) entity
void YnovGameEngine::Entity::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	states.transform.combine(getTransform());
	for (AComponent* comp : _components) {
		sf::Drawable* drawable = dynamic_cast<sf::Drawable*>(comp);
		if (drawable != nullptr) {
			target.draw(*drawable, states);
		}
	}
}

//TODO
void YnovGameEngine::Entity::Awake()
{
}

//TODO
void YnovGameEngine::Entity::Start()
{
}

//TODO
void YnovGameEngine::Entity::Update(float deltaTime)
{
	for (AComponent* comp : _components) {
		comp->Update(deltaTime);
	}
}

//TODO
void YnovGameEngine::Entity::LateUpdate(float deltaTime)
{
	for (AComponent* comp : _components) {
		comp->LateUpdate(deltaTime);
	}
}

//TODO
std::string YnovGameEngine::Entity::GetID() {
	return _id;
}