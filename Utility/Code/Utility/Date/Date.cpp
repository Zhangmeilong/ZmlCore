#include "Date.h"

using namespace zml;

Date::Date()
{
	this->year = 1900;
	this->month = 1;
	this->day = 1;
	this->hour = 0;
	this->minute = 0;
	this->secend = 0;
}

Date::Date(const Date& dateTime)
{
	this->year = dateTime.year;
	this->month = dateTime.month;
	this->day = dateTime.day;
	this->hour = dateTime.hour;
	this->minute = dateTime.minute;
	this->secend = dateTime.secend;
}

Date::~Date()
{

}

Date Date::currentDate()
{
	//Ê±¼ä´Á
	//auto start = std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();
	Date date;
	auto now = std::chrono::system_clock::now();
	std::time_t _time = std::chrono::system_clock::to_time_t(now);
	struct tm ptrTime;
	localtime_s(&ptrTime, &_time);
	date.year = ptrTime.tm_year + 1900;
	date.month = ptrTime.tm_mon;
	date.day = ptrTime.tm_mday;
	date.hour = ptrTime.tm_hour;
	date.minute = ptrTime.tm_min;
	date.secend = ptrTime.tm_sec;
	return date;
}

std::string Date::toString()
{
	std::string str = std::to_string(this->year) + "-" + std::to_string(this->month) + "-" + std::to_string(this->day) + "  " +
		std::to_string(this->hour) + ":" + std::to_string(this->minute) + ":" + std::to_string(this->secend);
	return str;
}

std::string Date::toStringByDate(const std::string& split)
{
	std::string str = std::to_string(this->year) + split + std::to_string(this->month) + split + std::to_string(this->day);
	return str;
}

Date Date::operator=(const Date& other)
{
	Date date;
	date.year = other.year;
	date.month = other.month;
	date.day = other.day;
	date.hour = other.hour;
	date.minute = other.minute;
	date.secend = other.secend;
	return date;
}
