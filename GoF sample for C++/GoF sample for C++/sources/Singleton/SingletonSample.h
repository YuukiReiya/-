/*!
	@file	SingletonSample.h
	@date	2019/06/16
	@author	番場 宥輝
	@brief	シングルトンのサンプルコード
*/
#pragma once
#include <iostream>

namespace GoF {
	namespace Singleton {
		/*!
			@class	CSingleton
			@brief	シングルトンのサンプルクラス
		*/
		class CSingleton
		{
		public:
			/*!
				@fn		GetInstance
				@brief	インスタンスのゲッター
				@detail	静的インスタンスを介したアクセス

				@sample	メソッドの呼び出し↓
						CSingleton::GetInstance().GetAdd();
			*/
			static inline CSingleton&GetInstance() {
				static CSingleton instance;
				return instance;
			}

#pragma region 動的メソッド

			/*!
				@fn		AddCount
				@brief	カウントの加算
			*/
			void AddCount() { m_Count++; }

			/*!
				@fn		GetCount
				@brief	カウントの取得
			*/
			const int GetCount() { return m_Count; }
#pragma endregion

#pragma region 静的メソッド

			/*!
				@fn		DisplayCount
				@brief	カウンタの表示

				@sample	メソッド呼び出し↓
						CSingleton::DisplayCount();
						これでOK。

						※
						CSingleton::GetInstance().DisplayCount();
						でも動作する。
			*/
			static void DisplayCount() { std::cout << GetInstance().m_Count; }
#pragma endregion

		private:
			//NOTE:	コンストラクタをprivateにすることでインスタンス生成を制限することが出来る。

			/*!
				@brief	コンストラクタ
			*/
			CSingleton() = default;

			/*!
				@brief	デストラクタ
			*/
			~CSingleton() = default;

			/*!
				@value	m_Count
				@brief	カウント
			*/
			int m_Count = 0;

			static int m_DummyBuffer;
		};

	}
}