#include "BoxCollider.h"

YnovGameEngine::BoxCollider::BoxCollider()
{
}

b2Shape* YnovGameEngine::BoxCollider::GetShape()
{
	return &_shape;
}

void YnovGameEngine::BoxCollider::SetSize(float newSizeWidth, float newSizeHeight)
{
	_widthSize = newSizeWidth;
	_heightSize = newSizeHeight;

	_shape.SetAsBox(newSizeWidth/2, newSizeHeight/2);
}
