#include "Caramel.h"

class ExampleLayer : public Caramel::Layer
{
public:
	ExampleLayer()
		:Layer("Example")
	{}

	void OnUpdate() override
	{
		//CRML_INFO("ExampleLayer::Update");

	}
	void OnEvent(Caramel::Event& event) override
	{
		//CRML_TRACE("{0}", event.ToString());
	}
};

class Sanbox : public Caramel::Application
{
public:
	Sanbox()
	{
		PushLayer(new ExampleLayer());
		PushOverlay(new Caramel::ImGuiLayer());
	}
	~Sanbox()
	{

	}
};

Caramel::Application* Caramel::CreateApplication()
{
	return new Sanbox;
}