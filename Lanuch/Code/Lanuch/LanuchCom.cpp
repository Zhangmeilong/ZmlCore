#include "LanuchCom.h"

UninitializeCore_ptr coreUninit = nullptr;

ZML_API zml::SystemAPI* InitializeLanuchAPI(const std::string& strConfigFile)
{
	zml::LanuchAPI* pLanuchAPI = zml::LanuchAPI::GetInstance();
	if (pLanuchAPI)
	{
		pLanuchAPI->Initialize();
	}

	//¼ÓÔØDLL
	zml::SystemAPI* pSystemAPI = zml::APIProvider::GetSystemAPI();

#ifdef _DEBUG
	HMODULE core = ::LoadLibraryA("Cored.dll");
	if (core == nullptr) 
	{
		return nullptr;
	}
	InitializeCore_ptr coreInit = (InitializeCore_ptr)GetProcAddress(core, "InitializeCoreAPI");
	coreUninit = (UninitializeCore_ptr)GetProcAddress(core, "UninitializeCoreAPI");
	zml::ICoreAPI* pCoreAPI = coreInit(pSystemAPI);
	if (pCoreAPI == nullptr) 
	{
		return nullptr;
	}
#endif

	return zml::APIProvider::GetSystemAPI();
}

ZML_API int UninitializeLanuchAPI()
{
	zml::LanuchAPI* pLanuchAPI = zml::LanuchAPI::GetInstance();
	if (pLanuchAPI)
	{
		pLanuchAPI->Destroy();
		return 0;
	}
	if (coreUninit) 
	{
		coreUninit();
	}
	return -1;
}
