#include "Controller.h"
#include <iostream>
#include <SFML/Window/Keyboard.hpp>

Controller::Controller()
{
    Awake();
    Start();
}

void Controller::Update(float deltatime)
{
    
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
    {
        _entity = _app->GetEntityFromComponent(this);
        std::cout << "Update Controller" << std::endl;
        sf::Vector2f _position = sf::Vector2f(_entity->getPosition().x, _entity->getPosition().y);
        // left key is pressed: move our character
        _entity->setPosition(_position.x -1.f, _position.y);
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
    {
        _entity = _app->GetEntityFromComponent(this);
        std::cout << "Update Controller" << std::endl;
        sf::Vector2f _position = sf::Vector2f(_entity->getPosition().x, _entity->getPosition().y);
        // left key is pressed: move our character
        _entity->setPosition(_position.x + 1.f, _position.y);
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
    {
        _entity = _app->GetEntityFromComponent(this);
        std::cout << "Update Controller" << std::endl;
        sf::Vector2f _position = sf::Vector2f(_entity->getPosition().x, _entity->getPosition().y);
        // left key is pressed: move our character
        _entity->setPosition(_position.x, _position.y + 1.f);
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
    {
        _entity = _app->GetEntityFromComponent(this);
        std::cout << "Update Controller" << std::endl;
        sf::Vector2f _position = sf::Vector2f(_entity->getPosition().x, _entity->getPosition().y);
        // left key is pressed: move our character
        _entity->setPosition(_position.x, _position.y - 1.f);
    }
}

void Controller::Start()
{
    std::cout << "Start Controller" << std::endl;
    _app = YnovGameEngine::Application::GetInstance();
}
