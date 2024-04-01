#pragma once
#include <iostream>
#include <string>
#include <windows.h>

#define DEBUG(strMessage) OutputDebugStringA(strMessage); \
						  OutputDebugStringA("\n")

namespace zml 
{
	class ILanuch;
	class ICore;
	typedef struct __SystemAPI
	{
		ILanuch* iLanuchAPI;
		ICore* iCore;
		__SystemAPI() 
		{
			iLanuchAPI = nullptr;
			iCore = nullptr;
		}

		~__SystemAPI() 
		{
			iLanuchAPI = nullptr;
			iCore = nullptr;
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

	class ILanuch 
	{
	public:
		virtual void iKeyEvent(const uint8_t& nKeyCode, const bool& bDown) = 0;
	};
}