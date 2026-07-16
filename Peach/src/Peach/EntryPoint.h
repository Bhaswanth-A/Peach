#pragma once

extern Peach::Application *Peach::CreateApplication();

int main(int argc, char **argv)
{

    Peach::Log::Init();
    PEACH_CORE_WARN("Initialized logging");
    PEACH_INFO("APP");

    printf("Peach Engine\n");
    auto app = Peach::CreateApplication();
    app->Run();
    delete app;
}