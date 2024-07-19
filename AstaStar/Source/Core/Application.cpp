#include "pch.hpp"
#include "Core/Logger.hpp"
#include "Core/Application.hpp"

namespace AstaStar
{
    Application::Application()
    {
        m_Window = std::unique_ptr<Window>(Window::create({WindowProps()}));
        m_Window->setEventCallback(std::bind(&Application::onEvent, this, std::placeholders::_1));
    }

    Application::~Application()
    {
        
    }

    void Application::run()
    {
        while (m_IsRunning)
        {
            static std::chrono::time_point<std::chrono::steady_clock> lastTime = std::chrono::high_resolution_clock::now();
            static float deltaTime = 0.0f;

            std::chrono::time_point<std::chrono::steady_clock> currentTime = std::chrono::high_resolution_clock::now();
            float delta = std::chrono::duration<float, std::chrono::seconds::period>(currentTime - lastTime).count();

            lastTime = currentTime;
            deltaTime += delta;

            // Update
            m_Window->onUpdate();
            
            if (deltaTime > m_FixedUpdateTime)
            {
                // Fixed Update

                deltaTime = 0.0f;
            }
        }
    }

    void Application::onEvent(Event& event)
    {
        AS_DEBUG(event.toString());
        EventDispatcher dispatcher(event);

        dispatcher.dispatch<WindowCloseEvent>(std::bind(&Application::onWindowClose, this, std::placeholders::_1));
    }

    bool Application::onWindowClose(WindowCloseEvent& event)
    {
        m_IsRunning = false;
        return true;
    }
} // namespace AstaStar
