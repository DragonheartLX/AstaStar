#include "Window/Windows/Window.hpp"
#include "Core/Logger.hpp"
#include "Event/ApplicationEvent.hpp"
#include "Event/KeyEvent.hpp"
#include "Event/MouseEvent.hpp"

#include <GLFW/glfw3.h>

namespace AstaStar
{
    WindowsWindow::WindowsWindow(const WindowProps& props)
    {
        m_WindowCallBack.props = props;

        if (!glfwInit())
            AS_CRITICAL("GLFW Init error!");

        glfwWindowHint(GLFW_CLIENT_API, GLFW_NO_API);
        m_Window = glfwCreateWindow(m_WindowCallBack.props.width, m_WindowCallBack.props.height, m_WindowCallBack.props.title.c_str(), nullptr, nullptr);

        glfwSetWindowUserPointer(m_Window, &m_WindowCallBack);

        glfwSetWindowSizeCallback(m_Window, [](GLFWwindow* window, int width, int height)
		{
			auto& pWindowCallBack = *(WindowCallBack*)glfwGetWindowUserPointer(window);
			pWindowCallBack.props.width = width;
			pWindowCallBack.props.height = height;

			WindowResizeEvent event(width, height);
			pWindowCallBack.callBackFunc(event);
		});

        glfwSetWindowCloseCallback(m_Window, [](GLFWwindow* window)
		{
			auto& pWindowCallBack = *(WindowCallBack*)glfwGetWindowUserPointer(window);
			WindowCloseEvent event;
			pWindowCallBack.callBackFunc(event);
		});

        glfwSetKeyCallback(m_Window, [](GLFWwindow* window, int key, int scancode, int action, int mods)
        {
			auto& pWindowCallBack = *(WindowCallBack*)glfwGetWindowUserPointer(window);
            
            switch (action)
                {
                case GLFW_PRESS:
                {
                    KeyPressedEvent event(key, false);
                    pWindowCallBack.callBackFunc(event);
                    break;
                }
                case GLFW_RELEASE:
                {
                    KeyReleasedEvent event(key);
                    pWindowCallBack.callBackFunc(event);
                    break;
                }
                case GLFW_REPEAT:
                {
                    KeyPressedEvent event(key, true);
                    pWindowCallBack.callBackFunc(event);
                    break;
                }
			}
        });

        glfwSetCharCallback(m_Window, [](GLFWwindow* window, unsigned int keycode)
		{
			auto& pWindowCallBack = *(WindowCallBack*)glfwGetWindowUserPointer(window);

			KeyTypeEvent event(keycode);
			pWindowCallBack.callBackFunc(event);
		});

        glfwSetMouseButtonCallback(m_Window, [](GLFWwindow* window, int button, int action, int mods)
		{
			auto& pWindowCallBack = *(WindowCallBack*)glfwGetWindowUserPointer(window);

			switch (action)
			{
                case GLFW_PRESS:
                {
                    MouseButtonPressedEvent event(button);
                    pWindowCallBack.callBackFunc(event);
                    break;
                }
                case GLFW_RELEASE:
                {
                    MouseButtonReleasedEvent event(button);
                    pWindowCallBack.callBackFunc(event);
                    break;
                }
			}
		});

        glfwSetScrollCallback(m_Window, [](GLFWwindow* window, double xOffset, double yOffset)
        {
            auto& pWindowCallBack = *(WindowCallBack*)glfwGetWindowUserPointer(window);

            MouseScrolledEvent event(static_cast<float>(xOffset), static_cast<float>(yOffset));
            pWindowCallBack.callBackFunc(event);
        });

        glfwSetCursorPosCallback(m_Window, [](GLFWwindow* window, double xPos, double yPos)
        {
            auto& pWindowCallBack = *(WindowCallBack*)glfwGetWindowUserPointer(window);

            MouseMovedEvent event(static_cast<float>(xPos), static_cast<float>(yPos));
            pWindowCallBack.callBackFunc(event);
        });
    };

    WindowsWindow::~WindowsWindow()
    {
        glfwDestroyWindow(m_Window);
        glfwTerminate();
    };
    
    uint32_t const& WindowsWindow::getWindowHeight() const
    {
        return m_WindowCallBack.props.height;
    };
    
    uint32_t const& WindowsWindow::getWindowWidth() const
    {
        return  m_WindowCallBack.props.width;
    };

    bool WindowsWindow::isVSync() const
    {
        return m_WindowCallBack.props.isSync;
    };
    
    void WindowsWindow::setVSync(bool option)
    {
        m_WindowCallBack.props.isSync = option;
    };
    
    void WindowsWindow::onUpdate()
    {
        glfwPollEvents();
    };

    void WindowsWindow::setEventCallback(const EventCallBackFunc& callback)
    {
        m_WindowCallBack.callBackFunc = callback;
    };
}