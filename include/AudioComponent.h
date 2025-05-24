#pragma once
#include <SFML/Audio.hpp>
#include "IComponent.h"

class AudioComponent : public IComponent
{
public:
	AudioComponent(const char* filepath);

	~AudioComponent();

	virtual void PlaySound();
	virtual void StopSound();
};

