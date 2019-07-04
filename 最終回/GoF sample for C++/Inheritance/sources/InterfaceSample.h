/*!
	@file	InterfaceSample.h
	@date	2019/06/15
	@author	番場 宥輝
	@brief	インターフェイスのサンプルコード
*/
#pragma once
#include <iostream>

namespace Inheritance {
	
#pragma region インターフェイス宣言
	namespace Interface {
		/*!
			@brief	キャラクターのインターフェイス

			NOTE:	インターフェイスはメンバ変数を持たせられないので注意!!
					多重継承を安全に出来るのがメリット！
					(C++よりC#のが効果的)
		*/
		__interface ICharacter
		{
			/*!
				@fn		Action
				@brief	アクションメソッド
			*/
			void Action();

			/*!
				@fn		Move
				@brief	移動メソッド
			*/
			void Move();

			/*!
				@fn		Damage
				@brief	ジャンプメソッド
			*/
			void Jump();
		};
	}
#pragma endregion

#pragma region 実体宣言
	namespace Entity {

		/*!
			@brief	プレイヤー
		*/
		class Player
			: public Interface::ICharacter
		{
		public:
			/*!
				@brief	コンストラクタ
			*/
			explicit Player() = default;

			/*!
				@brief	デストラクタ
			*/
			~Player() = default;

			/*!
				@fn		Action
				@brief	アクションメソッド
			*/
			inline void ICharacter::Action() {
				std::cout << "プレイヤーのアクション";
			}

			/*!
				@fn		Move
				@brief	移動メソッド
			*/
			inline void ICharacter::Move() {
				std::cout << "プレイヤーの移動";
			}

			/*!
				@fn		Damage
				@brief	ジャンプメソッド
			*/
			inline void ICharacter::Jump() {
				std::cout << "プレイヤーのジャンプ";
			}

		private:
		};

		/*!
			@brief	エネミー
		*/
		class Enemy
			: public Interface::ICharacter
		{
		public:
			/*!
				@brief	コンストラクタ
			*/
			Enemy() = default;

			/*!
				@brief	デストラクタ
			*/
			~Enemy() = default;


			/*!
				@fn		Action
				@brief	アクションメソッド
			*/
			inline void ICharacter::Action() {
				std::cout << "エネミーのアクション";
			}

			/*!
				@fn		Move
				@brief	移動メソッド
			*/
			inline void ICharacter::Move() {
				std::cout << "エネミーの移動";
			}

			/*!
				@fn		Damage
				@brief	ジャンプメソッド
			*/
			inline void ICharacter::Jump() {
				std::cout << "エネミーのジャンプ";
			}
		private:
		};
	}
#pragma endregion

}