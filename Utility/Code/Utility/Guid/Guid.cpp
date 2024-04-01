#include "Guid.h"

using namespace zml;

std::string Guid::GetGUID()
{
	return boost::uuids::to_string(m_random_uuid());
}

boost::uuids::random_generator Guid::m_random_uuid;
