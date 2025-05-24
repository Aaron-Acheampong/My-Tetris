#pragma once
#include <SFML/Graphics.hpp>



class IComponent
{
public:
	virtual ~IComponent() {};
	
	virtual void Update() = 0;
};
