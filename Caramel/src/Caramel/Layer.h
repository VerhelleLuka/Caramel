#pragma once
#include "Caramel/Core.h"

#include "Caramel/Events/Event.h"
namespace Caramel
{
	class CARAMEL_API Layer
	{
	public:

		Layer(const std::string& name = "Layer");
		virtual ~Layer();

		virtual void OnAttach() {}
		virtual void OnDetach(){}
		virtual void OnUpdate(){}
		virtual void OnEvent(Event& event){}

		inline const std::string& GetName() const { return m_DebugName; }

	protected:
		std::string m_DebugName;	
	};

}

