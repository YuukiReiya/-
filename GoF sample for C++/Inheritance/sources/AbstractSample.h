/*!
	@file	AbstractSample.h
	@date	2019/06/15
	@author	番場 宥輝
	@brief	抽象クラスのサンプルコード
*/
#pragma once
#include <string>

namespace Inheritance{

#pragma region 抽象宣言
	namespace Abstract {
		/*!
			@brief	動物の抽象クラス

			NOTE:	abstractキーワードを使うとインスタンス化が出来なくなります。
					(抽象クラスとはインスタンス化を制限されたクラスのこと)
		*/
		class AbstractAnimals abstract
		{
		public:
			/*!
				@brief	コンストラクタ
				@detail	abstract宣言なので継承元のインスタンス化はできない
			*/
			AbstractAnimals() = default;
			virtual ~AbstractAnimals() = default;

			/*!
				@fn		Update
				@brief	更新処理
				@detail	抽象メソッド

				NOTE:	今回はダミーなので継承先も空処理
			*/
			virtual void Update()abstract;

			/*!
				@fn		DisplayName
				@brief	メンバの名前を表示
			*/
			inline void DisplayName(){
				std::cout << m_Name << std::endl;
			}
		protected:
			/*!
				@var	m_Name
				@brief	名前
			*/
			std::string m_Name;
		};
	}
#pragma endregion

#pragma region 実体宣言
	namespace Entity {
		/*!
			@brief	犬
		*/
		class Dog 
			: public Abstract::AbstractAnimals
		{
		public:
			/*!
				@brief	コンストラクタ
			*/
			explicit Dog() { m_Name = "犬"; };

			/*!
				@brief	デストラクタ
			*/
			~Dog()override = default;

			/*!
				@fn		Update
				@brief	更新処理
				@detail	継承元のオーバーライド

				NOTE:	今回はサンプルコードなので空処理
			*/
			void Update()override {}
		};

		/*!
			@brief	猫
		*/
		class Cat
			: public Abstract::AbstractAnimals
		{
		public:
			/*!
				@brief	コンストラクタ
			*/
			explicit Cat() { m_Name = "猫"; };

			/*!
				@brief	デストラクタ
			*/
			~Cat()override = default;

			/*!
				@fn		Update
				@brief	更新処理
				@detail	継承元のオーバーライド

				NOTE:	今回はサンプルコードなので空処理
			*/
			void Update()override {}

		};
	}
#pragma endregion
}