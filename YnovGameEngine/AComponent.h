#pragma once
#include <string>

namespace YnovGameEngine {
	class AComponent
	{
	protected:
		static int _ID;
		std::string _id;

	public: 
		AComponent();
		virtual void Awake();
		virtual void Start();
		virtual void Update(float deltatime);
		virtual void LateUpdate(float deltatime);

		std::string GetId();
	};
}


