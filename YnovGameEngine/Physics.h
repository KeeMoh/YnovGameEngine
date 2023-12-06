#pragma once
#include <Box2d/Box2d.h>
//#include "Application.h"

namespace YnovGameEngine {
	class Application;

	class Physics
	{
	protected:
		b2Vec2 _gravity;
		b2World _world;
		Application* _app;
		float velocityIterations = 6;
		float positionIterations = 2;

	public:
		Physics();
		void Update(float deltatime);
		void PreUpdate();
		void PhysicUpdate();
		static const float WorldScale;
		b2World* GetWorld();
	};
}

