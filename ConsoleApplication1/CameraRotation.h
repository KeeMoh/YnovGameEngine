#pragma once
#include <YnovGameEngine/AComponent.h>

class CameraRotation : public YnovGameEngine::AComponent
{
public:
	void Update(float deltatime) override;
};
