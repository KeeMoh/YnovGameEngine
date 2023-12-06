#pragma once
#include <Box2D/box2d.h>
#include <SFML/Graphics.hpp>
#include "AComponent.h"

namespace YnovGameEngine {
	class Rigidbody : public AComponent
	{
	protected:
		b2BodyDef _bodyDef;
		b2Body* _body;

	public:
		Rigidbody();
		void SetBodyType(b2BodyType bodyType);
		void SetBodyPosition(b2Vec2 bodyPosition);
		void SetLinearVelocity(b2Vec2 linearVelocity);
		void SetAngularVelocity(float angularVelocity);

		b2Vec2 GetBodyPosition();
		float GetBodyAngular();
		b2Vec2 GetLinearVelocity();
		float GetAngularVelocity();
		b2Body* GetBody();
	};
}