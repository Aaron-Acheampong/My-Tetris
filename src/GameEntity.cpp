#include "GameEntity.h"

GameEntity::GameEntity(std::string name): m_name(name)
{
	xDirection = 0.0f;
	yDirection = 0.0f;
}

GameEntity::~GameEntity() {}

void GameEntity::setPosition(float x, float y)
{
	m_x = x;
	m_y = y;
	for (int i = 0; i < m_components.size(); i++)
	{
		m_components[i]->setPosition(m_x, m_y);
	}
}

float GameEntity::GetXPosition() const
{
	return m_x;
}

float GameEntity::GetYPosition() const
{
	return m_y;
}

std::vector<std::shared_ptr<SpriteComponent>> GameEntity::GetComponents() const
{
	return m_components;
}

void GameEntity::AddSpriteComponent(std::string filename)
{
	std::shared_ptr<SpriteComponent> sprite2dComponent = std::make_shared<SpriteComponent>(filename);
	m_components.push_back(sprite2dComponent);
}

void GameEntity::Render(sf::RenderWindow& ref)
{
	for (int i = 0; i < m_components.size(); i++)
	{
		m_components[i]->Render(ref);
	}
}
