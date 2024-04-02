#ifdef ZML_EXPORT
#define ZML_API _declspec(dllexport)
#else
#define ZML_API _declspec(dllimport)
#endif

#define DEL_PTR(ptr)		\
		while(ptr)			\
		{					\
			delete ptr;		\
			ptr = nullptr;	\
		}					\

#include "Lanuch/iLanuch.h"
#include "Utility/iUtility.h"
#include "Core/iCore.h"

typedef zml::SystemAPI* (*InitializeLanuch_ptr)(const std::string& strConfigFile);
typedef int				(*UninitializeLanuch_ptr)();

typedef zml::ICoreAPI*	(*InitializeCore_ptr)(zml::SystemAPI* pSystemAPI);
typedef void			(*UninitializeCore_ptr)();
