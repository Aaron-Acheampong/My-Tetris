#pragma once

#include <memory>
#include <vector>
#include <string>

#include "SpriteComponent.h"

class GameEntity
{
public:
	GameEntity(std::string name);

	~GameEntity();

	void setPosition(float x, float y);

	float GetXPosition() const;


	float GetYPosition() const;

	std::vector<std::shared_ptr<SpriteComponent>>GetComponents() const;


	// AddComponent, to add a new component
	void AddSpriteComponent(std::string filename);

	// Walk through all of the renderable components
	void Render(sf::RenderWindow& ref);

public:
	// TODO: 
	float xDirection;
	float yDirection;

private:
	float m_x, m_y;  // Positions of our Game Entity

	std::string m_name;
	std::vector<std::shared_ptr<SpriteComponent>> m_components;
};

