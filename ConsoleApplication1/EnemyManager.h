#pragma once
#include <YnovGameEngine/AEntity.h>
#include <YnovGameEngine/AComponent.h>

class EnemyManager : public YnovGameEngine::AComponent
{
protected:
	YnovGameEngine::Entity* _enemyEntity;
	std::vector<YnovGameEngine::Entity>* _enemies;
	int _maxEnemies;

public:
	EnemyManager(YnovGameEngine::Entity* _entity);
	void Update(float deltatime) override;
	void SpawnEnemy(const YnovGameEngine::Entity& enemy);
	void DestroyEnemy();
};