#pragma once
#include "Interface.h"
#include "CoreAPI.h"

ZML_API zml::ICoreAPI*			InitializeCoreAPI(zml::SystemAPI* pSystemAPI);
ZML_API void					UninitializeCoreAPI();