#pragma once
#include <iostream>
#include <string>
#include <windows.h>

#define DEBUG(strMessage) OutputDebugStringA(strMessage); \
						  OutputDebugStringA("\n")

namespace zml 
{
	class ILanuchAPI;
	class ICoreAPI;
	typedef struct __SystemAPI
	{
		ILanuchAPI* iLanuchAPI;
		ICoreAPI* iCoreAPI;
		__SystemAPI() 
		{
			iLanuchAPI = nullptr;
			iCoreAPI = nullptr;
		}

		~__SystemAPI() 
		{
			iLanuchAPI = nullptr;
			iCoreAPI = nullptr;
		}
	}SystemAPI;

	class APIProvider 
	{
		public:
			APIProvider(SystemAPI* pSystemAPI) 
			{ 
				sm_pSystemAPI = pSystemAPI; 
			}

			virtual ~APIProvider() {}

			static SystemAPI* GetSystemAPI() 
			{ 
				return sm_pSystemAPI; 
			}

	protected:
		static SystemAPI* sm_pSystemAPI;
	};

	typedef intptr_t ZML_PTR;
	class ZMLEvent 
	{
		int eMessage;
		ZML_PTR nParam1;
		ZML_PTR nParam2;
		ZML_PTR nParam3;
		ZML_PTR nParam4;
	};

	class IProcessModule
	{
	public:
		virtual void iKeyEvent(const int& nKeyCode, const bool& bDown) = 0;
	};

	class IFrameUpdateModule
	{
	public:
		virtual void iFrameUpdate() = 0;
	};

	class ILanuchAPI 
	{
	public:
		virtual void iAddFrameUpdateModule(IFrameUpdateModule* pIFrameUpdateModule) = 0;
		virtual void iRunFrame() = 0;
	};

}