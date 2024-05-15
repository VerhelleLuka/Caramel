#include "Caramel.h"

class Sanbox : public Caramel::Application
{
public:
	Sanbox()
	{

	}
	~Sanbox()
	{

	}
};

Caramel::Application* Caramel::CreateApplication()
{
	return new Sanbox;
}