#pragma once
#include <SFML/Graphics.hpp>
#include "AEntity.h"
#include "AComponent.h"
#include "ResourceManager.h"
#include "wtypes.h"
#include "AEntity.h"
#include <iostream>
#include "pch.h"
#include "yaml-cpp/yaml.h"
#include "Physics.h"

namespace YnovGameEngine {

	class Application
	{
	protected:
		sf::RenderWindow _window;
		ResourceManager* _resourceManager;
		static Application* _instance;
		void _Init(); //create window
		void _InitWindow(long horizontal, long vertical);
		void _HandleInput();
		std::vector<Entity*> _entities;
		Physics* _physics;

	public:
		Application();
		void Update(float deltatime);
		void Draw();
		void SetView();
		static Application* GetInstance();
		Entity* GetEntityFromComponent(AComponent* comp);
		void Loop(); // Loop > while (window.isopen()
		//void LinkEntityWithComponents(Entity* Entity, AComponent* Component);
		Physics* GetWorldPhysics();
		ResourceManager* GetResourceManager();
		Entity* CreateEntity();
		sf::RenderWindow* GetWindow();
		std::vector<Entity*> GetEntities();
		std::string GetInputKeyboard();
	};
}
