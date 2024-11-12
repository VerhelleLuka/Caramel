#pragma once


#include "Caramel/Input.h"

namespace Caramel
{
	class WindowsInput : public Input
	{
	protected:
		//This  "virtual" is a reminder that it overrides from input, but it is functionally useless
		virtual bool IsKeyPressedImpl(int keycode) override;

		virtual bool IsMouseButtonPressedImpl(int button) override;
		virtual float GetMouseXImpl() override;
		virtual float GetMouseYImpl() override;

		virtual std::pair<float, float> GetMousePosImpl() override;
	};
}