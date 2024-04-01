#include "../../../Utility/Code/Utility/UtilityHeader.h"
#include "Interface.h"
#include "LanuchAPI.h"

using namespace zml;

SystemAPI* APIProvider::sm_pSystemAPI = nullptr;

LanuchAPI::LanuchAPI():
	pAPIProvider(nullptr)
{

}

void LanuchAPI::iKeyEvent(const uint8_t& nKeyCode, const bool& bDown)
{

}

void LanuchAPI::Initialize()
{
	DEBUG("Initialize LanuchAPI.");
	SystemAPI* pSystemAPI = new SystemAPI;
	pAPIProvider = new APIProvider(pSystemAPI);
	pSystemAPI->iLanuchAPI = this;

	Logger* pLogger = Logger::GetInstance();
	if (pLogger) 
	{
		pLogger->Info("Initialize LanuchAPI.");
	}
}

LanuchAPI* LanuchAPI::GetInstance()
{
	if (sm_pLanuchAPI == nullptr) 
	{
		sm_pLanuchAPI = new LanuchAPI();
	}
	return sm_pLanuchAPI;
}

void LanuchAPI::Destroy()
{
	DEL_PTR(sm_pLanuchAPI);

	APIProvider::GetSystemAPI()->iLanuchAPI = nullptr;

	Logger* pLogger = Logger::GetInstance();
	if (pLogger)
	{
		pLogger->Info("Destroy LanuchAPI.");
	}
}

LanuchAPI* LanuchAPI::sm_pLanuchAPI = nullptr;
