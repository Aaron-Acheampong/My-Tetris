#include "TetrisApp.h"

TetrisApp::TetrisApp(sf::VideoMode mod, const char* title)
{
	m_windowRenderer = new sf::RenderWindow(mod, title);
}

TetrisApp::~TetrisApp()
{
	m_windowRenderer->close();
}

void TetrisApp::SetEventCallback(std::function<void(void)> func)
{
	m_EventCallback = func;
}

void TetrisApp::SetUpdateCallback(std::function<void(void)> func)
{
	m_UpdateCallback = func;
}

void TetrisApp::SetRenderCallback(std::function<void(void)> func)
{
	m_RenderCallback = func;
}

void TetrisApp::RunLoop()
{
	sf::Clock clock;
	while (m_windowRenderer->isOpen())
	{
		float time = clock.getElapsedTime().asSeconds();
		clock.restart();
		timer += time;

		m_EventCallback();

		m_UpdateCallback();

		m_RenderCallback();
	}
}

void TetrisApp::SetMaxFrameRate(int frameRate)
{
	m_maxFrameRate = frameRate;
}

sf::RenderWindow* TetrisApp::GetRenderWindow() const
{
	return m_windowRenderer;
}


int TetrisApp::GetWindowWidth()
{
	return m_width;
}

int TetrisApp::GetWindowHeight()
{
	return m_height;
}

void TetrisApp::StopAppLoop()
{
}
