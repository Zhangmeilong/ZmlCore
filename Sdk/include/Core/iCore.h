#pragma once

namespace zml 
{
	class ICore 
	{
	public:
		virtual void iKeyEvent(const uint8_t& nKeyCode, const bool& bDown) = 0;
	};
}