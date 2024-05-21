#include "crmlpch.h"
#include "Application.h"

#include "Caramel/Events/ApplicationEvent.h"
#include "Caramel/Log.h"
namespace Caramel
{
	Application::Application()
	{
	}

	Application::~Application()
	{

	}

	void Application::Run()
	{
		WindowResizeEvent e(1280, 720);
		CRML_TRACE(e.ToString());
		while (true)
		{
		}
	}
}
