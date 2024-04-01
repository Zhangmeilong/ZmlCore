#pragma once
namespace zml 
{
	class LanuchAPI:
		public ILanuch
	{
	public:
		explicit				LanuchAPI();
		virtual void			iKeyEvent(const uint8_t& nKeyCode, const bool& bDown) override;
		void					Initialize();
		void					Destroy();
		static LanuchAPI*		GetInstance();
	protected:
		static LanuchAPI*		sm_pLanuchAPI;
		APIProvider*			pAPIProvider;
	};
}


