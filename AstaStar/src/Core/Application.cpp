#include "AstaStar/Core/Application.hpp"
#include <chrono>

namespace AstaStar
{
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

            if (deltaTime > m_FixedUpdateTime)
                deltaTime -= m_FixedUpdateTime;
        }
    }
} // namespace AstaStar
