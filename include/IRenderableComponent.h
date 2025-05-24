#pragma once
#include "IComponent.h"

class IRenderableComponent : public IComponent
{
public:
	virtual ~IRenderableComponent() {}

	virtual void Update() {};

	virtual void Render(sf::RenderWindow& ref) = 0;


};

