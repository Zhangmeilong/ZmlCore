#pragma once
#include "Interface.h"

namespace zml 
{
	class ZML_API Tool
	{
	public:
		Tool() = delete;
		//����ȥ���ַ��������еĿո�
		static std::string					TrimString(const std::string& str);
		//�滻�ַ����е��ض��ַ�
		static void							ReplaceAll(const std::string& srcStr, const std::string& oldStr, const std::string& newStr, std::string& strResult);
		//utf-8 ת ascii
		static void							Utf8Ascii(std::string& srcStr, std::string& dstStr);
		//ascii ת utf-8
		static void							AsciiUtf8(std::string& srcStr, std::string& dstStr);
		//base64����
		static std::string					Base64EnCode(const std::string& strBase);
		//base64����
		static std::string					Base64DeCode(const std::string& strBase);
		//�����ļ���
		static void							CreateDir(const std::string& path);
		//��ȡ�ļ���С
		static size_t						GetFileSize(const std::string& strFilePath);
		//��ȡ�����·��
		static std::string					GetApplicationPath();
		//��ȡ���������
		static std::string					GetApplicationName();
		//ȡ�����
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


