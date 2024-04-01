#include "Logger.h"

using namespace zml;

Logger::Logger()
{
	lMaxFileSize = 1 * 1024 * 1024;
	m_bCreated = false;
}

Logger::~Logger()
{

}

void Logger::Create(const int& nMaxFileCount, const int& nMaxFileSize)
{
	char slnPath[_MAX_PATH] = { 0 };
	char* pChar = _getcwd(slnPath, _MAX_PATH);

	char exePath[_MAX_PATH] = { 0 };
	wchar_t exeFullPath[_MAX_PATH] = { 0 };
	GetModuleFileName(NULL, exeFullPath, _MAX_PATH);

	size_t convertedChar = 0;
	wcstombs_s(&convertedChar, exePath, wcslen(exeFullPath) + 1, exeFullPath, wcslen(exeFullPath) + 1);
	std::wstring wstrExePath(exeFullPath);
	std::string strExePath(exePath);
	std::string strExeLogPath = strExePath.substr(0, strExePath.find_last_of("."));
	std::string strExeName = strExePath.substr(strExePath.find_last_of("\\") + 1, strExePath.find_last_of(".") - strExePath.find_last_of("\\") - 1);
	std::shared_ptr<spdlog::logger> logger_info = spdlog::daily_logger_mt("info", strExeLogPath + "/info/info.log");
	std::shared_ptr<spdlog::logger> logger_debug = spdlog::daily_logger_mt("debug", strExeLogPath + "/debug/debug.log");
	std::shared_ptr<spdlog::logger> logger_warn = spdlog::daily_logger_mt("warn", strExeLogPath + "/warn/warn.log");
	std::shared_ptr<spdlog::logger> logger_error = spdlog::daily_logger_mt("error", strExeLogPath + "/error/error.log");
	logger_info->set_level(spdlog::level::level_enum::info);
	logger_debug->set_level(spdlog::level::level_enum::debug);
	logger_warn->set_level(spdlog::level::level_enum::warn);
	logger_error->set_level(spdlog::level::level_enum::err);
	m_mapLoggers[(int)LogType_e::LOG_INFO] = logger_info;
	m_mapLoggers[(int)LogType_e::LOG_DEBUG] = logger_debug;
	m_mapLoggers[(int)LogType_e::LOG_WARN] = logger_warn;
	m_mapLoggers[(int)LogType_e::LOG_ERROR] = logger_error;
	m_bCreated = true;
}

void Logger::Info(const std::string& strMsg)
{
	writerLogger(LogType_e::LOG_INFO, strMsg);
}

void Logger::Debug(const std::string& strMsg)
{
	writerLogger(LogType_e::LOG_DEBUG, strMsg);
}

void Logger::Warn(const std::string& strMsg)
{
	writerLogger(LogType_e::LOG_WARN, strMsg);
}

void Logger::Error(const std::string& strMsg)
{
	writerLogger(LogType_e::LOG_ERROR, strMsg);
}

void Logger::writerLogger(LogType_e logType, const std::string& strMsg)
{
	if (!m_bCreated)
	{
		return;
	}
	switch (logType)
	{
	case Logger::LogType_e::LOG_INFO:
		m_mapLoggers[(int)LogType_e::LOG_INFO]->info(strMsg);
		m_mapLoggers[(int)LogType_e::LOG_INFO]->flush();
		break;
	case Logger::LogType_e::LOG_DEBUG:
		m_mapLoggers[(int)LogType_e::LOG_DEBUG]->debug(strMsg);
		m_mapLoggers[(int)LogType_e::LOG_DEBUG]->flush();
		break;
	case Logger::LogType_e::LOG_WARN:
		m_mapLoggers[(int)LogType_e::LOG_WARN]->warn(strMsg);
		m_mapLoggers[(int)LogType_e::LOG_WARN]->flush();
		break;
	case Logger::LogType_e::LOG_ERROR:
		m_mapLoggers[(int)LogType_e::LOG_ERROR]->error(strMsg);
		m_mapLoggers[(int)LogType_e::LOG_ERROR]->flush();
		break;
	default:
		break;
	}
}

Logger* Logger::GetInstance()
{
	if (sm_pLogger == nullptr) 
	{
		sm_pLogger = new Logger();
		sm_pLogger->Create(10, 4096);
	}
	return sm_pLogger;
}

Logger* Logger::sm_pLogger = nullptr;
