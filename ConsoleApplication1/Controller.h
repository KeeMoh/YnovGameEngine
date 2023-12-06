#pragma once
#include <YnovGameEngine/AComponent.h>
#include <YnovGameEngine/Application.h>
#include <YnovGameEngine/AEntity.h>

class Controller : public YnovGameEngine::AComponent
{
protected:
	YnovGameEngine::Application* _app;
	YnovGameEngine::Entity* _entity;

public:
	Controller();
	void Update(float deltatime) override;
	void Start() override;
};
