#include "Tool.h"

using namespace zml;

#define GBK_CODE ".936"
using WCHAR_GBK = std::codecvt_byname<wchar_t, char, mbstate_t>;
using WCHAR_UTF8 = std::codecvt_utf8<wchar_t>;

std::string Tool::TrimString(const std::string& str)
{
	std::string strOperator = str;
	size_t pos = 1;
	while (pos >= 0)
	{
		pos = strOperator.find(' ');
		if (pos == -1)
		{
			break;
		}
		strOperator = strOperator.erase(pos, 1);
	}
	return strOperator;
}

void Tool::ReplaceAll(const std::string& srcStr, const std::string& oldStr, const std::string& newStr, std::string& strResult)
{
	std::string strTemp = srcStr;
	while (true)
	{
		std::string::size_type pos(0);
		if ((pos = strTemp.find(oldStr)) != std::string::npos)
		{
			strTemp.replace(pos, oldStr.length(), newStr);
		}
		else
		{
			break;
		}
	}
	strResult = strTemp;
}

void Tool::Utf8Ascii(std::string& srcStr, std::string& dstStr)
{
	std::wstring_convert<WCHAR_GBK>  cvtGBK(new WCHAR_GBK(GBK_CODE));
	std::wstring_convert<WCHAR_UTF8> cvtUTF8;
	std::wstring ustr = cvtUTF8.from_bytes(srcStr);
	std::string str = cvtGBK.to_bytes(ustr);
	dstStr = str;
}

void Tool::AsciiUtf8(std::string& srcStr, std::string& dstStr)
{
	std::wstring_convert<WCHAR_GBK>  cvtGBK(new WCHAR_GBK(GBK_CODE));
	std::wstring_convert<WCHAR_UTF8> cvtUTF8;
	std::wstring str = cvtGBK.from_bytes(srcStr);
	std::string ustr = cvtUTF8.to_bytes(str);
	dstStr = ustr;
}

