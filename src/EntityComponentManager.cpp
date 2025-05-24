#include "EntityComponentManager.h"

EntityComponentManager& EntityComponentManager::Instance()
{
	static EntityComponentManager* instance = new EntityComponentManager();

	return *instance;
}

std::shared_ptr<GameEntity> EntityComponentManager::CreateEntity(std::string name)
{
	// create a new entity
	std::shared_ptr<GameEntity> newEntity = std::make_shared<GameEntity>(name);
	// store entity in our unordered collection
	m_entities.insert(std::make_pair(name, newEntity));

	// return our new entity to the client
	return newEntity;
}

std::shared_ptr<GameEntity> EntityComponentManager::GetEntity(std::string name)
{
	return m_entities[name];
}

void EntityComponentManager::RenderAll(sf::RenderWindow& ref)
{
	for (auto it = m_entities.begin(); it != m_entities.end(); it++)
	{
		//std::string name = it->first;
		it->second->Render(ref);
	}
}
