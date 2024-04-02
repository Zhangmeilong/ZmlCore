#include "CoreCom.h"

ZML_API zml::SystemAPI* InitializeCore(zml::SystemAPI* pSystemAPI)
{
	zml::CoreAPI* pCoreAPI = zml::CoreAPI::GetInstance();
	if (pCoreAPI) 
	{
		pCoreAPI->Initialize(pSystemAPI);
	}
	return pSystemAPI;
}

ZML_API int UninitializeCore()
{
	zml::CoreAPI* pCoreAPI = zml::CoreAPI::GetInstance();
	if (pCoreAPI)
	{
		pCoreAPI->Destroy();
		return 0;
	}
	return -1;
}
