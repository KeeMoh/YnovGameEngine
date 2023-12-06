#include "Collider.h"


YnovGameEngine::Collider::Collider()
{
}

void YnovGameEngine::Collider::SetColliderDensity(float newDensity)
{
	if (_fixture) {
		_fixture->SetDensity(newDensity);
	}
	_fixtureDef.density = newDensity;
}

void YnovGameEngine::Collider::SetColliderFriction(float newFriction)
{
	if (_fixture) {
		_fixture->SetFriction(newFriction);
	}
	_fixtureDef.friction = newFriction;
}

void YnovGameEngine::Collider::CreateFixture(b2Body* body)
{
	_fixtureDef.shape = GetShape();
	_fixture = body->CreateFixture(&_fixtureDef);
}


