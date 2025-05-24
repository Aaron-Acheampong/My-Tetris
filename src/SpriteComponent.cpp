#include "SpriteComponent.h"

SpriteComponent::SpriteComponent(std::string filepath)
{
	// Setup our sprite with a texture.
	m_texture.loadFromFile(filepath);
	m_sprite.setTexture(m_texture);
}


SpriteComponent::~SpriteComponent()
{
}

void SpriteComponent::setTextureRect(const sf::IntRect& rectangle)
{
	m_sprite.setTextureRect(rectangle);
}


void SpriteComponent::setPosition(float x, float y)
{

	m_sprite.setPosition(x, y);
}

void SpriteComponent::move(sf::Vector2f vec)
{
	m_sprite.move(vec);
}



void SpriteComponent::Render(sf::RenderWindow& ref)
{
	ref.draw(m_sprite);
}

