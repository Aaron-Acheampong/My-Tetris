#include "TextComponent.h"

TextComponent::TextComponent(const char* filepath)
{
	m_font.loadFromFile(filepath);
	m_text.setFont(m_font);
	m_text.setCharacterSize(30);
	m_text.setStyle(sf::Text::Bold);
	m_text.setFillColor(sf::Color::Red);

}

TextComponent::~TextComponent()
{
}

void TextComponent::setPosition(float x, float y)
{
	m_text.setPosition(x, y);
}

void TextComponent::Render(sf::RenderWindow& ref)
{
	ref.draw(m_text);
}
