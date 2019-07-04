/*!
	@file	AbstractFactorySample.h
	@date	2019/06/29
	@author	番場 宥輝
	@brief	アブストラクトファクトリーのサンプルコード

	NOTE:	AbstractFactory.hの方に滅茶苦茶細かく書いています。
			ただ長くなりすぎて...
			見たい方はそちらも参考にetc.
			※途中までしか書いてないです。
*/
#pragma once
#include <iostream>

namespace GoF {
	namespace AbstractFactory {

#pragma region 説明

		//	最小

		/*!
			@class	AbstractProduct
			@brief	生成物の抽象クラス
		*/
		class AbstractProduct abstract
		{
		public:
			/*!
				@brief	コンストラクタ
			*/
			AbstractProduct() {}

			/*!
				@brief	デストラクタ
			*/
			~AbstractProduct() {}
		private:
		};

		/*!
			@class	CProduct
			@brief	抽象クラスを継承した具象クラス
		*/
		class CProduct
			: public AbstractProduct
		{
		public:
			/*!
				@brief	コンストラクタ
			*/
			CProduct() :AbstractProduct() {}

			/*!
				@brief	デストラクタ
			*/
			~CProduct() {}
		private:

		};
#pragma endregion

#pragma region サンプル

#pragma region インターフェイス・抽象クラス
		/*!
			@interface	ICharacter
			@brief		キャラクターのインターフェイス
		*/
		__interface ICharacter
		{
			/*!
				@fn		Move
				@brief	移動
			*/
			void Move();

			/*!
				@fn		Attack
				@brief	攻撃
			*/
			void Attack();

			/*!
				@fn		Damage
				@brief	ダメージ
			*/
			void Damage();
		};

		/*!
			@class	AbstractEnemy
			@brief	敵の抽象クラス
		*/
		class AbstractEnemy abstract
			: public ICharacter
		{
		public:
			/*!
				@brief	コンストラクタ
			*/
			AbstractEnemy() :m_ID(0), m_HP(10), m_ATK(1), m_DEF(1), m_SPD(1) {}

			/*!
				@brief	仮想デストラクタ
			*/
			virtual~AbstractEnemy() {};

		private:

		protected:
			/*!
				@var	m_ID
				@brief	敵キャラの持つID
			*/
			unsigned int m_ID;

			/*!
				@var	m_HP
				@brief	HP
			*/
			unsigned int m_HP;

			/*!
				@var	m_ATK
				@brief	攻撃力
			*/
			unsigned int m_ATK;

			/*!
				@var	m_DEF
				@brief	防御力
			*/
			unsigned int m_DEF;

			/*!
				@var	m_SPD
				@brief	速度
			*/
			unsigned int m_SPD;
		};


#pragma endregion

#pragma region 具象クラス

		/*!
			@class	CPlayer
			@brief	プレイヤーのクラス
		*/
		class CPlayer
			: public ICharacter
		{
		public:
			/*!
				@brief	デフォルトコンストラクタ
			*/
			CPlayer() = default;

			/*!
				@brief	デフォルトデストラクタ
			*/
			~CPlayer() = default;

			/*!
				@fn		Move
				@brief	移動
				@detail	インターフェイス実装
			*/
			void ICharacter::Move() {
				std::cout << "プレイヤーの移動";

			}

			/*!
				@fn		Attack
				@brief	攻撃
				@detail	インターフェイス実装
			*/
			void ICharacter::Attack() {
				std::cout << "プレイヤーの攻撃";

			}

			/*!
				@fn		Damage
				@brief	ダメージ
				@detail	インターフェイス実装
			*/
			void ICharacter::Damage() {
				std::cout << "プレイヤーへダメージ";

			}
		private:

		};

		/*!
			@class	CFriend
			@brief	仲間のクラス
		*/
		class CFriend
			: public ICharacter
		{
		public:
			/*!
				@brief	デフォルトコンストラクタ
			*/
			CFriend() = default;

			/*!
				@brief	デフォルトデストラクタ
			*/
			~CFriend() =default;

			/*!
				@fn		Move
				@brief	移動
				@detail	インターフェイス実装
			*/
			void ICharacter::Move() {
				std::cout << "仲間の移動";
			}

			/*!
				@fn		Attack
				@brief	攻撃
				@detail	インターフェイス実装
			*/
			void ICharacter::Attack() {
				std::cout << "仲間の攻撃";
			}

			/*!
				@fn		Damage
				@brief	ダメージ
				@detail	インターフェイス実装
			*/
			void ICharacter::Damage() {
				std::cout << "仲間へダメージ";
			}
		private:

		};

		/*!
			@class	CMobEnemy
			@brief	敵モブ
		*/
		class CMobEnemy
			: public AbstractEnemy
		{
		public:
			/*!
				@brief	コンストラクタ
				@detail	基底クラスのコンストラクタで初期化
			*/
			CMobEnemy() : AbstractEnemy() {}

			/*!
				@brief	デストラクタ
			*/
			~CMobEnemy() {};

			/*!
				@fn		Move
				@brief	移動
				@detail	インターフェイス実装
			*/
			void ICharacter::Move() {
				std::cout << "敵モブの移動";
			}

			/*!
				@fn		Attack
				@brief	攻撃
				@detail	インターフェイス実装
			*/
			void ICharacter::Attack() {
				std::cout << "敵モブの攻撃";
			}

			/*!
				@fn		Damage
				@brief	ダメージ
				@detail	インターフェイス実装
			*/
			void ICharacter::Damage() {
				std::cout << "敵モブへダメージ";
			}

		private:

		};

		/*!
			@class	CBossEnemy
			@brief	敵ボス
		*/
		class CBossEnemy
			: public AbstractEnemy
		{
		public:
			/*!
				@brief	コンストラクタ
				@detail	基底クラスのコンストラクタで初期化後、上書き
			*/
			CBossEnemy() : AbstractEnemy() {
				m_ID = 100, m_HP = 100, m_ATK = 100, m_DEF = 100, m_SPD = 10;
			}

			/*!
				@brief	デストラクタ
			*/
			~CBossEnemy() {};

			/*!
				@fn		Move
				@brief	移動
				@detail	インターフェイス実装
			*/
			void ICharacter::Move() {
				std::cout << "敵ボスの移動";
			}

			/*!
				@fn		Attack
				@brief	攻撃
				@detail	インターフェイス実装
			*/
			void ICharacter::Attack() {
				std::cout << "敵ボスの攻撃";
			}

			/*!
				@fn		Damage
				@brief	ダメージ
				@detail	インターフェイス実装
			*/
			void ICharacter::Damage() {
				std::cout << "敵ボスへダメージ";
			}

		private:

		};
#pragma endregion

#pragma endregion

	}
}