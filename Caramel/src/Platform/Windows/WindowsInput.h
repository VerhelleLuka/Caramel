#pragma once


#include "Caramel/Input.h"

namespace Caramel
{
	class WindowsInput : public Input
	{
	protected:
		virtual bool IsKeyPressedImpl(int keycode) override;

		virtual bool IsMouseButtonPressedImpl(int button) override;
		virtual float GetMouseXImpl() override;
		virtual float GetMouseYImpl() override;

		virtual std::pair<float, float> GetMousePosImpl() override;
	};
}