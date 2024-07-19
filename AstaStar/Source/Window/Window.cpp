#include "Window/Window.hpp"
#include "Window/Windows/Window.hpp"

namespace AstaStar
{
    Window* Window::create(const WindowProps& props)
    {
        return new WindowsWindow(props);
    }
}