#pragma once
#include "Core.h"
#include "Events/Event.h"

namespace Caramel
{
	class __declspec(dllexport) Application
	{
	public:
		Application();
		virtual ~Application();
		void Run();
	};

	//To be defined in client
	Application* CreateApplication();
}
