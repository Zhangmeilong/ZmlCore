#pragma once
namespace zml 
{
	class LanuchAPI:
		public ILanuchAPI
	{
	public:
		explicit							LanuchAPI();
		virtual void						iRunFrame();
		virtual void						iAddFrameUpdateModule(IFrameUpdateModule* pIFrameUpdateModule);
		void								Initialize();
		void								Destroy();
		static LanuchAPI*					GetInstance();
	protected:
		static LanuchAPI*					sm_pLanuchAPI;
		APIProvider*						pAPIProvider;

	private:
		std::vector<IFrameUpdateModule*>	m_vecIFrameUpdateModules;
	};
}


