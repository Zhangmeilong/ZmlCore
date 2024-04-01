#include "Device.h"

using namespace zml;

Device::Device()
{

}

Device::~Device()
{

}

void Device::GetComputerInfo(ComputerInfo& info)
{
	info.nScreenWidth = GetSystemMetrics(SM_CXSCREEN);
	info.nScreenHeight = GetSystemMetrics(SM_CYSCREEN);
	HWND hd = GetDesktopWindow();
	int zoom = GetDpiForWindow(hd);
	info.dScreenDPI = 0;
	switch (zoom) {
	case 96:
		info.dScreenDPI = 1;
		break;
	case 120:
		info.dScreenDPI = 1.25;
		break;
	case 144:
		info.dScreenDPI = 1.5;
		break;
	case 192:
		info.dScreenDPI = 2;
		break;
	default:
		break;
	}
	TCHAR name[1024];
	DWORD buffCount = 1024;
	if (GetComputerName(name, &buffCount))
	{
		std::wstring wstrName(name);
		info.strComputerName = std::string(wstrName.begin(), wstrName.end());
	}
	if (GetUserName(name, &buffCount))
	{
		std::wstring wstrName(name);
		info.strUserAccount = std::string(wstrName.begin(), wstrName.end());
	}
	MEMORYSTATUSEX status;
	status.dwLength = sizeof(status);
	GlobalMemoryStatusEx(&status);
	info.dTotalMemory = status.ullTotalPhys / 1024 / 1024;
	info.dFreeMemory = status.ullAvailPhys / 1024 / 1024;
	info.dUsedMemoryPer = status.dwMemoryLoad;
}

double Device::GetCurProcessMemory()
{
	PROCESS_MEMORY_COUNTERS pmc;
	if (GetProcessMemoryInfo(GetCurrentProcess(), &pmc, sizeof(pmc)))
	{
		return (double)pmc.WorkingSetSize / 1024.0 / 1024.0;
	}
	return 0.0;
}
