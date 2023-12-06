#include "Rigidbody.h"
#include "Physics.h"
#include "Application.h"
#include <Box2D/b2_contact.h>
//#include <cstdlib>

YnovGameEngine::Rigidbody::Rigidbody()
{
	YnovGameEngine::Physics* _physics = YnovGameEngine::Application::GetInstance()->GetWorldPhysics();
	
	_body = _physics->GetWorld()->CreateBody(&_bodyDef);
	for (b2ContactEdge* contact = _body->GetContactList(); contact != nullptr; contact = contact->next)
	{
		if (contact->contact->IsTouching())
		{
			// Do what you want here
			std::cout << "contact ----------" << std::endl;
			std::cout << contact->other << std::endl;
		}
	}
}

void YnovGameEngine::Rigidbody::SetBodyType(b2BodyType bodyType)
{
	if (_body) {
		_body->SetType(bodyType);
	}
	else {
		_bodyDef.type = bodyType;
	}
}

void YnovGameEngine::Rigidbody::SetBodyPosition(b2Vec2 bodyPosition)
{
	if (_body) {
		_body->SetTransform(bodyPosition, GetBodyAngular());
	}
	else {
		_bodyDef.position = bodyPosition;
	}
}

void YnovGameEngine::Rigidbody::SetLinearVelocity(b2Vec2 linearVelocity)
{
	if (_body) {
		_body->SetLinearVelocity(linearVelocity);
	}
	else {
		_bodyDef.linearVelocity = linearVelocity;
	}
}

void YnovGameEngine::Rigidbody::SetAngularVelocity(float angularVelocity)
{
	if (_body) {
		_body->SetAngularVelocity(angularVelocity);
	}
	else {
		_bodyDef.angularVelocity = angularVelocity;
	}
}

b2Vec2 YnovGameEngine::Rigidbody::GetBodyPosition()
{
	if (_body) {
		return _body->GetPosition();
	}

	return _bodyDef.position;
}

float YnovGameEngine::Rigidbody::GetBodyAngular()
{
	if (_body) {
		return _body->GetAngle();
	}

	return _bodyDef.angle;
}

b2Vec2 YnovGameEngine::Rigidbody::GetLinearVelocity()
{
	if (_body) {
		return _body->GetLinearVelocity();
	}

	return _bodyDef.linearVelocity;
}

float YnovGameEngine::Rigidbody::GetAngularVelocity()
{
	if (_body) {
		_body->GetLinearVelocity();
	}

	return _bodyDef.angularVelocity;
}

b2Body* YnovGameEngine::Rigidbody::GetBody()
{
	if (_body) {
		return _body;
	}

	return NULL;
}