std::string Tool::Base64EnCode(const std::string& strBase)
{
	//编码表
	const char EncodeTable[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/";
	//返回值
	std::string strEncode;
	unsigned char Tmp[4] = { 0 };
	int LineLength = 0;
	int DataByte = strBase.length();
	const char* Data = strBase.c_str();
	for (int i = 0; i < (int)(DataByte / 3); i++)
	{
		Tmp[1] = *Data++;
		Tmp[2] = *Data++;
		Tmp[3] = *Data++;
		strEncode += EncodeTable[Tmp[1] >> 2];
		strEncode += EncodeTable[((Tmp[1] << 4) | (Tmp[2] >> 4)) & 0x3F];
		strEncode += EncodeTable[((Tmp[2] << 2) | (Tmp[3] >> 6)) & 0x3F];
		strEncode += EncodeTable[Tmp[3] & 0x3F];
		if (LineLength += 4, LineLength == 76) { strEncode += "\r\n"; LineLength = 0; }
	}
	//对剩余数据进行编码
	int Mod = DataByte % 3;
	if (Mod == 1)
	{
		Tmp[1] = *Data++;
		strEncode += EncodeTable[(Tmp[1] & 0xFC) >> 2];
		strEncode += EncodeTable[((Tmp[1] & 0x03) << 4)];
		strEncode += "==";
	}
	else if (Mod == 2)
	{
		Tmp[1] = *Data++;
		Tmp[2] = *Data++;
		strEncode += EncodeTable[(Tmp[1] & 0xFC) >> 2];
		strEncode += EncodeTable[((Tmp[1] & 0x03) << 4) | ((Tmp[2] & 0xF0) >> 4)];
		strEncode += EncodeTable[((Tmp[2] & 0x0F) << 2)];
		strEncode += "=";
	}
	return strEncode;
}

std::string Tool::Base64DeCode(const std::string& strBase)
{
	int DataByte = strBase.length();
	const char* Data = strBase.c_str();
	//解码表
	const char DecodeTable[] =
	{
		0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
		0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
		62, // '+'
		0, 0, 0,
		63, // '/'
		52, 53, 54, 55, 56, 57, 58, 59, 60, 61, // '0'-'9'
		0, 0, 0, 0, 0, 0, 0,
		0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12,
		13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, // 'A'-'Z'
		0, 0, 0, 0, 0, 0,
		26, 27, 28, 29, 30, 31, 32, 33, 34, 35, 36, 37, 38,
		39, 40, 41, 42, 43, 44, 45, 46, 47, 48, 49, 50, 51, // 'a'-'z'
	};
	//返回值
	std::string strDecode;
	int nValue;
	int i = 0;
	while (i < DataByte)
	{
		if (*Data != '\r' && *Data != '\n')
		{
			nValue = DecodeTable[*Data++] << 18;
			nValue += DecodeTable[*Data++] << 12;
			strDecode += (nValue & 0x00FF0000) >> 16;
			if (*Data != '=')
			{
				nValue += DecodeTable[*Data++] << 6;
				strDecode += (nValue & 0x0000FF00) >> 8;
				if (*Data != '=')
				{
					nValue += DecodeTable[*Data++];
					strDecode += nValue & 0x000000FF;
				}
			}
			i += 4;
		}
		else
		{
			Data++;
			i++;
		}
	}
	return strDecode;
}

void Tool::CreateDir(const std::string& path)
{
	int i, len;
	char str[512];

	strncpy_s(str, path.c_str(), 512);
	len = strlen(str);
	for (i = 0; i < len; i++)
	{
		if (str[i] == '/')
		{
			str[i] = '\0';
			if (_access(str, 0) != 0)
			{
				_mkdir(str);
			}
			str[i] = '/';
		}
	}
	if (len > 0 && _access(str, 0) != 0)
	{
		_mkdir(str);
	}
}

size_t Tool::GetFileSize(const std::string& strFilePath)
{
	std::ifstream in(strFilePath);
	in.seekg(0, std::ios::end);
	size_t size = in.tellg();
	in.close();
	return size;
}

std::string Tool::GetApplicationPath()
{
	char exePath[MAX_PATH + 1] = { 0 };
	GetModuleFileNameA(NULL, exePath, MAX_PATH);
	std::string strExePath(exePath);
	std::string strResult;
	ReplaceAll(strExePath, "\\", "/", strResult);
	strResult = strResult.substr(0, strResult.find_last_of("/"));
	return strResult;
}

std::string Tool::GetApplicationName()
{
	char exePath[MAX_PATH + 1] = { 0 };
	GetModuleFileNameA(NULL, exePath, MAX_PATH);
	std::string strExePath(exePath);
	std::string strResult;
	ReplaceAll(strExePath, "\\", "/", strResult);
	strResult = strResult.substr(strResult.find_last_of("/") + 1, strResult.find_last_of(".") - strResult.find_last_of("/") - 1);
	return strResult;
}

double Tool::Random(double dStart, double dEnd)
{
	std::random_device rd;
	std::default_random_engine random(rd());
	std::uniform_real_distribution<double> dis(dStart, dEnd);
	double dResult = dis(random);
	return dResult;
}

ThreadPool::ThreadPool(int nSize)
	:m_mutex()
	, m_bStarted(false)
	, m_nThreadSize(nSize)
{
}

ThreadPool::ThreadPool()
	:m_mutex()
	, m_bStarted(false)
	, m_nThreadSize(4)
{
}

ThreadPool::~ThreadPool()
{
	if (m_bStarted)
	{
		Stop();
	}
}

void ThreadPool::Start()
{
	assert(m_threads.empty());
	m_bStarted = true;
	m_threads.reserve(m_nThreadSize);
	for (int i = 0; i < m_nThreadSize; ++i)
	{
		m_threads.push_back(new std::thread(std::bind(&ThreadPool::threadLoop, this)));
	}
}

void ThreadPool::Stop()
{
	std::unique_lock<std::mutex> lock(m_mutex);
	m_bStarted = false;
	m_conditional_lock.notify_all();
	for (auto it : m_threads)
	{
		if (it->joinable())
		{
			it->join();
		}
		DEL_PTR(it);
	}
	m_threads.clear();
}

void ThreadPool::addTask(const Task& task)
{
	std::unique_lock<std::mutex> lock(m_mutex);
	m_queTasks.push(task);
	m_conditional_lock.notify_all();
}

void ThreadPool::threadLoop()
{
	while (m_bStarted)
	{
		Task task = take();
		if (task)
		{
			task();
		}
	}
}

ThreadPool::Task ThreadPool::take()
{
	std::unique_lock<std::mutex> lock(m_mutex);
	while (m_queTasks.empty() && m_bStarted)
	{
		m_conditional_lock.wait(lock);
	}
	Task task;
	int nSize = m_queTasks.size();
	if (!m_queTasks.empty() && m_bStarted)
	{
		task = m_queTasks.front();
		m_queTasks.pop();
		assert(nSize - 1 == m_queTasks.size());
	}
	return task;
}