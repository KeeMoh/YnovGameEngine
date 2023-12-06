#include "CameraRotation.h"
#include <YnovGameEngine/Camera.h>
#include <YnovGameEngine/AEntity.h>
#include <YnovGameEngine/AComponent.h>

void CameraRotation::Update(float deltatime)
{
	YnovGameEngine::Application* app = YnovGameEngine::Application::GetInstance();
	YnovGameEngine::Entity* entity = app->GetEntityFromComponent(this);
	std::vector<YnovGameEngine::AComponent*> components = entity->GetComponents();

	for (YnovGameEngine::AComponent* component : components) {
		YnovGameEngine::Camera* camera = dynamic_cast<YnovGameEngine::Camera*>(component);
		if (camera) {
			//std::cout << "Camera rotate" << std::endl;
			camera->SetRotation(camera->GetRotation() + 10.f*deltatime);
		}
	}

}
