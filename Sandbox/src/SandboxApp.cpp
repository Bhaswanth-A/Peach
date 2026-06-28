#include "Peach.h"

class Sandbox : public Peach::Application{
public:
    Sandbox(){

    }

    ~Sandbox(){

    }

};

Peach::Application* Peach::CreateApplication(){
    return new Sandbox;
}