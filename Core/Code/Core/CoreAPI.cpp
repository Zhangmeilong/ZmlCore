#include "../../../Utility/Code/Utility/UtilityHeader.h"
#include "Interface.h"
#include "CoreAPI.h"

using namespace zml;

CoreAPI* CoreAPI::sm_pCoreAPI = nullptr;
SystemAPI* APIProvider::sm_pSystemAPI = nullptr;

CoreAPI::CoreAPI() :
	m_pAPIProvider(nullptr)
{

}

void CoreAPI::iKeyEvent(const uint8_t& nKeyCode, const bool& bDown)
{

}

void CoreAPI::Initialize(SystemAPI* pSystemAPI)
{
	pSystemAPI->iCore = this;
}

void CoreAPI::Destroy()
{
	DEL_PTR(sm_pCoreAPI);
	APIProvider::GetSystemAPI()->iCore = nullptr;
}

CoreAPI* CoreAPI::GetInstance()
{
	if (sm_pCoreAPI == nullptr) 
	{
		sm_pCoreAPI = new CoreAPI();
	}
	return sm_pCoreAPI;
}