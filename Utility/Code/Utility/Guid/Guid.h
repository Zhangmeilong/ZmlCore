#pragma once
#include "Interface.h"

namespace zml 
{
	class ZML_API Guid
	{
	public:
		static std::string							GetGUID();

	protected:
		static boost::uuids::random_generator		m_random_uuid;
	};
}