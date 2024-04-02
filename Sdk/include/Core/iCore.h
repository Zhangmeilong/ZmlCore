#pragma once

namespace zml 
{
	class IProcessModule;
	class ICoreAPI:
		public IProcessModule,
		public IFrameUpdateModule
	{
	public:
		virtual void iKeyEvent(const int& nKeyCode, const bool& bDown) = 0;
		virtual void iFrameUpdate() = 0;
	};
}