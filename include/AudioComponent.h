#pragma once
#include <SFML/Audio.hpp>
#include "IComponent.h"

class AudioComponent : public IComponent
{
public:
	AudioComponent(std::string filepath, bool setloop, float volume, float pitch);

	~AudioComponent();

	void PlaySound();
	void PauseSound();
	void StopSound();
	void SetAudioOffset(float offset);

	void Update();

private:
	sf::Music music;
};

