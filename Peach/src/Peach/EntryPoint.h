#pragma once

extern Peach::Application* Peach::CreateApplication();

int main(int argc, char** argv){
    
    printf("Peach Engine\n");
    auto app = Peach::CreateApplication();
    app->Run();
    delete app;


}