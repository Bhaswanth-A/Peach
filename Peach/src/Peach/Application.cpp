#include "pch.h"
#include "Application.h"

#include "Peach/Events/ApplicationEvent.h"
#include "Peach/Log.h"

namespace Peach
{

    Application::Application()
    {
        m_Window = std::unique_ptr<Window>(Window::Create());
    }

    Application::~Application()
    {
    }

    void Application::Run()
    {
        
        while (m_Running)
        {
            m_Window->OnUpdate();
        }
    }
}