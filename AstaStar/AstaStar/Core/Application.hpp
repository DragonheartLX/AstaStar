#pragma once

namespace AstaStar
{
    class Application
    {
    public:
        Application() = default;
        Application(const Application&) = delete;

        ~Application();

        void run();
    private:
        bool m_IsRunning = true;
        float m_FixedUpdateTime = 1.0f / 60;
    };

    Application* createApplication();
} // namespace AstaStar
