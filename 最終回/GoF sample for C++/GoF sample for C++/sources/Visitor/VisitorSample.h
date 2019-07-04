/*!
	@file	VisitorSample.h
	@date	2019/06/18
	@author	番場 宥輝
	@brief	Visitorパターンのサンプルコード

	NOTE:	Visitor ＝ Dispatch
*/
#pragma once

namespace GoF {
	namespace Visitor1 {

		/*!
			1.訪問する全てのクラスに対して、機能提供を行うVisitorクラス

			2.訪問を受け入れる各クラスのインターフェイスに訪問を受け入れるメソッドを定義

			<前提>
			"プレイヤー"、"敵"、"アイテム"はそれぞれ位置情報を持ち、加えて"キャラクター(プレイヤーと敵)"は範囲を持つとする。
			"プレイヤー"は範囲内に"敵"と"アイテム"があるか、"敵"は"プレイヤー"と"アイテム"があるかをそれぞれ別途関数を作る必要が出てきてしまう。
			そこで"範囲内にオブジェクトが存在するか"を機能(クラス)として分割すことでコード量を減らす。

			NOTE:	ファイル分けはしない(基本インライン)
					概念的には多重ディスパッチに近い(？)
		*/

#pragma region 基底クラス
		/*!
			@class	CObject
			@brief	ゲームオブジェクトの抽象クラス
		*/
		class CObject abstract
		{
		public:
			/*!
				@brief	コンストラクタ
			*/
			CObject() :pos({ 0,0,0 }) {};

			/*!
				@brief	仮想デストラクタ
			*/
			virtual~CObject() = default;

			/*!
				@struct	SFloat3
				@brief	float型3つの構造体
			*/
			struct SFloat3
			{
				/*!
					@var	x,y,z
					@brief	三次元位置情報
				*/
				float x, y, z;

				/*!
					@operator	==
					@brief		等価演算子の定義

					NOTE:		別にいらないけど、書き方覚えておくといいよ！
				*/
				inline bool operator ==(SFloat3 other) {
					return this->x == other.x&&this->y == other.y&&this->z == other.z;
				}
			}pos;
			/*!
				@struct	SFloat2
				@brief	float型3つの構造体
			*/
			struct SFloat2
			{
				/*!
					@var	x,y
					@brief	二次元位置情報
				*/
				float x, y;
			};


		private:

		};

		/*!
			@class	CCharacter
			@brief	キャラクターの基底クラス
		*/
		class CCharacter abstract
			:public CObject
		{
		public:
			/*!
				@brief	コンストラクタ
			*/
			CCharacter() :CObject() {};

			/*!
				@brief	仮想デストラクタ
			*/
			virtual~CCharacter() = default;

			/*!
				@fn		GetRange
				@brief	範囲の取得
			*/
			const SFloat3 GetRange() const { return m_Range; }

		protected:
			/*!
				@var	m_Range
				@brief	範囲
			*/
			SFloat3 m_Range;
		};


#pragma endregion

#pragma region オブジェクト

		/*!
			@class	CPlayer
			@brief	プレイヤークラス
			@detail	役割:訪問を受け入れる
		*/
		class CPlayer
			:public CCharacter
		{
		public:
			/*!
				@brief	コンストラクタ
			*/
			CPlayer() :CCharacter() {}

			/*!
				@brief	デストラクタ
			*/
			~CPlayer();

		private:

		};

		/*!
			@class	CEnemy
			@brief	エネミークラス
			@detail	役割:訪問を受け入れる
		*/
		class CEnemy
			:public CCharacter
		{
		public:
			/*!
				@brief	コンストラクタ
			*/
			CEnemy() :CCharacter() {}

			/*!
				@brief	デストラクタ
			*/
			~CEnemy() = default;

		private:

		};

		/*!
			@class	CItem
			@brief	アイテムクラス
			@detail	役割:訪問を受け入れる
		*/
		class CItem
			:public CObject
		{
		public:
			/*!
				@brief	コンストラクタ
			*/
			CItem() :CObject() {}

			/*!
				@brief	デストラクタ
			*/
			~CItem() = default;

		private:

		};

#pragma endregion

#pragma region Visitor

		/*!
			@class	RangeInObject
			@brief	範囲内にオブジェクトがあるか確認
			@detail	役割:Visitor
		*/
		class RangeInObject
		{
		public:
			/*!
				@brief	コンストラクタ
			*/
			RangeInObject() = default;

			/*!
				@brief	デストラクタ
			*/
			~RangeInObject() = default;

			/*!
				@fn			SetPosition
				@brief		検索位置の設定
				@param[in]	検索位置
			*/
			inline void SetPosition(CObject::SFloat3 pos) { m_Pos = pos; }

			/*!
				@fn			SetRange
				@brief		検索範囲の設定
				@param[in]	検索範囲
			*/
			inline void SetRande(CObject::SFloat3 range) { m_Range = range; }

			/*!
				@fn		VisitPlayer
				@brief	Playerの訪問

				NOTE:	今回のケースだと"Player"と"AbstractEnemy"はメンバが一緒なので
						正直、"VisitCharacter"でいいけど、突っ込んじゃダメ!
			*/
			void VisitPlayer(CPlayer*player) {
				//	訪問する際に細かく設定したい情報
				//	例えば...
				//	ステータスとか
			}

			/*!
				@fn		VisitEnemy
				@brief	AbstractEnemyの訪問

				NOTE:	今回のケースだと"Player"と"AbstractEnemy"はメンバが一緒なので
						正直、"VisitCharacter"でいいけど、突っ込んじゃダメ!
			*/
			void VisitEnemy(CEnemy*enemy) {
				//	訪問する際に細かく設定したい情報
				//	例えば...
				//	IDとか
			}

			/*!
				@fn		VisitItem
				@brief	Itemの訪問
			*/
			void VisitItem(CItem*item) {
				//	訪問する際に細かく設定したい情報
				//	例えば...
				//	アイテムの座標は三次元ではなく、二次元にコンバートとか
			}

			/*!
				@fn		GetResult
				@brief	判定結果の取得

				NOTE:	判定処理は適当
			*/
			const bool GetResult() {
				return m_Pos == m_Range;
			}

		private:
			/*!
				@var	m_Pos
				@brief	検索位置
			*/
			CObject::SFloat3 m_Pos;

			/*!
				@var	m_Range
				@brief	検索範囲
			*/
			CObject::SFloat3 m_Range;

		};

#pragma endregion
	}

	namespace Visitor {

		/*!
			@class	CPotision
			@brief	
		*/
		class CPosition
		{
		public:

		private:
				
		};
	}
}