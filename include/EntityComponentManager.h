#pragma once

#include <unordered_map>
#include <memory>

#include "GameEntity.h"

class EntityComponentManager
{
public:
	static EntityComponentManager& Instance();

	// create new Entity
	// And then add it to our container data structure
	std::shared_ptr<GameEntity> CreateEntity(std::string name);

	// retrieve an entity
	std::shared_ptr<GameEntity> GetEntity(std::string name);

	// Render all entities
	void RenderAll(sf::RenderWindow& ref);



private:
	EntityComponentManager() {}
	~EntityComponentManager() {}

	// Our container structure
	std::unordered_map<std::string, std::shared_ptr<GameEntity>> m_entities;
};

