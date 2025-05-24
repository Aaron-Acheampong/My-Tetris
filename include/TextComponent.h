#pragma once

#include "IRenderableComponent.h"

class TextComponent : public IRenderableComponent
{
public:
	TextComponent(const char* filepath);

	~TextComponent();

	void setPosition(float x, float y);

	void Render(sf::RenderWindow& ref);

private:
	sf::Font m_font;
	sf::Text m_text;
};

