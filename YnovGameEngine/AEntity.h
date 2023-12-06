#pragma once
#include <SFML/Graphics.hpp>
#include "AComponent.h"

namespace YnovGameEngine {
	class Entity : public sf::Transformable, public sf::Drawable
	{
	
	protected:
		static int _ID;
		std::string _id;
		std::vector<AComponent*> _components;

	public: 
		Entity();
		//createEntity
		void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
		void Awake();
		void Start();
		void Update(float deltaTime);
		void LateUpdate(float deltaTime);

		template<typename T>
		T* AddComponent() {
			T* component = new T();
			_components.push_back(component);
			return component;
		};
		
		//template<typename T>
		std::vector<AComponent*> GetComponents() {
			return _components;
			//for (AComponent* comp : _components) {

			//	T* tcomponent = dynamic_cast<T*>(comp);
			//	if (tcomponent != nullptr) {
			//		return tcomponent;
			//	}
			//}
			//return nullptr;
		}

		template<typename T>
		void RemoveComponent() {
			for (AComponent* comp : _components) {
				T* tcomponent = dynamic_cast<T*>(comp);
				if (tcomponent != nullptr) {
					delete tcomponent;
				}
			}
		};

		std::string GetID();
	};
}

