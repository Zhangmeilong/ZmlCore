#pragma once
#include "Interface.h"

namespace zml 
{
	class ZML_API Tool
	{
	public:
		Tool() = delete;
		//用于去掉字符串中所有的空格
		static std::string					TrimString(const std::string& str);
		//替换字符串中的特定字符
		static void							ReplaceAll(const std::string& srcStr, const std::string& oldStr, const std::string& newStr, std::string& strResult);
		//utf-8 转 ascii
		static void							Utf8Ascii(std::string& srcStr, std::string& dstStr);
		//ascii 转 utf-8
		static void							AsciiUtf8(std::string& srcStr, std::string& dstStr);
		//base64编码
		static std::string					Base64EnCode(const std::string& strBase);
		//base64解码
		static std::string					Base64DeCode(const std::string& strBase);
		//创建文件夹
		static void							CreateDir(const std::string& path);
		//获取文件大小
		static size_t						GetFileSize(const std::string& strFilePath);
		//获取程序的路径
		static std::string					GetApplicationPath();
		//获取程序的名字
		static std::string					GetApplicationName();
		//取随机数
		static double						Random(double dStart, double dEnd);
	};

	class ZML_API ThreadPool
	{
	public:
		typedef std::function<void()> Task;
		ThreadPool();
		ThreadPool(int nSize);
		~ThreadPool();

	public:
		void								Start();
		void								Stop();
		template<typename F, typename ...Args>
		void								AddTask(F&& f, Args&&...args)
		{
			std::function<decltype(f(args...))()> func = std::bind(std::forward<F>(f), std::forward<Args>(args)...);
			auto task_ptr = std::make_shared<std::packaged_task<decltype(f(args...))()>>(func);
			std::function<void()> warpper = [task_ptr]()
			{
				(*task_ptr)();
			};
			addTask(warpper);
		}
	private:
		std::vector<std::thread*> m_threads;
		std::queue<Task> m_queTasks;
		std::mutex m_mutex;
		std::condition_variable m_conditional_lock;
		bool m_bStarted;
		int  m_nThreadSize;
	private:
		ThreadPool(const ThreadPool&) = delete;
		const ThreadPool& operator=(const ThreadPool&) = delete;
		void threadLoop();
		Task take();
		void addTask(const Task&);
	};
}


