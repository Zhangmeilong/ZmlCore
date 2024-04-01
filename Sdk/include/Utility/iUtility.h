#pragma once
#pragma warning(disable:4996)
#include <iostream>
#include <set>
#include <vector>
#include <map>
#include <direct.h>
#include <fstream>
#include <io.h>
#include <chrono>
#include <ctime>
#include <string_view>
#include <source_location>
#include <codecvt>
#include <string>
#include <memory>
#include <windows.h>
#include <Psapi.h>
#include <thread>
#include <utility>
#include <queue>
#include <functional>
#include <mutex>
#include <future>
#include <assert.h>
#include <random>

#ifndef Q_MOC_RUN
#include <boost/uuid/uuid.hpp>
#include <boost/uuid/uuid_io.hpp>
#include <boost/uuid/uuid_generators.hpp>
#endif

#include <spdlog/spdlog.h>
#include <spdlog/logger.h>
#include <spdlog/sinks/basic_file_sink.h>
#include <spdlog/sinks/daily_file_sink.h>
#include <spdlog/sinks/rotating_file_sink.h>

#include <rapidxml/rapidxml.hpp>
#include <rapidxml/rapidxml_print.hpp>
#include <rapidxml/rapidxml_utils.hpp>

#include <json/json.h>

#ifdef NO_QT
#ifdef _DEBUG
#pragma comment(lib,"spdlog/Debug/spdlogd.lib")
//#pragma comment(lib,"opencv/Debug/opencv_world480d.lib")
//#pragma comment(lib,"zxing/Debug/ZXing_d.lib")
#pragma comment(lib,"json/Debug/jsoncpp.lib")
#else
#pragma comment(lib,"spdlog/Release/spdlog.lib")
//#pragma comment(lib,"opencv/Release/opencv_world480.lib")
//#pragma comment(lib,"zxing/Release/ZXing.lib")
#pragma comment(lib,"json/Release/jsoncpp.lib")
#endif
#endif

