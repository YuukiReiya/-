/*!
	@file	AdapterSample.h
	@date	2019/06/16
	@author	番場 宥輝
	@brief	アダプターのサンプルコード

	NOTE:	実際のゲーム制作を仮定した状況でサンプルコードを作成する
			Targetに対してCAdapterにAdapteeとTargetを多重継承する
*/
#pragma once
#include <iostream>

namespace GoF {
	namespace Adapter {

#pragma region 説明

		/*!
			@class	CTarget
			@brief	対象のクラス
			@detail	機能の追加を考えているが、なんらかの事情で直接いじれないクラス
					ex)
						中身が"ブラックボックス","分業中で誰かが作業中"etc...

			NOTE:	中身は空にしときます。
		*/
		class CTarget
		{
		public:
			/*!
				@brief	デフォルトコンストラクタ
			*/
			CTarget() = default;

			/*!
				@brief	デフォルトデストラクタ
			*/
			~CTarget() = default;

			//	何らかの処理...

		private:

			//	何らかのメンバ変数

		};

		/*!
			@interface	IAdaptee
			@brief		追加処理群(Adaptee)
			@detail		追加したい機能の関数群を純粋仮想関数で定義

			NOTE:		追加機能を"Func1 ～ Func3"とする。
						※C++なら未定義でも出来るけど、C#は多重継承禁止だから分ける必要がある。
		*/
		__interface IAdaptee
		{
			//NOTE:	Interfaceで宣言した関数は全て"純粋仮想関数"と同じ扱い

			/*!
				@fn		Func1
				@brief	機能追加関数1
			*/
			void Func1();

			/*!
				@fn		Func2
				@brief	機能追加関数2
			*/
			void Func2();

			/*!
				@fn		Func3
				@brief	機能追加関数3
			*/
			void Func3();
		}; 

		/*!
			@class	CAdapter
			@brief	対象クラスに機能追加した拡張クラス
			
			NOTE:	"Adaptee"と"Target"の多重継承
		*/
		class CAdapter:
			public IAdaptee,private CTarget
		{
		public:
			/*!
				@brief	デフォルトコンストラクタ
			*/
			CAdapter() = default;
			/*!
				@brief	デフォルトデストラクタ
			*/
			~CAdapter() = default;

			/*!
				@fn		Func1
				@brief	機能追加関数1

				NOTE:	Interfaceならアクセス修飾子に依存しない!(public)
			*/
			void IAdaptee::Func1() {}

		protected:
			/*!
				@fn		Func2
				@brief	機能追加関数2

				NOTE:	Interfaceならアクセス修飾子に依存しない!(protected)
			*/
			void IAdaptee::Func2() {}

		private:
			/*!
				@fn		Func3
				@brief	機能追加関数3

				NOTE:	Interfaceならアクセス修飾子に依存しない!(private)
			*/
			void IAdaptee::Func3() {}
		};
#pragma endregion

#pragma region サンプル

		/*!
			@class	CPlayer
			@author	Aさん
			@brief	プレイヤークラス

			NOTE:	Aさんは"Input"関数で手が離せなく、アイテムをゲットする処理をBさんに投げた。
					※ちなみに本来の使い方とは違うので、この使い方はあまりお勧めできない。
					　アダプターで適合させる関数は仮想関数もしくはインターフェイスの必要がある。
		*/
		class CPlayer
		{
		public:
			/*!
				@brief	コンストラクタ
			*/
			CPlayer() :m_ItemCode(0) {};

			/*!
				@brief	デストラクタ
			*/
			~CPlayer() = default;

			/*!
				@fn		Input
				@brief	入力処理
				@detail	現在制作中

				NOTE:	サンプルなので空処理。
			*/
			void Input() {};

			/*!
				@fn		GetItemCode
				@brief	保持しているアイテムのID取得
				@note	"0" = 未所持
				@return	アイテムのID
			*/
			inline const int GetItemCode()const { return m_ItemCode; }

			/*!
				@fn			SetItemCode
				@brief		保持しているアイテムの登録
				@param[in]	アイテムのID
			*/
			inline const void SetItemCode(const int id) { m_ItemCode = id; }
		private:
			/*!
				@var	m_ItemCode
				@brief	プレイヤーが保持しているアイテムのID
			*/
			int m_ItemCode;
		};

		/*!
			@class	CItemCollector
			@author	Bさん
			@brief	アイテムを獲得するクラス

			NOTE:	実装はCAdapterがメイン(Adaptee)
		*/
		class CItemCollector
		{
		public:
			/*!
				@brief	コンストラクタ
			*/
			CItemCollector() = default;

			/*!
				@brief	デストラクタ
			*/
			~CItemCollector() = default;

			/*!
				@fn		GetItem
				@brief	アイテムの取得

				NOTE:	アダプターでラップするので仮想関数にしとく。
			*/
			virtual void GetItem()abstract;
		private:

		};

		/*!
			@class	CPlayerAdapter
			@author	Bさん
			@brief	BさんがAさんのいじっている"CPlayer"クラスに手を加えないようにアダプターでラッピング

		*/
		class CPlayerAdapter :public CItemCollector, private CPlayer
		{
		public:
			/*!
				@brief	コンストラクタ
			*/
			CPlayerAdapter() :CItemCollector(), CPlayer() {}

			/*!
				@brief	デストラクタ
			*/
			~CPlayerAdapter() = default;

			/*!
				@fn		GetItem
				@brief	アイテムの取得

				NOTE:	CItemCollectorのGetItemの中身
			*/
			void GetItem()override {
				//アイテムの取得処理
				const int c_DummyItem = 1;
				std::cout << "AdapterのアイテムID:" << GetItemCode() << std::endl;
				SetItemCode(c_DummyItem);
				std::cout << "AdapterのアイテムID:" << GetItemCode() << std::endl;
			}

		private:

		};
#pragma endregion
	}
}