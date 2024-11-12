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

		if (Caramel::Input::IsKeyPressed(CRML_KEY_TAB))
			CRML_INFO("Tab key is pressed!");

	}
	void OnEvent(Caramel::Event& event) override
	{
		//CRML_TRACE("{0}", event.ToString());
		if (event.GetEventType() == Caramel::EventType::KeyPressed)
		{
			Caramel::KeyPressedEvent& e = (Caramel::KeyPressedEvent&)event;
			CRML_TRACE("{0}", (char)e.GetKeyCode());
		}
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