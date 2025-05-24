#pragma once

#include <functional>
#include <SFML/Graphics.hpp>
extern float timer;

class TetrisApp
{
public:
    // Constructor
    TetrisApp(sf::VideoMode mod, const char* title);

    // Destructor
    ~TetrisApp();

    // Handle Events
    void SetEventCallback(std::function<void(void)> func);

    // Handle Updates
    void SetUpdateCallback(std::function<void(void)> func);

    // Handle Render
    void SetRenderCallback(std::function<void(void)> func);

    // Loop our application
    void RunLoop();
 
    void SetMaxFrameRate(int frameRate);

    // Retrieve the renderer
    sf::RenderWindow* GetRenderWindow() const;

  
    // Return the window dimensions
    int GetWindowWidth();
    int GetWindowHeight();

    // Stop the main loop of our application
    void StopAppLoop();

private:
    // Pointer to our SDL Window Renderer
    sf::RenderWindow* m_windowRenderer = nullptr;


    // Set the maximum frame cap;
    int m_maxFrameRate;

  
    // Store width and height of window
    int m_width;
    int m_height;

    // Store our callback functions
    std::function<void(void)> m_EventCallback;
    std::function<void(void)> m_UpdateCallback;
    std::function<void(void)> m_RenderCallback;
};

