#pragma once

#include "IRenderableComponent.h"

class TextComponent : public IRenderableComponent
{
public:
	TextComponent(const char* filepath, std::string txtdisplay);

	~TextComponent();

	void setPosition(float x, float y);

	void SetColor(sf::Color color);
	void SetFontSize(std::size_t font);
	void SetText(sf::String txt);
	void SetStyle(sf::Uint32 bold);

	void Render(sf::RenderWindow& ref);

private:
	sf::Font m_font;
	sf::Text m_text;
};

