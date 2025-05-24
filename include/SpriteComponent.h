#pragma once
#include "IRenderableComponent.h"


class SpriteComponent : public IRenderableComponent
{
public:
	SpriteComponent(std::string filepath);

	~SpriteComponent();

	void setTextureRect(const sf::IntRect& rectangle);

	void setPosition(float x, float y);
	void move(sf::Vector2f vec);

	void update() {};

	void Render(sf::RenderWindow& ref);

private:
	sf::Texture m_texture;
	sf::Sprite m_sprite;
};

