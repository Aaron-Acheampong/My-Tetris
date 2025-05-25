#include "AudioComponent.h"

AudioComponent::AudioComponent(std::string filepath, bool setloop, float volume, float pitch)
{
	music.openFromFile(filepath);
	music.setPitch(pitch);
	music.setVolume(volume);
	music.setLoop(setloop);
}

AudioComponent::~AudioComponent()
{
}

void AudioComponent::PlaySound()
{
	music.play();
}

void AudioComponent::PauseSound()
{
	music.pause();
}

void AudioComponent::StopSound()
{
	music.stop();
}

void AudioComponent::SetAudioOffset(float offset)
{
	music.setPlayingOffset(sf::seconds(offset));
}

void AudioComponent::Update()
{
}
