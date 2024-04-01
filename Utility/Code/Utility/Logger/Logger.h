#pragma once
#include "Interface.h"

namespace zml 
{
	class ZML_API Logger
	{
	public:
		Logger();
		~Logger();
		void											Create(const int& nMaxFileCount, const int& nMaxFileSize);
		void											Info(const std::string& strMsg);
		void											Debug(const std::string& strMsg);
		void											Warn(const std::string& strMsg);
		void											Error(const std::string& strMsg);
		static Logger*									GetInstance();
	protected:
		enum class LogType_e
		{
			LOG_INFO = 0,
			LOG_DEBUG,
			LOG_WARN,
			LOG_ERROR,
		};

	private:
		void											writerLogger(LogType_e logType, const std::string& strMsg);

	private:
		bool											m_bCreated;
		long long										lMaxFileSize;
		std::map<int, std::shared_ptr<spdlog::logger>>	m_mapLoggers;
		static Logger*									sm_pLogger;
	};
}