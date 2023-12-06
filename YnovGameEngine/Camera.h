#pragma once
#include <SFML/Graphics.hpp>
#include "AComponent.h"
#include "Application.h"

namespace YnovGameEngine {

	class Camera : public AComponent
	{
	private:
		float _rotation;
		sf::Vector2f _size;
		float _zoom;
		sf::Vector2f _center;
		//Entity* _entity;

	protected:
		//Camera _cameraInstance;
		sf::View _view;
		Application* _app;
		sf::RenderWindow* _window;

	public:
		Camera();
		void Update(float deltaTime);
		void SetView(sf::View newView);
		sf::View GetView();
		void SetZoom(float zoom);
		void SetViewport(sf::FloatRect newViewport);
		void SetRotation(float newRotation);
		void SetSize(sf::Vector2f size);
		void SetCenter(sf::Vector2f center);
		virtual void LateUpdate(float deltatime) override;
		sf::Vector2f GetCenter();
		float GetRotation();

	};
}
