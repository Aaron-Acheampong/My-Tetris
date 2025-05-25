#include "TextComponent.h"

TextComponent::TextComponent(const char* filepath, std::string txtdisplay)
{
	m_font.loadFromFile(filepath);
	m_text.setFont(m_font);
	m_text.setCharacterSize(20);
	m_text.setStyle(sf::Text::Bold);
	m_text.setFillColor(sf::Color::Red);
	m_text.setString(txtdisplay);

}

TextComponent::~TextComponent()
{
}

void TextComponent::setPosition(float x, float y)
{
	m_text.setPosition(x, y);
}

void TextComponent::SetColor(sf::Color color)
{
	m_text.setFillColor(color);
}

void TextComponent::SetFontSize(std::size_t font)
{
	m_text.setCharacterSize(font);
}

void TextComponent::SetText(sf::String txt)
{
	m_text.setString(txt);
}

void TextComponent::SetStyle(sf::Uint32 bold)
{
	m_text.setStyle(bold);
}

void TextComponent::Render(sf::RenderWindow& ref)
{
	ref.draw(m_text);
}
