#include "Window/Window.hpp"

struct GLFWwindow;

namespace AstaStar
{
    class WindowsWindow : public Window
    {
    public:
        WindowsWindow(const WindowProps& props);
        ~WindowsWindow() override;

		virtual uint32_t const& getWindowHeight() const override;
		virtual uint32_t const& getWindowWidth() const override;
		virtual bool isVSync() const override;
		virtual void setVSync(bool option) override;
		virtual void onUpdate() override;
		virtual void setEventCallback(const EventCallBackFunc& callback) override;

    private:
        GLFWwindow* m_Window;

        struct WindowCallBack
        {
            WindowProps props;
            EventCallBackFunc callBackFunc;
        };

        WindowCallBack m_WindowCallBack;
    };
}