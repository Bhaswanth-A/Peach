#include "Peach.h"

class ExampleLayer : public Peach::Layer
{
public:
    ExampleLayer() : Layer("Example") {}

    void OnUpdate() override
    {
        PEACH_INFO("ExampleLayer::Update");
    }

    void OnEvent(Peach::Event &event) override
    {
        PEACH_TRACE("{0}", event);
    }
};

class Sandbox : public Peach::Application
{
public:
    Sandbox()
    {
        PushLayer(new ExampleLayer());
    }

    ~Sandbox()
    {
    }
};

Peach::Application *Peach::CreateApplication()
{
    return new Sandbox;
}