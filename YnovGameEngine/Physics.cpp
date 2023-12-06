#include "Physics.h"
#include "AEntity.h"
#include "Rigidbody.h"
#include "Application.h"

YnovGameEngine::Physics::Physics() : _gravity(0,100), _world(_gravity)
{
	_app = YnovGameEngine::Application::GetInstance();
}

void YnovGameEngine::Physics::Update(float deltatime)
{
	//Ajuste la valeur de la position physique par rapport � la position graphique
	PreUpdate();
	
	//Appliquer la physic --> world.Step(timeStep, velocityIterations, positionIterations);
	_world.Step(deltatime, velocityIterations, positionIterations);

	//Puis remettre le graph � jour par rapport � la nouvelle position physic.
	PhysicUpdate();
}

void YnovGameEngine::Physics::PreUpdate()
{
	//r�cup�re toutes les entit�s de l'app et boucle sur chaque entit�
	std::vector<Entity*> entities = _app->GetEntities();
	for (Entity* entity : entities) {
		//r�cup�re tous les components li�s � l'entit�, puis boucle sur chaque component pour identifier s'il poss�de un Rigidbody
		std::vector <AComponent*> components = entity->GetComponents();
		for (AComponent* component : components) {
			//recherche les components qui sont impact�s par la physique du jeu.
			if (Rigidbody* rigidbody = dynamic_cast<Rigidbody*>(component))
			{
				rigidbody->SetBodyPosition(b2Vec2(entity->getPosition().x, entity->getPosition().y));
			}
		}
	}
}

void YnovGameEngine::Physics::PhysicUpdate()
{
	//Get Rigidbody then
	//set entity to _body->GetPosition().x && _body->GetPosition().y;
	std::vector<Entity*> entities = _app->GetEntities();
	for (Entity* entity : entities) {
		std::vector <AComponent*> components = entity->GetComponents();
		for (AComponent* component : components) {
			//recherche les components qui sont impact�s par la physique du jeu.
			if (Rigidbody* rigidbody = dynamic_cast<Rigidbody*>(component))
			{
				entity->setPosition(sf::Vector2(rigidbody->GetBodyPosition().x, rigidbody->GetBodyPosition().y));
			}
		}
	}
}

b2World* YnovGameEngine::Physics::GetWorld()
{
	return &_world;
}
