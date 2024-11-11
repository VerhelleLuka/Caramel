#include "crmlpch.h"
#include "Application.h"
#include "Application.h"

#include "Caramel/Log.h"
#include <glad/glad.h>
#include "ImGui/ImGuiLayer.h"
#include <imgui.h>

#include "Input.h"
namespace Caramel
{

	Application* Application::s_Instance = nullptr;

	Application::Application()
	{
		CRML_CORE_ASSERT(!s_Instance, "Application already exists!");
		s_Instance = this;

		m_Window = std::unique_ptr<Window>(Window::Create());
		m_Window->SetEventCallback(BIND_EVENT_FN(Application::OnEvent));
	}

	Application::~Application()
	{

	}

	void Application::PushLayer(Layer* layer)
	{
		m_LayerStack.PushLayer(layer);
		layer->OnAttach();
	}

	void Application::PushOverlay(Layer* layer)
	{
		m_LayerStack.PushOverlay(layer);
		layer->OnAttach();
	}

	void Application::OnEvent(Event& e)
	{
		//Log all events
		//CRML_CORE_INFO("{0}", e.ToString());

		EventDispatcher dispatcher(e);

		//Bind the window close event to the OnWindowClosed function
		dispatcher.Dispatch<WindowCloseEvent>(BIND_EVENT_FN(Application::OnWindowClosed));


		//Loop backwards over layerstack for events
		for (auto it = m_LayerStack.end(); it != m_LayerStack.begin();)
		{
			(*--it)->OnEvent(e);
			if (e.Handled)
				break;
		}

	}
	
	bool Application::OnWindowClosed(WindowCloseEvent& e)
	{
		m_Running = false;
		return true;
	}
	void Application::Run()
	{

		while (m_Running)
		{

			for (Layer* layer : m_LayerStack)
			{
				layer->OnUpdate();
			}
			auto [x, y] = Input::GetMousePos();
			CRML_CORE_TRACE("{0}, {1}", x, y);
			m_Window->OnUpdate();
			glClearColor(1,0,0,0.5);
			glClear(GL_COLOR_BUFFER_BIT);
		}

	}
}
