#include "camera.h"
#include "Application.h"

YnovGameEngine::Camera::Camera()
{
	//_view get defaultview
	//sf::View view1(sf::FloatRect(200, 200, 300, 200));
	// création d'une vue à partir de sa position centrale et de sa taille
	_app = Application::GetInstance();
	_window = _app->GetWindow();
	_view = _window->getDefaultView();

	//_entity = _app->GetEntityFromComponent(this);

	_center = sf::Vector2f(0, 0);// _entity->getPosition();
	_rotation = 0; // _entity->getRotation();
}

void YnovGameEngine::Camera::Update(float deltatime)
{
	//sf::View _view;
	//_view.setCenter(200, 200);
	//_view.setRotation(20);
	//_view.setSize(1200, 800);
	//_view.zoom(0.5f);
}

void YnovGameEngine::Camera::SetViewport(sf::FloatRect newViewport)
{
	_view.setViewport(newViewport);
}

void YnovGameEngine::Camera::SetZoom(float newZoom)
{
	_view.zoom(newZoom);
}

void YnovGameEngine::Camera::SetRotation(float newRotation)
{
	_rotation = newRotation;
	//_view.setRotation(newRotation);
}

void YnovGameEngine::Camera::SetSize(sf::Vector2f size)
{
	_view.setSize(size);
}

void YnovGameEngine::Camera::SetCenter(sf::Vector2f center)
{
	_center = center;
	//_view.setCenter(x, y);
}

void YnovGameEngine::Camera::LateUpdate(float deltatime)
{
	//sf::View _view;
//_view.setCenter(200, 200);
//_view.setRotation(20);
//_view.setSize(1200, 800);
//_view.zoom(0.5f);

	//Récupère l'entité liée à la caméra component
	Entity* entity = _app->GetEntityFromComponent(this);
	//entity->getTransform();

	_view.setCenter(entity->getPosition() + _center);
	_view.setRotation(entity->getRotation() + _rotation);

	//_view.setRotation(entity->getRotation());
	//entity->setRotation(entity->getRotation()+1);
	//_view.setSize(1200, 800);
	//_view.zoom(0.5f);
	_window->setView(_view);
}

void YnovGameEngine::Camera::SetView(sf::View newView)
{
	_view = newView;
}


sf::View YnovGameEngine::Camera::GetView()
{
	return _view;
}

sf::Vector2f YnovGameEngine::Camera::GetCenter()
{
	return _center;
}

float YnovGameEngine::Camera::GetRotation()
{
	return _rotation;
}
