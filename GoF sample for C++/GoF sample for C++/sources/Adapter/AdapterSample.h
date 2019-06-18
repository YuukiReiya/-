/*!
	@file	AdapterSample.h
	@date	2019/06/16
	@author	番場 宥輝
	@brief	アダプターのサンプルコード

	NOTE:	実際のゲーム制作を仮定した状況でサンプルコードを作成する
			Targetに対してAdapterにAdapteeとTargetを多重継承する
*/
#pragma once
#include <iostream>

namespace GoF {
	namespace Adapter {

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

			NOTE:	実装はAdapterがメイン(Adaptee)
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
			@class	CAdapter
			@author	Bさん
			@brief	BさんがAさんのいじっている"CPlayer"クラスに手を加えないようにアダプターでラッピング

		*/
		class CAdapter :public CItemCollector, private CPlayer
		{
		public:
			/*!
				@brief	コンストラクタ
			*/
			CAdapter() :CItemCollector(), CPlayer() {}

			/*!
				@brief	デストラクタ
			*/
			~CAdapter() = default;

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

	}
}