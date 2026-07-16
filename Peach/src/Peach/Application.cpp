#include "pch.h"
#include "Application.h"

#include "Peach/Events/ApplicationEvent.h"
#include "Peach/Log.h"

namespace Peach
{

    Application::Application()
    {
    }

    Application::~Application()
    {
    }

    void Application::Run()
    {
        WindowResizeEvent e(1200, 720);
        PEACH_TRACE(e); 
        
        while (true)
            ;
    }
}