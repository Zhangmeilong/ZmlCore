#pragma once
#include "Interface.h"
#include "CoreAPI.h"

ZML_API zml::SystemAPI*			InitializeCore(zml::SystemAPI* pSystemAPI);
ZML_API int						UninitializeCore();