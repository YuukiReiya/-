/*!
	@file	CSample2.h
	@date	2019/06/16
	@author	番場 宥輝
	@brief	Singletonのサンプルコード2
	@detail	シングルトンでソースを跨いでも値が共有されていることの証明
*/
#pragma once
#include "SingletonSample.h"
namespace GoF {
	namespace Singleton {
		/*!
			@class	CSample1
			@brief	デストラクタでシングルトンのカウンタを加算させる。
		*/
		class CSample2
		{
		public:
			/*!
				@brief	コンストラクタ
			*/
			CSample2() {}

			/*!
				@brief	デストラクタ
				@detail	シングルトンのカウンタを加算
			*/
			~CSample2() { CSingleton::GetInstance().AddCount(); }

		private:

		};

	}
}