#pragma once
#include "Interface.h"
#include "LanuchAPI.h"

ZML_API zml::SystemAPI*			InitializeLanuchAPI(const std::string& strConfigFile);
ZML_API int						UninitializeLanuchAPI();

