#include "LanuchCom.h"

ZML_API zml::SystemAPI* InitializeLanuch(const std::string& strConfigFile)
{
	zml::LanuchAPI* pLanuchAPI = zml::LanuchAPI::GetInstance();
	if (pLanuchAPI)
	{
		pLanuchAPI->Initialize();
	}
	return zml::APIProvider::GetSystemAPI();
}

ZML_API int UninitializeLanuch()
{
	zml::LanuchAPI* pLanuchAPI = zml::LanuchAPI::GetInstance();
	if (pLanuchAPI)
	{
		pLanuchAPI->Destroy();
		return 0;
	}
	return -1;
}
