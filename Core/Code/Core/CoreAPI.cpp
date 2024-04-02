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
	if (nKeyCode == 'C')
	{
		std::string strAppPath = Tool::GetApplicationPath() + "/ZmlCore.conf";
		Xml::CreateDefaultConf(strAppPath);
	}
}

void CoreAPI::Initialize(SystemAPI* pSystemAPI)
{
	pSystemAPI->iCoreAPI = this;
	pSystemAPI->iLanuchAPI->iAddFrameUpdateModule(this);
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

void CoreAPI::iFrameUpdate()
{
	DEBUG("CoreAPI iFrameUpdate.");
}