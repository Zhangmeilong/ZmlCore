#pragma once
#include "Interface.h"

namespace zml 
{
	class ZML_API Device
	{
	public:
		typedef struct _ComputerInfo
		{
			int			nScreenWidth = 0;
			int			nScreenHeight = 0;
			double		dScreenDPI = 0;
			std::string strComputerName;
			std::string strUserAccount;
			double		dUsedMemoryPer = 0.0;
			double		dTotalMemory = 0.0;
			double		dFreeMemory = 0.0;
		}ComputerInfo;
		Device();
		~Device();
		void								GetComputerInfo(ComputerInfo& info);
		double								GetCurProcessMemory();
	};
}