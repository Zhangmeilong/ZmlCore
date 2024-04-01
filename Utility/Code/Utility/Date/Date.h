#pragma once
#include "Interface.h"

namespace zml 
{
	class ZML_API Date
	{
	public:
		Date();
		Date(const Date& date);
		virtual					~Date();
		Date					operator=(const Date& other);
		static Date				currentDate();
		std::string				toString();
		std::string				toStringByDate(const std::string& split);
	public:
		int						year;
		int						month;
		int						day;
		int						hour;
		int						minute;
		int						secend;
	};
}