/*!
	@file	TemplateMethodSample.h
	@date	2019/06/30
	@author	番場 宥輝
	@brief	テンプレートメソッドのサンプルコード
*/
#pragma once
#include <iostream>
#include <vector>
namespace GoF {
	namespace TemplateMethod {

#pragma region 関数テンプレート	

		/*!
			@fn			mul
			@brief		乗算
			@detail		テンプレートメソッド
			@param[in]	掛ける数
			@param[in]	掛けられる数
			@return		乗算結果

			NOTE:		自作クラスや構造体も出来る。(動作未定義に注意。)
						下記メソッドでは異なる型を引数に渡した場合、動作未定義。
		*/
		template<typename T>T mul(T a, T b) { return a * b; }

		/*!
			@fn			mul
			@brief		乗算
			@detail		テンプレートメソッド オーバーロード
			@param[in]	掛ける数
			@param[in]	掛けられる数
			@return		掛ける数と同じ型の乗算結果

			NOTE:		引数に異なる型を渡す場合は、このように明示的に2種類の型を渡した方が安全。
						※ダックタイピングと桁落ち等は自己責任で。
		*/
		template<typename T1, typename T2>T1 mul(T1 a, T2 b) { return a * b; }

		/*!
			@fn		FuncSample
			@brief	関数テンプレートのサンプルコード
		*/
		void FuncSample()
		{
			std::cout << "int:" << mul<int>(2, 3) << std::endl;	//	int型
			std::cout << "float:" << mul<float>(1.5f, 3.0f) << std::endl;//	float型


			//NOTE:	下記呼び出しでわかる通り、引数は型推論される。
			std::cout << "桁落ち計算:" << mul<int>(1.5f, 3) << std::endl;//	1.5f→1 => 1 * 3 = 3

			//引数型2種の呼び出し
			std::cout << "引数型2種の呼び出し:" << mul<int, float>(1, 2.5f) << std::endl;
		}
#pragma endregion

#pragma region クラステンプレート
		/*!
			@class	CTemplate
			@brief	テンプレートクラス
		*/
		template <typename C>class CTemplate{
		public:
			/*!
				@fn		Func
				@brief	テンプレートクラスに実装した関数

				NOTE:	テンプレートクラスを利用した継承を使えば継承先で呼び出せる。
			*/
			void Func() { std::cout << "テンプレートクラスに実装されている関数" << std::endl; }

			/*!
				@fn			MemberFunc
				@brief		引数で受け取った値の出力
				@detail		メンバ関数のテンプレート化
				@param[in]	出力する値

				NOTE:		もちろん戻り値も指定できます。
			*/
			template<typename T>
			void MemberFunc(T value) { std::cout << "受け取った値:" << value << std::endl; }

			/*!
				@fn		AbstractFunc
				@brief	テンプレートクラスに実装した純粋関数

				NOTE:	継承先に純粋仮想関数を投げることもできる。
						※継承先で定義作るのが怠いし、
						テンプレートクラスのインスタンス化が出来なくなるので今回はしない。
			*/
			//virtual void AbstractFunc()abstract;

			/*!
				@fn			SetValue
				@brief		テンプレート型のメンバへのセッター
				@param[in]	セットする値
			*/
			inline void SetValue(C value) { m_Value = value; }

			/*!
				@fn		GetValue
				@brief	テンプレート型のメンバのゲッター
				@return	メンバ
			*/
			inline C GetValue() { return m_Value; }
		private:
			/*!
				@var	m_Value
				@brief	テンプレート型のメンバ変数

				NOTE:	回りくどいけど、テンプレート型をメンバにすることもできます。
						今回は説明のために、関数でやっているけど、一般的にはコンストラクタ
						実装が普通。
			*/
			C m_Value;

		};

		//==================================================================
		//	↓クラステンプレートの利用↓
		//※継承している時点でテンプレートメソッドじゃないよ!
		//==================================================================

		/*!
			@struct	SBase
			@brief	継承元構造体(クラス)

			NOTE:	テンプレートクラスに自作クラスを渡せることの証明のため、
					動作は空。
		*/
		struct SBase{};

		/*!
			@class	CInt
			@brief	int型をテンプレートクラスを使って継承。
					※何の意味もない。ただ継承できるだけ。
		*/
		class CInt
			: public CTemplate<int>
		{
		public:
			/*!
				@brief	デフォルトコンストラクタ
			*/
			CInt() = default;

			/*!
				@brief	デフォルトデストラクタ
			*/
			~CInt() = default;
		private:
		};

		/*!
			@class	CInstance
			@brief	SBase型をテンプレートクラスを使って継承。
		*/
		class CInstance
			: public CTemplate<SBase>
		{
		public:
			/*!
				@brief	デフォルトコンストラクタ
			*/
			CInstance() = default;

			/*!
				@brief	デフォルトデストラクタ
			*/
			~CInstance() = default;

		private:

		};

#pragma endregion

#pragma region エイリアステンプレート

		//NOTE:	簡単に言うと"型に別名を持たせる"こと。
		//例えば、"int型"に別の型名を指定することが出来ます。
		//例)
		using INT = int;//C++
		//typedef int INT;//C言語
		//こうすることでコンパイル時"INT型" = "int型"として扱われます。

		//	近いものとして"enum型"かな
		
		//	"INT型"の別名宣言をコメントアウトすると書き宣言はエラーを吐きます。
		//なので正確には"INT型"≒"int型"です。
		INT g_INT;


		//	この型宣言を応用すると...
		using IntArray4 = int[4];	//int型の要素数4つの配列型

		//このように宣言を短縮ことが出来ます。
		IntArray4 g_IA4 = {0,1,2,3};
		
		//=======================================================
		//	応用
		//=======================================================
		//	一般的に使われているのは"Template"との併用です。
		template<typename P>
		using vector2 = std::vector<std::vector<P>>;//面倒な2重可変長配列が短くできました。


		//使用例↓
		vector2<int>g_v2;//使い方は通常どおり
#pragma endregion

	}
}