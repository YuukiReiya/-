/*!
	@file	CSample1.h
	@date	2019/06/16
	@author	番場 宥輝
	@brief	Singletonのサンプルコード1
	@detail	シングルトンでソースを跨いでも値が共有されていることの証明
*/
#pragma once
#include "SingletonSample.h"
namespace GoF {
	namespace Singleton {
		/*!
			@class	CSample1
			@brief	コンストラクタでシングルトンのカウンタを加算させる。
		*/
		class CSample1
		{
		public:
			/*!
				@brief	コンストラクタ
				@detail	シングルトンのカウンタを加算
			*/
			CSample1() { CSingleton::GetInstance().AddCount(); };

			/*!
				@brief	デストラクタ
			*/
			~CSample1() {};

		private:

		};

	}
}