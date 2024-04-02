#pragma once
namespace zml
{
	class ZML_API CoreAPI :
		public ICoreAPI
	{
	public:
		explicit				CoreAPI();
		virtual void			iKeyEvent(const int& nKeyCode, const bool& bDown) override;
		virtual void			iFrameUpdate() override;
		void					Initialize(SystemAPI* pSystemAPI);
		void					Destroy();
		static CoreAPI*			GetInstance();

	protected:
		static CoreAPI*			sm_pCoreAPI;
		APIProvider*			m_pAPIProvider;
	};
}