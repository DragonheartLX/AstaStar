#pragma once
#include "pch.hpp"
#include "Event/Event.hpp"

namespace AstaStar
{
    struct WindowProps
    {
        std::string title = "AstaStar Application";
        uint32_t width = 1280;
        uint32_t height = 720;
        bool isSync = true;
    };

    class Window
    {
    public:
        using EventCallBackFunc = std::function<void(Event&)>;
    
        virtual ~Window() {};
		virtual uint32_t const& getWindowHeight() const = 0;
		virtual uint32_t const& getWindowWidth() const = 0;
		virtual bool isVSync() const = 0;
		virtual void setVSync(bool option) = 0;
		virtual void onUpdate() = 0;
		virtual void setEventCallback(const EventCallBackFunc& callback) = 0;

		static Window* create(const WindowProps& props = WindowProps());
    };
}