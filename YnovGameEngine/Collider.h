#pragma once
#include "AComponent.h"
#include <Box2d/box2d.h>
#include "Rigidbody.h"

namespace YnovGameEngine {
	class Collider : public AComponent
	{
	protected:
		b2FixtureDef _fixtureDef;
		b2Fixture* _fixture;

	public:
		Collider();
		//La fonction pour créer la fixture en paramètre le body du rigidbody
		void CreateFixture(b2Body* body);
		virtual b2Shape* GetShape() = 0;
		void SetColliderDensity(float newDensity);
		void SetColliderFriction(float newFriction);
	};
}