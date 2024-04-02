#pragma once
namespace zml 
{
	class LanuchAPI:
		public ILanuchAPI
	{
	public:
		explicit				LanuchAPI();
		void					Initialize();
		void					Destroy();
		static LanuchAPI*		GetInstance();
	protected:
		static LanuchAPI*		sm_pLanuchAPI;
		APIProvider*			pAPIProvider;
	};
}


