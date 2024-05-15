#pragma once
#include <iostream>

#ifdef CRML_PLATFORM_WINDOWS

extern Caramel::Application* Caramel::CreateApplication();


int main(int argc, char** argv)
{
	std::cout << ("Caramel Engine");
	auto app = Caramel::CreateApplication();

	app->Run();

	delete app;
}
#else
#error Caramel only supports windows
#endif
