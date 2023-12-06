#include "EnemyManager.h"

EnemyManager::EnemyManager(YnovGameEngine::Entity* _entity)
{
	_enemyEntity = _entity;
}

void EnemyManager::Update(float deltatime)
{
	if (_enemies->size() < _maxEnemies) {
		//SpawnEnemy(YnovGameEngine::Entity entity = new YnovGameEngine::Entity)
	}
}

void EnemyManager::SpawnEnemy(const YnovGameEngine::Entity &enemy)
{
	
}

void EnemyManager::DestroyEnemy()
{
}
