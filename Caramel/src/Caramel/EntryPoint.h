#pragma once
#include <iostream>

#ifdef CRML_PLATFORM_WINDOWS

extern Caramel::Application* Caramel::CreateApplication();


int main(int argc, char** argv)
{
	std::cout << ("Caramel Engine");

	Caramel::Log::Init();

	CRML_CORE_WARN("Initialized Log!");
	int a = 5;
	CRML_INFO("Hello! Var={0}", a);


	auto app = Caramel::CreateApplication();
	app->Run();
	delete app;
}
#else
#error Caramel only supports windows
#endif
