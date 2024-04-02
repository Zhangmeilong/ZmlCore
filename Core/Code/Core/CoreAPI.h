#pragma once
namespace zml
{
	class ZML_API CoreAPI :
		public ICore
	{
	public:
		explicit				CoreAPI();
		virtual void			iKeyEvent(const uint8_t& nKeyCode, const bool& bDown) override;
		void					Initialize(SystemAPI* pSystemAPI);
		void					Destroy();
		static CoreAPI*			GetInstance();

	protected:
		static CoreAPI*			sm_pCoreAPI;
		APIProvider*			m_pAPIProvider;
	};
}