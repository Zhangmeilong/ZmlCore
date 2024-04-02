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

void CoreAPI::iKeyEvent(const int& nKeyCode, const bool& bDown)
{
	std::string strMessage = "nKeyCode: " + std::to_string(nKeyCode);
	strMessage += bDown ? ", true" : ", false";
	Logger* pLogger = Logger::GetInstance();
	if (pLogger)
	{
		pLogger->Debug(strMessage);
	}
}

void CoreAPI::Initialize(SystemAPI* pSystemAPI)
{
	pSystemAPI->iCore = this;
}

void CoreAPI::Destroy()
{
	DEL_PTR(sm_pCoreAPI);
}

CoreAPI* CoreAPI::GetInstance()
{
	if (sm_pCoreAPI == nullptr)
	{
		sm_pCoreAPI = new CoreAPI();
	}
	return sm_pCoreAPI;
}