#include "CoreCom.h"

ZML_API zml::ICoreAPI* InitializeCoreAPI(zml::SystemAPI* pSystemAPI)
{
	zml::CoreAPI* pCoreAPI = zml::CoreAPI::GetInstance();
	if (pCoreAPI) 
	{
		pCoreAPI->Initialize(pSystemAPI);
	}
	return pCoreAPI;
}

ZML_API void UninitializeCoreAPI()
{
	zml::CoreAPI* pCoreAPI = zml::CoreAPI::GetInstance();
	if (pCoreAPI)
	{
		pCoreAPI->Destroy();
	}
}
