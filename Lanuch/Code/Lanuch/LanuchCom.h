#pragma once
#include "Interface.h"
#include "LanuchAPI.h"

ZML_API zml::SystemAPI*			InitializeLanuch(const std::string& strConfigFile);
ZML_API int						UninitializeLanuch();