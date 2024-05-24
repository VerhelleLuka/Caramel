#include "crmlpch.h"
#include "Application.h"
#include "Application.h"

#include "Caramel/Log.h"
namespace Caramel
{
#define BIND_EVENT_FN(x) std::bind(&x, this, std::placeholders::_1)

	Application::Application()
	{
		m_Window = std::unique_ptr<Window>(Window::Create());
		m_Window->SetEventCallback(BIND_EVENT_FN(Application::OnEvent));
	}

	Application::~Application()
	{

	}
	void Application::OnEvent(Event& e)
	{
		//Log all events
		CRML_CORE_INFO("{0}", e.ToString());

		EventDispatcher dispatcher(e);

		//Bind the window close event to the OnWindowClosed function
		dispatcher.Dispatch<WindowCloseEvent>(BIND_EVENT_FN(Application::OnWindowClosed));

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
			m_Window->OnUpdate();
		}
	}
}
