#include "pch.h"
#include "AComponent.h"

int YnovGameEngine::AComponent::_ID = 0;

//Constructor
YnovGameEngine::AComponent::AComponent()
{
	_id = "COM" + std::to_string(_ID++);
	Awake();
	Start();
}

void YnovGameEngine::AComponent::Awake()
{
}

void YnovGameEngine::AComponent::Start()
{
}

void YnovGameEngine::AComponent::Update(float deltatime)
{
}

void YnovGameEngine::AComponent::LateUpdate(float deltatime)
{
}

std::string YnovGameEngine::AComponent::GetId()
{
	return _id;
}
