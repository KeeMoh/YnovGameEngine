#pragma once
#include "Collider.h"

namespace YnovGameEngine {
	class BoxCollider : public Collider
	{
	protected:
		float _heightSize;
		float _widthSize;
		b2PolygonShape _shape;

	public:
		BoxCollider();
		b2Shape* GetShape() override;
		void SetSize(float newSizeWidth, float newSizeHeight);
	};
}