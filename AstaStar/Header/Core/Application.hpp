#pragma once
#include "pch.hpp"
#include "Event/Event.hpp"
#include "Event/ApplicationEvent.hpp"
#include "Window/Window.hpp"

namespace AstaStar
{
    class Application
    {
    public:
        Application();
        ~Application();

        void run();
        void onEvent(Event& event);
        bool onWindowClose(WindowCloseEvent& event);
    private:
        bool m_IsRunning = true;
        float m_FixedUpdateTime = 1.0f / 60;

        std::unique_ptr<Window> m_Window;
    };

    Application* createApplication();
} // namespace AstaStar
